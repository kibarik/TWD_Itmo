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
void ExtendedMyTcpServer::setRoundTime(const short &QRoundTime){
    roundTime = QRoundTime;
    emit timeChanged();
}

void ExtendedMyTcpServer::setRedAdmonition(const short &QRedAdmonition){
    redAdmonition = QRedAdmonition;
    emit admonitionChanged();
}

void ExtendedMyTcpServer::setBlueAdmonition(const short &QBlueAdmonition){
    blueAdmonition = QBlueAdmonition;
    emit admonitionChanged();
}

void ExtendedMyTcpServer::setRedWarning(const short &QRedWarning){
    redWarning = QRedWarning;
    emit warningChanged();
}

void ExtendedMyTcpServer::setBlueWarning(const short &QBlueWarning){
    blueWarning = QBlueWarning;
    emit warningChanged();
}
