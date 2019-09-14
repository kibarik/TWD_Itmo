#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <QObject>
#include <iostream>
#include "mytcpserver.h"

class TestObject : public QObject
{
    Q_OBJECT
public:
    explicit TestObject(QObject *parent = nullptr);
    void ConnectToServer(const MyTcpServer &server);

signals:
public slots:
    void PrintScore(int judgeNum, int red, int blue);
};

#endif // TESTOBJECT_H
