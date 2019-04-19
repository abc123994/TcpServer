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
void Manager::HandleMsg(QString str)
{
	//handle msg here...
	qDebug() << "handle msg:" << str;
	
	MSG_rep msg;
	msg.replyToken = server->GetClient()->GetToken();

	//��H���B�z �i�H����dispatcher�h��
	if (str == "listall") {
		msg.message= m_dal->ListAll();
	}
	else
	{
		//query db
		msg.message = m_dal->TakeMsg(str);
	}

	

	//response
	QJsonDocument doc(msg.toJson());
	QString strJson(doc.toJson(QJsonDocument::Compact));
	server->ToClient(strJson);
}
#include "Manager.moc"