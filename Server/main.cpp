#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "lib/category.h"
//#include "lib/fileio.h"
#include "lib/xmlio.h"
#include "lib/competition.h"
#include  "lib/dbConnection.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

//-------------регистрируем собственные QML типы данных-----------------------//
	//qmlRegisterType<FileIO, 1>("FileIO", 1, 0, "FileIO");
	//qmlRegisterType<FileIO, 1>("XmlIO", 1, 0, "XmlIO");
	qmlRegisterType<Category, 1>("Category", 1, 0, "Category");
	qmlRegisterType<Competition, 1>("Competition", 1, 0, "Competition");

//	try {
//		DbConnection testDb();
//	} catch (QString er){
//		qDebug() << er;
//	}

    TestObject reference;
    MyTcpServer server;
    reference.ConnectToServer(server.modes);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();

}
