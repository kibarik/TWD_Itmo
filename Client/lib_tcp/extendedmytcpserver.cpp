#include "extendedmytcpserver.h"

ExtendedMyTcpServer::ExtendedMyTcpServer(QObject *parent) : MyTcpServer (parent)
{

}

//---------------------сеттеры для Q_PROPERTY-------------
/*сеттеры вся суть ->
 * 1. испустить сигнал emit signal()... с сообщением для логирования.
 * 2. Передать параметр из QML в C++ структуру.
*/
//void MyTcpServer::setRoundTime(const short &QRoundTime){
//    roundTime = QRoundTime;
//    emit timeChanged();
//}

//void MyTcpServer::setRedAdmonition(const short &QRedAdmonition){
//    redAdmonition = QRedAdmonition;
//    emit admonitionChanged(QString("Red"));
//}

//void MyTcpServer::setBlueAdmonition(const short &QBlueAdmonition){
//    blueAdmonition = QBlueAdmonition;
//    emit admonitionChanged(QString("Blue"));
//}
