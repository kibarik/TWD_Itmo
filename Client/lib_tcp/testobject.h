#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include <QObject>
#include <iostream>
#include "judgementmodes.h"

class TestObject : public QObject
{
    Q_OBJECT
public:
    explicit TestObject(QObject *parent = nullptr);
    void ConnectToServer(const JudgementModes &modes);

signals:
public slots:
    void PrintScore(int red, int blue);
};

#endif // TESTOBJECT_H
