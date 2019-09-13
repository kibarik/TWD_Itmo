#include "testobject.h"

TestObject::TestObject(QObject *parent) : QObject(parent) {

}

void TestObject::PrintScore(int red, int blue) {
    std::cout << red << ':' << blue << std:: endl;
}

void TestObject::ConnectToServer(const JudgementModes &modes) {
    connect(&modes, &JudgementModes::signalScoreUpdate, this, &TestObject::PrintScore);
}
