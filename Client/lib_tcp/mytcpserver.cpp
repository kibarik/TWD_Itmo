#include "mytcpserver.h"

// Конструктор
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    this->mode = 0;
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 6000)){
        std::cout << "server is not started" << std::endl;
    } else {
        std::cout << "server is started" << std::endl;
    }
}

// Режим спарринг

// Выбор режима
void MyTcpServer::setMode(short mode) {
    this->mode = mode;
}

// Получение текущего режима
short MyTcpServer::getMode() {
    return this->mode;
}

void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    while(mTcpSocket->bytesAvailable()>0)
    {
        /*
         * ------Коды кнопок и их действия------
         *            0 - отмена
         *           1 - красный +1
         *           2 - красный +2
         *           3 - кпасный +3
         *            4 - синий +1
         *            5 - синий +2
         *            6 - синий +3
        */
        // Получаем значения от клиента
        QByteArray array = mTcpSocket->readAll();
        mTcpSocket->write(array);
        // В зависимости от режима работы, выбираем алгоритм
        switch(mode) {
            case 0: // Спарринг
                modes.sparring(array);
                break;
            case 1: // Туль
                std::cout << "Tul" << std::endl;
                break;
        }
    }
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}
