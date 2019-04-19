#include "stdafx.h"
#include "DAL.h"



DAL::DAL(QObject* p)
{
	m_sql= QSqlDatabase::addDatabase("QODBC");
	QString dns = "DRIVER={SQL Server};DataBase=Msg;Server=Localhost;Trusted_Connection=yes;";
	m_sql.setDatabaseName(dns);

	if (m_sql.open())
	{
		m_query = new QSqlQuery(m_sql);
		qDebug() << "open db ok\n\n";

		Init(m_handle_msgs);
		
	}
	else
	{
		qDebug() << QSqlDatabase::drivers();
		qDebug() << m_sql.lastError();
	}
}


DAL::~DAL()
{
}

void DAL::Init(QMultiMap<QString,QString>& message)
{
	m_query->clear();
	m_query->prepare("select  * from [Msg].[dbo].[MessageLink]");
	m_query->exec();
	while (m_query->next())
	{
		message.insert(m_query->value(0).toString(), m_query->value(1).toString());
	}

}
void DAL::OnMsgAdd(QString request, QString Message)
{
	m_handle_msgs.insert(request, Message);
	qDebug()<< "Add:" + request + "\t" + Message;
	m_query->clear();
	m_query->prepare("insert into  [Msg].[dbo].[MessageLink] values(:request,:Message)");
	m_query->bindValue(":request", request);
	m_query->bindValue(":Message", Message);
	if (!m_query->exec())
	{
		qDebug() << m_query->lastError();
	}
}
QString DAL::TakeMsg(QString msg)
{

	QMultiMap<QString, QString>::iterator i = m_handle_msgs.find(msg);
	while (i != m_handle_msgs.end() && i.key() == msg) {
		return i.value() ;
	}
	
	return QString::fromLocal8Bit("!!!not in db!!!\n輸入:listall查看信息列表");
	
}
QString DAL::ListAll()
{
	QString str;
	QMultiMap<QString, QString>::iterator i;
	for ( i = m_handle_msgs.begin(); i != m_handle_msgs.end(); i++)
	{
		str += "request: " + i.key()+"response: "+i.value()+"\n";
	}
	return str;
}