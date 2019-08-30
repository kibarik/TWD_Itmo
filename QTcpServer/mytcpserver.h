#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QTime>
#include "judgementmodes.h"
#include "middleware.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    void setMode(short mode);
    short getMode();

// !!!Сигнал вызывает слот, т. е. слот - функция, которая исполняется, а сигнал её вызывает!!!
public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
    void slotAdmonition(bool player); // 0 - красный, 1 - синий
    void slotWarning(bool player); // 0 - красный, 1 - синий

signals:
    void signalScoreUpdate(int judgeNum, int red, int blue); // Сигнал, вызываемый при изменении счёта судьями
    void signalDisqualification(bool player); // Сигнал, вызываемый при дисквалификации одного из игроков. 0 - красный, 1 - синий

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    std::vector <JudgementModes *> Judges; // Нужно для обработки различных режимов при нажатии на кнопки
    /*
     * Режимы работы
     * 0 - спарринг
     * 1 - туль
     * По умолчанию спарринг
    */
    short mode;
};

#endif // MYTCPSERVER_H
