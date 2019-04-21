#include "stdafx.h"
//和客端的協議
struct MSG_rep {
	QString message;
	QString content;
	QJsonObject toJson() const {
	
		return { {"msg", message},{"content",content} };
	}
};

struct TypeA
{
	int A_number;

	QJsonObject toJson() const {
		
		return { {"A_number", A_number} };
	}

};

struct TypeB
{
	QString B_String;
	QJsonObject toJson() const {

		return { {"B_String", B_String} };
	}

};