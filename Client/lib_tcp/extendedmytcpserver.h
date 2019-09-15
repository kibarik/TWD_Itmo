#ifndef EXTENDEDMYTCPSERVER_H
#define EXTENDEDMYTCPSERVER_H

#include <QObject>
#include "mytcpserver.h"

/*
    Данный класс расширяет стандартный class MyTcpServer
    Здесь находятся функции и методы, для передачи данных из C++ в QML
*/
<<<<<<< HEAD
class ExtendedMyTcpServer : public QObject
=======
class ExtendedMyTcpServer : /*public QObject,*/ public MyTcpServer
>>>>>>> QTdevelop
{
    Q_OBJECT
    //Соединяем QML характеристики с серверным API (read/write/notify)
    //Позволяет передавать/получать сигналы с QML кода в C++ структуру
<<<<<<< HEAD
    Q_PROPERTY(short QRoundTimeElapsed  READ QRoundTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(short QPauseTimeElapsed  READ QPauseTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(short QRoundTime         READ QRoundTime       WRITE setRoundTime         NOTIFY timeChanged)
    Q_PROPERTY(short QPauseTime         READ QPauseTime       WRITE setPauseTime         NOTIFY timeChanged)
    Q_PROPERTY(short QRedAdmonition     READ QRedAdmonition   WRITE setRedAdmonition     NOTIFY admonitionChanged)
    Q_PROPERTY(short QBlueAdmonition    READ QBlueAdmonition  WRITE setBlueAdmonition    NOTIFY admonitionChanged)
    Q_PROPERTY(short QRedWarning        READ QRedWarning      WRITE setRedWarning        NOTIFY warningChanged)
    Q_PROPERTY(short QBlueWarning       READ QBlueWarning     WRITE setBlueWarning       NOTIFY warningChanged)
    Q_PROPERTY(MyTcpServer *qServer     READ qServer)
=======
    Q_PROPERTY(int qRoundTimeElapsed  READ qRoundTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(int qPauseTimeElapsed  READ qPauseTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(int qRoundTime         READ qRoundTime       WRITE setRoundTime         NOTIFY timeChanged)
    //Q_PROPERTY(short QPauseTime         READ QPauseTime       WRITE setPauseTime         NOTIFY timeChanged)
    Q_PROPERTY(int qRedAdmonition     READ qRedAdmonition   WRITE setRedAdmonition     NOTIFY admonitionChanged)
    Q_PROPERTY(int qBlueAdmonition    READ qBlueAdmonition  WRITE setBlueAdmonition    NOTIFY admonitionChanged)
    Q_PROPERTY(int qRedWarning        READ qRedWarning      WRITE setRedWarning        NOTIFY warningChanged)
    Q_PROPERTY(int qBlueWarning       READ qBlueWarning     WRITE setBlueWarning       NOTIFY warningChanged)

>>>>>>> QTdevelop
public:
    explicit ExtendedMyTcpServer(QObject *parent = nullptr); //явное наследование от родителя, обязательно для QML древа

    //геттеры (READ) для Q_PROPERTY.
<<<<<<< HEAD
    short QRoundTimeElapsed()    {return this->server->roundTimeElapsed;}
    short QPauseTimeElapsed()    {return this->server->pauseTimeElapsed;}
    short QRoundTime()           {return this->server->roundTime;}
    short QPauseTime()           {return this->server->pauseTime;}
    short QRedAdmonition()       {return this->server->redAdmonition;}
    short QBlueAdmonition()      {return this->server->blueAdmonition;}
    short QRedWarning()          {return this->server->redWarning;}
    short QBlueWarning()         {return this->server->blueWarning;}
    MyTcpServer *qServer()       {return this->server;}
=======
    Q_INVOKABLE int qRoundTimeElapsed()         {return static_cast<int>(roundTimeElapsed);}
    Q_INVOKABLE int qPauseTimeElapsed()    {return static_cast<int>(pauseTimeElapsed);}
    Q_INVOKABLE int qRoundTime()           {return static_cast<int>(roundTime);}
    Q_INVOKABLE int qPauseTime()           {return static_cast<int>(pauseTime);}
    Q_INVOKABLE int qRedAdmonition()       {return static_cast<int>(redAdmonition);}
    Q_INVOKABLE int qBlueAdmonition()      {return static_cast<int>(blueAdmonition);}
    Q_INVOKABLE int qRedWarning()          {return static_cast<int>(redWarning);}
    Q_INVOKABLE int qBlueWarning()         {return static_cast<int>(blueWarning);}
>>>>>>> QTdevelop

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
