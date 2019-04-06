#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "category.h"

int main(int argc, char *argv[])
{

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	try { //тестирование системы на работспособность.
		engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	} catch (const std::string) {
		std::cerr<<"Catched ";
		//engine.load(QUrl(QStringLiteral("qrc:/Error.qml")));
	}

//----------------------------Objects----------------------------
	CategoryAPI *categoryAPI = new CategoryAPI();
	engine.rootContext()->setContextProperty("categoryAPI", categoryAPI);

//	//----------------------Debugger--------------------------------//

//    CategoryAPI* debug = new CategoryAPI;

//    QVector<Category> testcats = getCategories();
//	printCategories(testcats); // Этап тестирования для отображения категорий

//    for(const Category& category : testcats){
//        debug->setParticipants(category);
//    }

//---------------------------------------------------------
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
    }
