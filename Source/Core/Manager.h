#pragma once

#include "Schema/Protocol.h"
#include "Core/DAL.h"
#include "Network/TCPServer.h"
class Manager :
	public QObject
{
	Q_OBJECT
public:
	Manager(QObject* parent=0);
	~Manager();
	void HandleMsg(QString);
	TcpServer* server;
	DAL* m_dal;
private:
	

};

