#pragma once

class TCPServer;
class TCPSocket :
	public QTcpSocket
{
	Q_OBJECT
public:
	TCPSocket(QObject* parent);
	~TCPSocket();
	int m_num;
	
private:
	QByteArray data;;
	bool handling = false;
	int datalen = 0;
	QString m_token;
public slots:
	void OnReadyRead();
	void OnDisconnected();
public:
	void SetNum(int);
	int GetNum();
	QString GetToken();


};

