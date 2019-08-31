#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QBasicTimer>
#include <QTimerEvent>
#include "judgementmodes.h"
#include "middleware.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    enum Mode {SPARRING, CLASSICTUL, NEWTUL} mode;
    explicit MyTcpServer(QObject *parent = nullptr);
    void setMode(Mode mode);
    Mode getMode();

// !!!Сигнал вызывает слот, т. е. слот - функция, которая исполняется, а сигнал её вызывает!!!
public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

    void slotAdmonition(bool player); // 0 - красный, 1 - синий
    void slotWarning(bool player); // 0 - красный, 1 - синий
    void slotCancelAdmonition(bool player); // 0 - красный, 1 - синий
    void slotCancelWarning(bool player); // 0 - красный, 1 - синий
    void slotChangeTulLevel(short level) {this->tulLevel = level; tulLevelChanged = true;}

    void slotReset();
    void slotTimerStart(int delay = 1000);
    void slotTimerStop();

signals:
    void signalScoreUpdate(int judgeNum, int red, int blue); // Сигнал, вызываемый при изменении счёта судьями
    void signalDisqualification(bool player); // Сигнал, вызываемый при дисквалификации одного из игроков. 0 - красный, 1 - синий
    void signalTimeOver(); // Время таймера вышло

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    QBasicTimer timer;
    void timerEvent(QTimerEvent *event);
    std::vector <JudgementModes *> Judges; // Нужно для обработки различных режимов при нажатии на кнопки
    short timeElapsed; // Время, прошедшее с начала запуска таймера в секундах
    short roundTime; // Время, которое длится один раунд
    short redAdmonition = 0, blueAdmonition = 0, redWarning = 0, blueWarning = 0;
    short tulLevel;
    bool tulLevelChanged = false;
};

#endif // MYTCPSERVER_H
