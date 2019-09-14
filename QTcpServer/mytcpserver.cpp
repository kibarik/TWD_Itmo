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

/*
 *
 *******Секция геттеров/сеттеров*******
 *
 */

// Выбор режима
void MyTcpServer::setMode(Mode mode) {
    this->mode = mode;
}

// Получение текущего режима
MyTcpServer::Mode MyTcpServer::getMode() {
    return this->mode;
}

// Получение количества Чуев (замечаний)
short MyTcpServer::getAdmonition(bool player) {
    return player? this->blueAdmonition: this->redAdmonition;
}

// Получение количества Гамжунов (предупреждений)
short MyTcpServer::getWarning(bool player) {
    return player? this->blueWarning: this->redWarning;
}

// Получение общего счёта (счёта по всем судьям)
int MyTcpServer::getOverallScore(bool player) {
    int score = 0;
    for (ulong i = 0; i < this->Judges.size(); i++) {
        score += player? this->Judges[i]->getBlue(): this->Judges[i]->getRed();
    }
    return score;
}

/*
 *
 *************Секция слотов************
 *
 */

// Слот для запуска таймера
void MyTcpServer::slotTimerStart() {
    this->roundTimeElapsed = 0;
    this->mainTimer.start(this->roundTimerDelay, this);
};

// Слот для остановки таймера
void MyTcpServer::slotTimerStop() {
    this->mainTimer.stop();
};

// Слот для паузы
void MyTcpServer::slotTimerPause(short time) {
    if (this->pauseTimer.isActive()) {
        this->pauseTimer.stop();
        this->mainTimer.start(this->roundTimerDelay, this);
    } else {
        if (time) {
            this->mainTimer.stop();
            this->pauseTime = time;
            this->pauseTimeElapsed = 0;
            this->pauseTimer.start(1000, this);
        } else {
            (this->mainTimer.isActive())? this->mainTimer.stop(): this->mainTimer.start(this->roundTimerDelay, this);
        }
    }
}

// Слот для сброса очков
void MyTcpServer::slotReset() {
    for (ulong i = 0; i < this->Judges.size(); i++) {
        Judges[i]->setRed(0);
        Judges[i]->setBlue(0);
        emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
    }
};

// Слот для обработки таймера
void MyTcpServer::timerEvent(QTimerEvent *event) {
    if (event->timerId() == mainTimer.timerId()) {
        if (++roundTimeElapsed > roundTime) {
            slotTimerStop();
            emit this->signalTimeOver();
        }
    } else if (event->timerId() == pauseTimer.timerId()) {
        if (++this->pauseTimeElapsed > pauseTime) {
            slotTimerPause();
        }
    } else {
        QObject::timerEvent(event);
    }
    emit this->signalTimerEvent(this->roundTimeElapsed);
}

// Слот для Чуя (замечания)
void MyTcpServer::slotAdmonition(bool player) {
    if (player == 0) { // Красный
        if (++redAdmonition == 3) { // Если получено 3 замечания
            redAdmonition = 0;
            // Уменьшение на 1 балл у всех судей
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setRed(Judges[i]->getRed() - 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
    } else { // Синий
        if (++blueAdmonition == 3) { // Если получено 3 замечания
            blueAdmonition = 0;
            // Уменьшение на 1 балл у всех судей
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setBlue(Judges[i]->getBlue() - 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
    }
    emit this->signalAdmonition(redAdmonition, blueAdmonition);
}

// Слот для отмены Чуя (замечания)
void MyTcpServer::slotCancelAdmonition(bool player) {
    if (player == 0) { // Красный
        if (--redAdmonition == -1) {
            redAdmonition = 2;
            // Увеличение счёта на 1 у всех судий
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setRed(Judges[i]->getRed() + 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
    } else { // Синий
        if (--blueAdmonition == -1) {
            blueAdmonition = 2;
            // Увеличение счёта на 1 у всех судий
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setBlue(Judges[i]->getBlue() + 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
    }
    emit this->signalAdmonition(redAdmonition, blueAdmonition);
}

// Слот для Гамжуна (предупреждения)
void MyTcpServer::slotWarning(bool player) {
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
    emit this->signalWarning(redWarning, blueWarning);
}

// Слот для отмены Гамжуна (предупреждения)
void MyTcpServer::slotCancelWarning(bool player) {
    if (player == 0) { // Если красный
        // Увеличение на 1 балл у всех судей
        for (unsigned long long i = 0; i < this->Judges.size(); i++) {
            Judges[i]->setRed(Judges[i]->getRed() + 1);
            emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
        }

        --redWarning;
    } else { // Если синий
        // Увеличение на 1 балл у всех судей
        for (unsigned long long i = 0; i < this->Judges.size(); i++) {
            Judges[i]->setBlue(Judges[i]->getBlue() + 1);
            emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
        }
        --blueWarning;
    }
    emit this->signalWarning(redWarning, blueWarning);
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
                case Mode::NEWTUL:
                    NewJudge->setScore(100, 100);
                    break;
            }
            Judges.push_back(NewJudge);

            int JudgeID = static_cast<int>(Judges.size() - 1 );
            QByteArray id = QString::number(JudgeID).toLocal8Bit();
            mTcpSocket->write(id);
        } else {
            if(data.getRawData() != "nan" && mainTimer.isActive()) {
                qDebug() << "Test";
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
                    case Mode::NEWTUL:
                        Judges[judgeNum]->newTul(data, tulLevel, tulLevelChanged);
                        if (tulLevelChanged) {
                            tulLevelChanged = false;
                        }
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
