#pragma once
#include <functional>
#include <map>

#include "../stdafx.h"
using namespace std::placeholders;
using namespace std;
class MsgDispatcher {
public:
	MsgDispatcher() {};
	~MsgDispatcher() {};
	bool dispatch(QString type,QString content,int client/*whose msg...*/)//type,pack,client
	{
		map<QString ,std::function<void(QString,int)>>::iterator it;
		for (it = m_funcs.find(type); it != m_funcs.end(); it++)
		{
			std::function<void(QString,int)> funcCall = it->second;
			funcCall(content,client);
			return true;
		}

		return false;
	}
	void registerfunc(QString type, std::function<void(QString,int)> func)
	{
		m_funcs.insert(std::pair<QString, std::function<void(QString,int)>>(type, func));
	}
private:
	map<QString,std::function<void(QString,int)>> m_funcs;





};