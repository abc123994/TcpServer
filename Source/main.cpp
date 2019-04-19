#include "stdafx.h"
#include "Core/Manager.h"
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	qDebug() << "initial";
	Manager mgr;



	app.exec();
}