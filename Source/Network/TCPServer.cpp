// TCPServer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "TCPServer.h"
#include "Core/Manager.h"


TcpServer::TcpServer(QObject* parent)
{
	mgr = qobject_cast<Manager*>(parent);


	qDebug("server on listen 1337 port");

	if (!listen(QHostAddress::LocalHost, 1337))
	{
		qDebug() << "Server could not start";
	}
	else
	{
	

		qDebug() << "Server started!";
	}
}


TcpServer::~TcpServer()
{
}


void TcpServer::incomingConnection(qintptr handle)
{
	qDebug() << "client connected..";
	// need to grab the socket
	TCPSocket* s = new TCPSocket();
	s->SetNum(handle);
	qDebug() << handle;
	s->setSocketDescriptor(handle);
	m_client.insert(handle, s);
	s->SetServer(this);
	QThread* socket_thread = new QThread(this);
	this->moveToThread(socket_thread);

	socket_thread->start();
	connect(s, SIGNAL(readyRead()), s, SLOT(OnReadyRead()), Qt::DirectConnection);
	connect(s, SIGNAL(disconnected()), s, SLOT(OnDisconnected()));
}
void TcpServer::ToClient(QString Content,int client)
{

	QByteArray byteArray;
	QDataStream stream(&byteArray, QIODevice::WriteOnly);
	int length = Content.toUtf8().size();
	stream << length;
	auto s = m_client[client];
	s->write(byteArray);
	s->write(Content.toUtf8());
	s->flush();
}
void TcpServer::DelClient(int num)
{
	m_client.value(num)->deleteLater();
	m_client.remove(num);
}
TCPSocket* TcpServer::GetClient(int client)
{
	return m_client[client];
}
#include "TcpServer.moc"