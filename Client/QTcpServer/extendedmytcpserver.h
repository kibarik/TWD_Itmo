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
    Q_PROPERTY(int qPauseTime         READ qPauseTime       WRITE setPauseTime         NOTIFY timeChanged)
    Q_PROPERTY(QString qMinutesNow    READ qMinutesNow      NOTIFY timeChanged)
    Q_PROPERTY(QString qSecondsNow    READ qSecondsNow      NOTIFY timeChanged)

    Q_PROPERTY(int qRedAdmonition     READ qRedAdmonition   WRITE setRedAdmonition     NOTIFY admonitionChanged)
    Q_PROPERTY(int qBlueAdmonition    READ qBlueAdmonition  WRITE setBlueAdmonition    NOTIFY admonitionChanged)
    Q_PROPERTY(int qRedWarning        READ qRedWarning      WRITE setRedWarning        NOTIFY warningChanged)
    Q_PROPERTY(int qBlueWarning       READ qBlueWarning     WRITE setBlueWarning       NOTIFY warningChanged)
    Q_PROPERTY(int qRedScore          READ qRedScore    NOTIFY scoreChanged)
    Q_PROPERTY(int qBlueScore         READ qBlueScore   NOTIFY scoreChanged)
    Q_PROPERTY(int qRound             READ qRoundRead       WRITE setRound NOTIFY roundChanged)
    Q_PROPERTY(int qRoundCount        READ qRoundCountRead  WRITE setRoundCount NOTIFY roundChanged)

    Q_PROPERTY(int qJudge1r READ qJudge1r NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge1b READ qJudge1b NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge2r READ qJudge2r NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge2b READ qJudge2b NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge3r READ qJudge3r NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge3b READ qJudge3b NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge4r READ qJudge4r NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge4b READ qJudge4b NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge5r READ qJudge5r NOTIFY scoreChanged)
    Q_PROPERTY(int qJudge5b READ qJudge5b NOTIFY scoreChanged)

public:
    explicit ExtendedMyTcpServer(QObject *parent = nullptr); //явное наследование от родителя, обязательно для QML древа

    //Q_ENUM(Sportsman)
    //геттеры (READ) для Q_PROPERTY.
    int qRoundTimeElapsed()    {return static_cast<int>(roundTimeElapsed);}
    int qPauseTimeElapsed()    {return static_cast<int>(pauseTimeElapsed);}
    int qRoundTime()           {return static_cast<int>(roundTime);}
    int qPauseTime()           {return static_cast<int>(pauseTime);}
    int qRedAdmonition()       {return static_cast<int>(redAdmonition);}
    int qBlueAdmonition()      {return static_cast<int>(blueAdmonition);}
    int qRedWarning()          {return static_cast<int>(redWarning);}
    int qBlueWarning()         {return static_cast<int>(blueWarning);}
    int qRedScore()  {return static_cast<int>(getOverallScore(MyTcpServer::RED));}
    int qBlueScore() {return static_cast<int>(getOverallScore(MyTcpServer::BLUE));}
    int qRoundRead() {return this->round;}
    int qRoundCountRead()     {return this->roundCount;}
    QString qMinutesNow();
    QString qSecondsNow();

    int qJudge1r()  {return judge1r;}
    int qJudge1b()  {return judge1b;}
    int qJudge2r()  {return judge2r;}
    int qJudge2b()  {return judge2b;}
    int qJudge3r()  {return judge3r;}
    int qJudge3b()  {return judge3b;}
    int qJudge4r()  {return judge4r;}
    int qJudge4b()  {return judge4b;}
    int qJudge5r()  {return judge5r;}
    int qJudge5b()  {return judge5b;}

    /*сеттеры вся суть ->
     * 1. испустить сигнал categoryChanged() с сообщением для логирования.
     * 2. Передать параметр из QML в C++ структуру.
    */
    void setRoundTime(const int& qRoundTime);
    void setPauseTime(const int& qPauseTime);
    void setRedAdmonition(const int& qRedAdmonition);
    void setBlueAdmonition(const int& qBlueAdmonition);
    void setRedWarning(const int& qBlueWarning);
    void setBlueWarning(const int& qBlueWarning);
    void setRound(const int& qRound);
    void setRoundCount(const int& qRoundCount);

public slots:
    void plusSeconds (int seconds = 30);


signals:
    //Notify signals
    void timeChanged();
    void admonitionChanged();
    void warningChanged();
    void scoreChanged();
    void roundChanged();
    void extraRoundSetted(); //Дополнительный раунд при ничье в основном счете
    void clearPointRoundSetted(); //Раунд до первого точного попадания
    void doctorSignal();

protected:
    int round = 1;
    int roundCount = 1;

    int judge1r=0;    int judge1b=0;
    int judge2r=0;    int judge2b=0;
    int judge3r=0;    int judge3b=0;
    int judge4r=0;    int judge4b=0;
    int judge5r=0;    int judge5b=0;
};

#endif // EXTENDEDMYTCPSERVER_H
