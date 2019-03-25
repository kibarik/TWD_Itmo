#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "category.h"

int main(int argc, char *argv[])
{
	printCategories(getCategTemplate());

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	CategoryAPI *categoryAPI = new CategoryAPI();
	engine.rootContext()->setContextProperty("categoryAPI", categoryAPI);

	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
