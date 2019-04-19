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
	QMap<int, TCPSocket*>m_client; //有多個客端時用這個去做處理
	TCPSocket* GetClient();
	void ToClient(QString);
	void DelClient(int);
	Manager* mgr;
private:
	TCPSocket* s;





};
