#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "lib/category.h"
//#include "lib/fileio.h"
#include "lib/xmlio.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

//-------------регистрируем собственные QML типы данных-----------------------//
	//qmlRegisterType<FileIO, 1>("FileIO", 1, 0, "FileIO");
	//qmlRegisterType<FileIO, 1>("XmlIO", 1, 0, "XmlIO");
	qmlRegisterType<Category, 1>("Category", 1, 0, "Category");



	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();

}
