#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "category.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    CategoryAPI *categoryAPI = new CategoryAPI();
    engine.rootContext()->setContextProperty("categoryAPI", categoryAPI);

    if (engine.rootObjects().isEmpty())
        return -1;
//------------------------------------------------------//

    CategoryAPI* debug = new CategoryAPI;

    QVector<Category> testcats = getCategories();
    printCategories(testcats); // Этап тестирования для отображения категорий

    for(const Category& category : testcats){
        debug->setParticipants(category);
    }

//---------------------------------------------------------
    return app.exec();
    }
