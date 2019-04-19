#include "stdafx.h"
//和客端的協議
struct MSG_rep {
	QString replyToken;
	QString message;
	QJsonObject toJson() const {
		return { {"replyToken", replyToken}, {"msg", message} };
	}
};