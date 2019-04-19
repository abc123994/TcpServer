#pragma once


class DAL :
	public QObject
{
	
public:
	DAL(QObject* parent=0);
	~DAL();
	QMultiMap<QString, QString>m_handle_msgs;
	QString TakeMsg(QString);
	void OnMsgAdd(QString request, QString respond);
	QString ListAll();
private:
	QSqlDatabase m_sql;
	QSqlQuery* m_query;
	
	
	void Init( QMultiMap<QString, QString>& message);
	
};

