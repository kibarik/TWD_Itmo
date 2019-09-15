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
    emit timeChanged();
}

void ExtendedMyTcpServer::setRedAdmonition(const int &QRedAdmonition){
    redAdmonition = static_cast<short>(QRedAdmonition);
    emit admonitionChanged();
}

void ExtendedMyTcpServer::setBlueAdmonition(const int &QBlueAdmonition){
    blueAdmonition = static_cast<short>(QBlueAdmonition);
    emit admonitionChanged();
}

void ExtendedMyTcpServer::setRedWarning(const int &QRedWarning){
    redWarning = static_cast<short>(QRedWarning);
    emit warningChanged();
}

void ExtendedMyTcpServer::setBlueWarning(const int &QBlueWarning){
    blueWarning = static_cast<short>(QBlueWarning);
    emit warningChanged();
}
void ExtendedMyTcpServer::setPauseTime(const int &qPauseTime) {
    pauseTime = static_cast<short>(qPauseTime);
    emit timeChanged();
}
