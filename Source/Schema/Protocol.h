#include "stdafx.h"
//�M�Ⱥݪ���ĳ
struct MSG_rep {
	QString replyToken;
	QString message;
	QJsonObject toJson() const {
		return { {"replyToken", replyToken}, {"msg", message} };
	}
};