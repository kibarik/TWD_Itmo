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

    ExtendedMyTcpServer *serverAPI = new ExtendedMyTcpServer();
    engine.rootContext()->setContextProperty("serverAPI", serverAPI);

    //----------------------Debugger--------------------------------//

/*    CategoryAPI* debug = new CategoryAPI;

    QVector<Category> testcats = getCategories();
    printCategories(testcats); // Этап тестирования для отображения категорий

    for(const Category& category : testcats){
       debug->setParticipants(category);
    }
*/

    //-------------TCP_server for remote controls
//    qDebug()<<"Start tcp server";
//    TestObject reference;
//    MyTcpServer server;
//    server.setMode(MyTcpServer::Mode::CLASSICTUL);
//    reference.ConnectToServer(server);
//    server.slotTimerStart();

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
    }
