#include "stdafx.h"
//�M�Ⱥݪ���ĳ
struct MSG_rep {
	QString message;
	QJsonObject toJson() const {
		return {  {"msg", message} };
	}
};