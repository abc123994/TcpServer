#pragma once



#include "TCPSocket.h"
#include "Core/DAL.h"
class Manager;
class TcpServer :
	public QTcpServer
{
	Q_OBJECT
public:
	TcpServer(QObject* parent);
	~TcpServer();


	virtual void incomingConnection(qintptr handle);
public:

	TCPSocket* GetClient(int);
	void ToClient(QString content,int client);
	void DelClient(int);
	Manager* mgr;
private:
	QMap<int, QPair<TCPSocket*,QThread*>>m_client; //���h�ӫȺݮɥγo�ӥh���B�z





};
