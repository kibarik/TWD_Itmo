#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "category.h"
#include "lib_tcp/extendedmytcpserver.h"
#include "lib_tcp/testobject.h"

int main(int argc, char *argv[])
{

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);


    qmlRegisterType<ExtendedMyTcpServer, 1>("ServerAPI", 1, 0, "ServerAPI");
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//----------------------------C++ Objects----------------------------
    //Позволяет только выводить данные из categoryAPI из category.h
    CategoryAPI *categoryAPI = new CategoryAPI();
	engine.rootContext()->setContextProperty("categoryAPI", categoryAPI);

//    ExtendedMyTcpServer *serverAPI = new ExtendedMyTcpServer();
//    engine.rootContext()->setContextProperty("serverAPI", serverAPI);
    //engine.

    //Регистрируем полноценный объект QML для ввода/вывода данных из C++ в QML
    //----------------------Debugger--------------------------------//

/*    CategoryAPI* debug = new CategoryAPI;

    QVector<Category> testcats = getCategories();
    printCategories(testcats); // Этап тестирования для отображения категорий

    for(const Category& category : testcats){
       debug->setParticipants(category);
    }
*/

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
    }
