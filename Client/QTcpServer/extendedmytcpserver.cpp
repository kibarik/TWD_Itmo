#include "extendedmytcpserver.h"

ExtendedMyTcpServer::ExtendedMyTcpServer(QObject *parent) : MyTcpServer (parent)
{

}

//----------------сигналы notify, вызываются при изменении свойств из QML
//---------------------сеттеры для Q_PROPERTY-------------
/*сеттеры вся суть ->
 * 1. испустить сигнал emit signal()... с сообщением для логирования.
 * 2. Передать параметр из QML в C++ структуру.
*/
void ExtendedMyTcpServer::setRoundTime(const int &QRoundTime){
    roundTime = static_cast<short>(QRoundTime);
    emit this->timeChanged();
}

void ExtendedMyTcpServer::setRedAdmonition(const int &QRedAdmonition){
    redAdmonition = static_cast<short>(QRedAdmonition);
    emit admonitionChanged();
}

void ExtendedMyTcpServer::setBlueAdmonition(const int &QBlueAdmonition){
    blueAdmonition = static_cast<short>(QBlueAdmonition);
    emit this->admonitionChanged();
}

void ExtendedMyTcpServer::setRedWarning(const int &QRedWarning){
    redWarning = static_cast<short>(QRedWarning);
    emit this->warningChanged();
}

void ExtendedMyTcpServer::setBlueWarning(const int &QBlueWarning){
    blueWarning = static_cast<short>(QBlueWarning);
    emit this->warningChanged();
}
void ExtendedMyTcpServer::setPauseTime(const int &qPauseTime) {
    pauseTime = static_cast<short>(qPauseTime);
    emit this->timeChanged();
}

void ExtendedMyTcpServer::setRound(const int& qRound){
    this->round = qRound>2 ? 1 : qRound; //Логически у нас не может быть больше 2 раундов. Экстрараунды не считаются
    emit this->roundChanged();
};

void ExtendedMyTcpServer::setRoundCount(const int &qRoundCount){
    if(qRoundCount <= this->round){
        this->roundCount = qRoundCount;
    }
    else if(qRoundCount == this->round+1){//Дополнительный раунд
        roundCount = qRoundCount;
        emit extraRoundSetted();
    }
    else {//(qRoundCount == this->roundCount+2){//До первого касания
        emit clearPointRoundSetted();
    }
    emit this->roundChanged();
}


QString ExtendedMyTcpServer::qMinutesNow(){
    QString str;
    int min = static_cast<int>((roundTime-roundTimeElapsed)/60 );
    str.setNum(min);
    return str;
}

QString ExtendedMyTcpServer::qSecondsNow(){
    QString str;
    int sec = static_cast<int>((roundTime-roundTimeElapsed)%60 );
    str.setNum(sec); //преобразование int к String

    if (sec<10){
        return "0"+str;
    }

    return str;
}
