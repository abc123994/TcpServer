#pragma once

class TcpServer;
class TCPSocket :
	public QTcpSocket
{
	Q_OBJECT
public:
	TCPSocket();
	~TCPSocket();
	int m_num;
	void SetServer(TcpServer*);
private:
	QByteArray data;;
	bool handling = false;
	int datalen = 0;
	QThread* m_thread;
	
public slots:
	void OnReadyRead();
	void OnDisconnected();

public:
	void SetNum(int);
	int GetNum();
	TcpServer* m_svr;


};

