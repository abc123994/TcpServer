#pragma once

#include "Schema/Protocol.h"
#include "Core/DAL.h"
#include "Network/TCPServer.h"
#include "Network/MsgDispatcher.h"
class Manager :
	public QObject
{
	Q_OBJECT
public:
	Manager(QObject* parent=0);
	~Manager();
	void HandleMsg(QString,QString,int);
	TcpServer* server;
	DAL* m_dal;
private:
	MsgDispatcher* dispatcher;
	void OnHandleTypeA(QString,int);
	void OnHandleTypeB(QString,int);
	

};

