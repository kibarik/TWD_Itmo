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

    //Соединяем QML характеристики с серверным API (read/write/notify)
    //Позволяет передавать/получать сигналы с QML кода в C++ структуру
    Q_PROPERTY(short QTimeElapsed       READ QTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(short QRoundTime         READ QRoundTime       WRITE setRoundTime         NOTIFY timeChanged)
    Q_PROPERTY(short QRedAdmonition     READ QRedAdmonition   WRITE setRedAdmonition     NOTIFY admonitionChanged)
    Q_PROPERTY(short QBlueAdmonition    READ QBlueAdmonition  WRITE setBlueAdmonition    NOTIFY admonitionChanged)
    Q_PROPERTY(short QRedWarning        READ QRedWarning      WRITE setRedWarning        NOTIFY warningChanged)
    Q_PROPERTY(short QBlueWarning       READ QBlueWarning     WRITE setBlueWarning       NOTIFY warningChanged)
    Q_PROPERTY(short QTulLevel          READ QTulLevel        WRITE setTulLevel          NOTIFY tulLevelChanged)
    Q_PROPERTY(bool  QTulLevelChanged   READ isTulLevelChanged WRITE changeTulLevel      NOTIFY tulLevelChanged)

public:
    explicit MyTcpServer(QObject *parent = nullptr); //явное наследование от родителя, обязательно для QML древа

    //геттеры (READ) для Q_PROPERTY.
    short QTimeElapsed()    {return timeElapsed;}
    short QRoundTime()      {return roundTime;}
    short QRedAdmonition()  {return redAdmonition;}
    short QBlueAdmonition() {return blueAdmonition;}
    short QRedWarning()     {return timeElapsed;}
    short QBlueWarning()    {return blueWarning;}
    short QTulLevel()       {return tulLevel;}
    bool  isTulLevelChanged() {return tulLevelChanged;}

    /* сеттеры вся суть ->
     * 1. испустить сигнал categoryChanged() с сообщением для логирования.
     * 2. Передать параметр из QML в C++ структуру.
    */
    void setRoundTime(const short& QRoundTime);
    void setRedAdmonition(const short& QRedAdmonition);
    void setBlueAdmonition(const short& QBlueAdmonition);
    void setRedWarning();
    void setBlueWarning();
    void setTulLevel();
    void changeTulLevel();

    enum Mode {SPARRING, CLASSICTUL, NEWTUL} mode;

    void setMode(Mode mode);
    Mode getMode();
    short getAdmonition(bool player); // 0 - красный, 1 - синий
    short getWarning(bool player); // 0 - красный, 1 - синий

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

    //Notify signals
    void timeChanged();
    void admonitionChanged(const QString& who);
    void warningChanged(const QString& who);

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
