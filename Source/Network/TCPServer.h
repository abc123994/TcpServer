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
	QMap<int, TCPSocket*>m_client; //���h�ӫȺݮɥγo�ӥh���B�z
	TCPSocket* GetClient();
	void ToClient(QString);
	void DelClient(int);
	Manager* mgr;
private:
	TCPSocket* s;





};
