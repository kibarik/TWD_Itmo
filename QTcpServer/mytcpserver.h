#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QTime>
#include <QBasicTimer>
#include <QTimerEvent>
#include "judgementmodes.h"
#include "middleware.h"

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    enum Mode {SPARRING, CLASSICTUL, NEWTUL_1, NEWTUL_2, NEWTUL_3} mode;
    const int roundTimerDelay = 1000;

    explicit MyTcpServer(QObject *parent = nullptr);
    void setMode(Mode mode);
    Mode getMode();
    short getAdmonition(bool player); // 0 - красный, 1 - синий
    short getWarning(bool player); // 0 - красный, 1 - синий
    int getOverallScore(bool player); // 0 - красный, 1 - синий


// !!!Сигнал вызывает слот, т. е. слот - функция, которая исполняется, а сигнал её вызывает!!!
public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

    void slotAdmonition(bool player); // 0 - красный, 1 - синий (Чуй)
    void slotWarning(bool player); // 0 - красный, 1 - синий (Гамжун)
    void slotCancelAdmonition(bool player); // 0 - красный, 1 - синий (Чуй)
    void slotCancelWarning(bool player); // 0 - красный, 1 - синий (Гамжун)
    void slotChangeNewTulLevel(short level);
    void slotReset();

    void slotTimerStart();
    void slotTimerPause(short time = 0); // time - время паузы
    void slotTimerStop();

signals:
    void signalScoreUpdate(int judgeNum, int red, int blue); // Сигнал, вызываемый при изменении счёта судьями
    void signalDisqualification(bool player); // Сигнал, вызываемый при дисквалификации одного из игроков. 0 - красный, 1 - синий
    void signalTimeOver(); // Время таймера вышло
    void signalAdmonition(short redAdmonition, short blueAdmonition); // Вызывается при получении Чуя (замечания)
    void signalWarning(short redWarning, short blueWarning); // Вызывается при получении Гамжуна (предупреждения)
    void signalTimerEvent(short timeElapsed); // Вызывается при каждом срабатывании таймера
    void signalJudgeNumError(ulong judgeNum);

protected:
    void timerEvent(QTimerEvent *event);
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    QBasicTimer mainTimer;
    QBasicTimer pauseTimer;
    std::vector <JudgementModes *> Judges; // Нужно для обработки различных режимов при нажатии на кнопки
    short roundTimeElapsed; // Время, прошедшее с начала запуска таймера в секундах
    short pauseTimeElapsed; // Для хранения времени медицинского таймера
    short roundTime; // Время, которое длится один раунд
    short pauseTime; // Время, которое длится пауза
    short redAdmonition = 0, blueAdmonition = 0, redWarning = 0, blueWarning = 0;
};

#endif // MYTCPSERVER_H
