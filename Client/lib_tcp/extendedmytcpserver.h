#ifndef EXTENDEDMYTCPSERVER_H
#define EXTENDEDMYTCPSERVER_H

#include <QObject>
#include "mytcpserver.h"

/*
    Данный класс расширяет стандартный class MyTcpServer
    Здесь находятся функции и методы, для передачи данных из C++ в QML
*/
class ExtendedMyTcpServer : /*public QObject,*/ public MyTcpServer
{
    Q_OBJECT
    //Соединяем QML характеристики с серверным API (read/write/notify)
    //Позволяет передавать/получать сигналы с QML кода в C++ структуру
    Q_PROPERTY(int qRoundTimeElapsed  READ qRoundTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(int qPauseTimeElapsed  READ qPauseTimeElapsed     NOTIFY timeChanged)
    Q_PROPERTY(int qRoundTime         READ qRoundTime       WRITE setRoundTime         NOTIFY timeChanged)
    //Q_PROPERTY(short QPauseTime         READ QPauseTime       WRITE setPauseTime         NOTIFY timeChanged)
    Q_PROPERTY(int qRedAdmonition     READ qRedAdmonition   WRITE setRedAdmonition     NOTIFY admonitionChanged)
    Q_PROPERTY(int qBlueAdmonition    READ qBlueAdmonition  WRITE setBlueAdmonition    NOTIFY admonitionChanged)
    Q_PROPERTY(int qRedWarning        READ qRedWarning      WRITE setRedWarning        NOTIFY warningChanged)
    Q_PROPERTY(int qBlueWarning       READ qBlueWarning     WRITE setBlueWarning       NOTIFY warningChanged)

public:
    explicit ExtendedMyTcpServer(QObject *parent = nullptr); //явное наследование от родителя, обязательно для QML древа

    //геттеры (READ) для Q_PROPERTY.
    Q_INVOKABLE int qRoundTimeElapsed()    {return static_cast<int>(roundTimeElapsed);}
    Q_INVOKABLE int qPauseTimeElapsed()    {return static_cast<int>(pauseTimeElapsed);}
    Q_INVOKABLE int qRoundTime()           {return static_cast<int>(roundTime);}
    Q_INVOKABLE int qPauseTime()           {return static_cast<int>(pauseTime);}
    Q_INVOKABLE int qRedAdmonition()       {return static_cast<int>(redAdmonition);}
    Q_INVOKABLE int qBlueAdmonition()      {return static_cast<int>(blueAdmonition);}
    Q_INVOKABLE int qRedWarning()          {return static_cast<int>(redWarning);}
    Q_INVOKABLE int qBlueWarning()         {return static_cast<int>(blueWarning);}

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
};

#endif // EXTENDEDMYTCPSERVER_H
