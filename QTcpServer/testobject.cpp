#include "testobject.h"

TestObject::TestObject(QObject *parent) : QObject(parent) {

}

void TestObject::PrintScore(int judgeNum, int red, int blue) {
    std::cout << "Judge" << judgeNum << "  " << red << ':' << blue << std:: endl;
}

void TestObject::ConnectToServer(const MyTcpServer &modes) {
    connect(&modes, &MyTcpServer::signalScoreUpdate, this, &TestObject::PrintScore);
}
