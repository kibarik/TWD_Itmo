#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include "judgementmodes.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    void setMode(short mode);
    short getMode();
    JudgementModes modes; // Нужно для обработки различных режимов при нажатии на кнопки

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    /*
     * Режимы работы
     * 0 - спарринг
     * 1 - туль
     * По умолчанию спарринг
    */
    short mode;
};

#endif // MYTCPSERVER_H
