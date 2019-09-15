#ifndef EXTENDEDMYTCPSERVER_H
#define EXTENDEDMYTCPSERVER_H

#include <QObject>
#include "mytcpserver.h"

/*
    Данный класс расширяет стандартный class MyTcpServer
    Здесь находятся функции и методы, для передачи данных из C++ в QML
*/
class ExtendedMyTcpServer : public QObject
{
    Q_OBJECT
    //Соединяем QML характеристики с серверным API (read/write/notify)
    //Позволяет передавать/получать сигналы с QML кода в C++ структуру
    Q_PROPERTY(short QRoundTimeElapsed  READ QRoundTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(short QPauseTimeElapsed  READ QPauseTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(short QRoundTime         READ QRoundTime       WRITE setRoundTime         NOTIFY timeChanged)
    Q_PROPERTY(short QPauseTime         READ QPauseTime       WRITE setPauseTime         NOTIFY timeChanged)
    Q_PROPERTY(short QRedAdmonition     READ QRedAdmonition   WRITE setRedAdmonition     NOTIFY admonitionChanged)
    Q_PROPERTY(short QBlueAdmonition    READ QBlueAdmonition  WRITE setBlueAdmonition    NOTIFY admonitionChanged)
    Q_PROPERTY(short QRedWarning        READ QRedWarning      WRITE setRedWarning        NOTIFY warningChanged)
    Q_PROPERTY(short QBlueWarning       READ QBlueWarning     WRITE setBlueWarning       NOTIFY warningChanged)
    Q_PROPERTY(MyTcpServer *qServer     READ qServer)
public:
    explicit ExtendedMyTcpServer(QObject *parent = nullptr); //явное наследование от родителя, обязательно для QML древа

    //геттеры (READ) для Q_PROPERTY.
    short QRoundTimeElapsed()    {return this->server->roundTimeElapsed;}
    short QPauseTimeElapsed()    {return this->server->pauseTimeElapsed;}
    short QRoundTime()           {return this->server->roundTime;}
    short QPauseTime()           {return this->server->pauseTime;}
    short QRedAdmonition()       {return this->server->redAdmonition;}
    short QBlueAdmonition()      {return this->server->blueAdmonition;}
    short QRedWarning()          {return this->server->redWarning;}
    short QBlueWarning()         {return this->server->blueWarning;}
    MyTcpServer *qServer()       {return this->server;}

    /*сеттеры вся суть ->
     * 1. испустить сигнал categoryChanged() с сообщением для логирования.
     * 2. Передать параметр из QML в C++ структуру.
    */

    void setRoundTime(const short& QRoundTime);
    void setPauseTime(const short& QPauseTime);
    void setRedAdmonition(const short& QRedAdmonition);
    void setBlueAdmonition(const short& QBlueAdmonition);
    void setRedWarning(const short& QBlueWarning);
    void setBlueWarning(const short& QBlueWarning);

public slots:


signals:
    //Notify signals
    void timeChanged();
    void admonitionChanged();
    void warningChanged();
private:
    MyTcpServer *server;
};

#endif // EXTENDEDMYTCPSERVER_H
