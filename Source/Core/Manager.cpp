#include "stdafx.h"
#include "Manager.h"

Manager::Manager(QObject* p)
{
	server = new TcpServer(this);
	m_dal = new DAL(this);

}


Manager::~Manager()
{
}
void Manager::HandleMsg(QString str,int client)
{
	//handle msg here...
	qDebug() << "handle msg:" << str;
	//test response
	
	MSG_rep msg;
	
	//對信息處理 可以有個dispatcher去做
	//if (str == "listall") {
	//	msg.message= m_dal->ListAll();
	//}
	//else
	//{
	//	//query db
	//	msg.message = m_dal->TakeMsg(str);
	//}

	msg.message = "server ack... msg";

	//response
	QJsonDocument doc(msg.toJson());
	QString strJson(doc.toJson(QJsonDocument::Compact));
	server->ToClient(strJson,client);
}
#include "Manager.moc"