#include "mytcpserver.h"

// Конструктор
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    this->mode = Mode::SPARRING;
    this->roundTime = 120;
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
void MyTcpServer::setMode(Mode mode) {
    this->mode = mode;
}

// Получение текущего режима
MyTcpServer::Mode MyTcpServer::getMode() {
    return this->mode;
}

/*
 *
 *******Секция слотов*******
 *
 */

// Слот для запуска таймера
void MyTcpServer::slotTimerStart(int delay) {
    this->timer.start(delay, this);
};

// Слот для остановки таймера
void MyTcpServer::slotTimerStop() {
    this->timer.stop();
};

// Слот для сброса очков
void MyTcpServer::slotReset() {
    for (unsigned long long i = 0; i < this->Judges.size(); i++) {
        Judges[i]->setRed(0);
        emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
    }
};

// Слот для обработки таймера
void MyTcpServer::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timer.timerId()) {
        if (++timeElapsed > roundTime) {
            slotTimerStop();
            emit signalTimeOver();
        }
    } else {
        QObject::timerEvent(event);
    }
}

// Слот для Чуя (замечания)
void MyTcpServer::slotAdmonition(bool player) {
    static short redAdmonition = 0, blueAdmonition = 0;
    if (player == 0) {
        if (++redAdmonition == 3) {
            redAdmonition = 0;
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setRed(Judges[i]->getRed() - 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
    } else
        if (++blueAdmonition == 3) {
            blueAdmonition = 0;
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setBlue(Judges[i]->getBlue() - 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
}

// Слот для Гамжуна (предупреждения)
void MyTcpServer::slotWarning(bool player) {
    static short redWarning = 0, blueWarning = 0;
    if (player == 0) { // Если красный
        // Уменьшение на 1 балл у всех судей
        for (unsigned long long i = 0; i < this->Judges.size(); i++) {
            Judges[i]->setRed(Judges[i]->getRed() - 1);
            emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
        }

        // Если накоплено 3 предупреждения, то присуждаем поражение красному участнику
        if (++redWarning == 3) {
            redWarning = 0;
            slotTimerStop();
            emit signalDisqualification(0);
        }
    } else { // Если синий
        // Уменьшение на 1 балл у всех судей
        for (unsigned long long i = 0; i < this->Judges.size(); i++) {
            Judges[i]->setBlue(Judges[i]->getBlue() - 1);
            emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
        }

        // Если накоплено 3 предупреждения, то присуждаем поражение синему участнику
        if (++blueWarning == 3) {
            blueWarning = 0;
            slotTimerStop();
            emit signalDisqualification(1);
        }
    }
}

// Слоты, необходимые для работы сервера

void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    QByteArray array = mTcpSocket->readAll();

    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotServerRead()
{
    while(mTcpSocket->bytesAvailable()>0)
    {
        // Получаем значения от клиента
        QByteArray array = mTcpSocket->readAll();
        middleware data = middleware(&array);

        if (data.getID() == -1) { // Если клиент - новый пульт
            JudgementModes *NewJudge = new JudgementModes;
            // Задаём стартовые очки для игроков
            switch(mode) {
                case Mode::SPARRING:
                    NewJudge->setScore(0, 0);
                    break;
                case Mode::CLASSICTUL:
                    NewJudge->setScore(100, 100);
                    break;
            }
            Judges.push_back(NewJudge);

            int JudgeID = static_cast<int>(Judges.size() - 1 );
            QByteArray id = QString::number(JudgeID).toLocal8Bit();
            mTcpSocket->write(id);
        } else {
            if(data.getRawData() != "nan" && timer.isActive()) {
                unsigned long long judgeNum = static_cast<unsigned long long>(data.getID());
                array.remove(0, 1);
                // В зависимости от режима работы, выбираем алгоритм
                switch(mode) {
                    case Mode::SPARRING: // Спарринг
                        Judges[judgeNum]->sparring(data);
                        break;
                    case Mode::CLASSICTUL: // Страый туль
                        Judges[judgeNum]->classicTul(data);
                        break;
                }
                emit signalScoreUpdate(static_cast<int>(judgeNum), Judges[judgeNum]->getRed(), Judges[judgeNum]->getBlue());
            }
        }
    }
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}
