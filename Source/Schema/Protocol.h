#include "stdafx.h"
//和客端的協議
struct MSG_rep {
	QString message;
	QJsonObject toJson() const {
		return {  {"msg", message} };
	}
};