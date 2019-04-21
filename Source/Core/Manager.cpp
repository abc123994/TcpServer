#include "stdafx.h"
#include "Manager.h"

Manager::Manager(QObject* p)
{
	server = new TcpServer(this);
	m_dal = new DAL(this);
	dispatcher = new MsgDispatcher();
	
	dispatcher->registerfunc("TypeA", bind(&Manager::OnHandleTypeA, this, _1,_2));
	dispatcher->registerfunc("TypeB", bind(&Manager::OnHandleTypeB, this, _1,_2));

}


Manager::~Manager()
{
}
void Manager::HandleMsg(QString type,QString Content,int client)
{
	//handle msg here...
	qDebug() << "handle msg:" << type;
	//對信息處理 有個dispatcher去做
	if (dispatcher->dispatch(type, Content, client))
	{
		//
	}
	else
	{
		//here the message is not valid
		qDebug() << "this message is not valid:\t" << type;
	};

}
void Manager::OnHandleTypeA(QString Content,int client)
{
	qDebug() << "on handle type a";
	// parse json and dosomething
	QJsonDocument doc= QJsonDocument::fromJson(Content.toUtf8());
	QJsonObject obj = doc.object();
	qDebug() << "get:\t" << obj.value("A_number").toInt();

	//response
	MSG_rep msg;
	msg.message = QString::fromLocal8Bit("處理信息A");
	msg.content = "server ack..";
	QJsonDocument reply_doc (msg.toJson());
	QString strJson(reply_doc.toJson(QJsonDocument::Compact));
	server->ToClient(strJson,client);
}
void Manager::OnHandleTypeB(QString Content,int client)
{
	qDebug() << "on handle type b";
	// parse json and dosomething
	QJsonDocument doc = QJsonDocument::fromJson(Content.toUtf8());
	QJsonObject obj = doc.object();
	qDebug() << "get:\t" << obj.value("B_String").toString();
	//dosomething
	MSG_rep msg;
	msg.message = QString::fromLocal8Bit("處理信息B");
	msg.content = "server ack..";
	QJsonDocument reply_doc(msg.toJson());
	QString strJson(reply_doc.toJson(QJsonDocument::Compact));
	server->ToClient(strJson, client);
}
#include "Manager.moc"