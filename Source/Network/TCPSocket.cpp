#include "stdafx.h"
#include "TCPSocket.h"
#include "TCPServer.h"
#include "Core/Manager.h"
//

TCPSocket::TCPSocket(QObject* parent)
{
	this->setParent(parent);
}


TCPSocket::~TCPSocket()
{
}
void TCPSocket::SetNum(int num)
{
	m_num = num;
}
int TCPSocket::GetNum()
{
	return m_num;
}
void TCPSocket::OnReadyRead()
{

	this->data+= this->readAll();
	while (this->data.size() > 0) {
		
		int headerlen = 4;
	
		if (!handling) {
			if (data.size() > headerlen) {
				handling = true;
				QByteArray array2;
				array2.reserve(4);
				array2[0] = data[3];
				array2[1] = data[2];
				array2[2] = data[1];
				array2[3] = data[0];
			
				memcpy(&datalen, array2, sizeof(int));
				qDebug() << "msg byte len" << datalen;
		
			}
			
			if (datalen <= (this->data.size() - headerlen))
			{
				qDebug() << "on complete msg...";
				data.remove(0, 4);
				QByteArray ary;
				for (int i = 0; i < datalen; i++)
				{
					ary += data.at(i);

				}
				QTextCodec *tc = QTextCodec::codecForName("UTF8");
				
				
				QJsonDocument d = QJsonDocument::fromJson(tc->toUnicode(ary).toUtf8());
				QJsonObject sett2 = d.object();
				
				QString text = sett2.value(QString("msg")).toString();
				this->m_token =sett2.value(QString("replyToken")).toString(); ;
				qDebug() << text << "\t" << sett2.keys();
				TcpServer* ptr = qobject_cast<TcpServer*>(this->parent());
			
				ptr->mgr->HandleMsg(text.toUtf8());
				this->data.remove(0, datalen);
				
				handling = false;
			}
			else {
				//只有收到title 數字
				handling = false;
				break;
			}

		}

		qDebug() << "IDLE\t" << data<<data.size()<<"\t"<<this->data.size();
		//
		handling = false;
	}

	
}
void TCPSocket::OnDisconnected() {
	qDebug() << m_num << "\t disconnected";
	TcpServer* msvr = qobject_cast<TcpServer*>(this->parent());
	qDebug() << msvr;
}
QString TCPSocket::GetToken()
{
	return m_token;
}
#include "TCPSocket.moc"