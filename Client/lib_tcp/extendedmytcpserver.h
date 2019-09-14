#ifndef EXTENDEDMYTCPSERVER_H
#define EXTENDEDMYTCPSERVER_H

#include <QObject>
#include "mytcpserver.h"

/*
    Данный класс расширяет стандартный MyTcpServer
    В нем находятся функции и методы, для передачи данных из C++ в QML
*/
class extendedMyTcpServer : public MyTcpServer
{

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
    extendedMyTcpServer();

    //геттеры (READ) для Q_PROPERTY.
    short QTimeElapsed()    {return timeElapsed;}
    short QRoundTime()      {return roundTime;}
    short QRedAdmonition()  {return redAdmonition;}
    short QBlueAdmonition() {return blueAdmonition;}
    short QRedWarning()     {return timeElapsed;}
    short QBlueWarning()    {return blueWarning;}
    short QTulLevel()       {return tulLevel;}
    bool  isTulLevelChanged() {return tulLevelChanged;}

signals:
    //Notify signals
    void timeChanged();
    void admonitionChanged(const QString& who);
    void warningChanged(const QString& who);
};

#endif // EXTENDEDMYTCPSERVER_H
