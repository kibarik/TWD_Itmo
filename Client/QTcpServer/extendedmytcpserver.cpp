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


QString ExtendedMyTcpServer::qMinutesNow(){
    QString str;
    int min = static_cast<int>((roundTime-roundTimeElapsed)/60 );
    str.setNum(min);
    return str;
}

QString ExtendedMyTcpServer::qSecondsNow(){
    QString str;
    int sec = static_cast<int>((roundTime-roundTimeElapsed)%60 );
    str.setNum(sec);

    if (sec<10){
        str.append("0");
    }

    return str;
}
