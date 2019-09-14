#include <QCoreApplication>
#include <iostream>
#include "mytcpserver.h"
#include "testobject.h"
//#include <QObject>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestObject reference;
    MyTcpServer server;
    server.setMode(MyTcpServer::Mode::NEWTUL_2);
    reference.ConnectToServer(server);
    server.slotTimerStart();
    return a.exec();
}
