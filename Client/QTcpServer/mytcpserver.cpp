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
short MyTcpServer::getAdmonition(Sportsman player) {
    return player? this->blueAdmonition: this->redAdmonition;
}

// Получение количества Гамжунов (предупреждений)
short MyTcpServer::getWarning(Sportsman player) {
    return player? this->blueWarning: this->redWarning;
}

// Получение общего счёта (счёта по всем судьям)
int MyTcpServer::getOverallScore(Sportsman player) {
    int score = 0;
    for (ulong i = 0; i < this->Judges.size(); i++) {
        score += player == Sportsman::BLUE? this->Judges[i]->getBlue(): this->Judges[i]->getRed();
    }
    return score;
}

// Получение счёта у определённого судьи
int MyTcpServer::getScore(int judgeNum, MyTcpServer::Sportsman player) {
    if (static_cast<ulong>(judgeNum) >= this->Judges.size())
        return 0;
    return player == MyTcpServer::Sportsman::RED? this->Judges[static_cast<ulong>(judgeNum)]->getRed(): this->Judges[static_cast<ulong>(judgeNum)]->getBlue();
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
    this->roundTimeElapsed = 0;
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


// Слот для сброса всего
void MyTcpServer::slotReset() {
    for (ulong i = 0; i < this->Judges.size(); i++) {
        this->Judges[i]->setRed(0);
        this->Judges[i]->setBlue(0);
        emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
    }
    this->roundTimeElapsed = 0;
    this->pauseTimeElapsed = 0;
    if(this->mainTimer.isActive())
        mainTimer.stop();
    if(this->pauseTimer.isActive())
        pauseTimer.stop();
    this->redWarning = 0;
    this->redAdmonition = 0;
    this->blueWarning = 0;
    this->blueAdmonition = 0;
};

// Слот для изменения уровня туля
void MyTcpServer::slotChangeNewTulLevel(short tulLevel) {
    for (ulong i = 0; i < this->Judges.size(); i++) {
        this->Judges[i]->reset();
    }
    switch (tulLevel) {
        case 1:
            this->mode = MyTcpServer::Mode::NEWTUL_1;
            break;
        case 2:
            this->mode = MyTcpServer::Mode::NEWTUL_2;
            break;
        case 3:
            this->mode = MyTcpServer::Mode::NEWTUL_3;
            break;
    }
}

// Слот для обработки таймера
void MyTcpServer::timerEvent(QTimerEvent *event) {
    if (event->timerId() == mainTimer.timerId()) {
        if ((++roundTimeElapsed) > roundTime) {
            slotTimerStop();
            emit this->signalTimeOver();
        } else {
            emit this->signalTimerEvent(this->roundTimeElapsed);
        }
    } else if (event->timerId() == pauseTimer.timerId()) {
        if (++this->pauseTimeElapsed > pauseTime) {
            slotTimerPause();
        } else {
            emit this->signalPauseTimerEvent(this->pauseTimeElapsed);
        }
    } else {
        QObject::timerEvent(event);
    }
}

// Слот для Чуя (замечания)
void MyTcpServer::slotAdmonition(Sportsman player) {
    if (player == Sportsman::RED) { // Красный
        if ((++redAdmonition) % 3 == 0) { // Если получено 3 замечания
            // Уменьшение на 1 балл у всех судей
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setRed(Judges[i]->getRed() - 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
    } else { // Синий
        if ((++blueAdmonition) % 3 == 0) { // Если получено 3 замечания
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
void MyTcpServer::slotCancelAdmonition(Sportsman player) {
    if ((player == Sportsman::RED) && (redAdmonition > 0)) { // Красный
        if ((--redAdmonition) % 3 == 2) {
            // Увеличение счёта на 1 у всех судий
            for (unsigned long long i = 0; i < this->Judges.size(); i++) {
                Judges[i]->setRed(Judges[i]->getRed() + 1);
                emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
            }
        }
    } else if (blueAdmonition > 0) { // Синий
        if ((--blueAdmonition) % 3 == 2) {
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
void MyTcpServer::slotWarning(Sportsman player) {
    if (player == Sportsman::RED) { // Если красный
        // Уменьшение на 1 балл у всех судей
        for (unsigned long long i = 0; i < this->Judges.size(); i++) {
            Judges[i]->setRed(Judges[i]->getRed() - 1);
            emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
        }

        // Если накоплено 3 предупреждения, то присуждаем поражение красному участнику
        if (++redWarning == 3) {
            redWarning = 0;
            slotTimerStop();
            emit signalDisqualification(Sportsman::RED);
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
            emit signalDisqualification(Sportsman::BLUE);
        }
    }
    emit this->signalWarning(redWarning, blueWarning);
}

// Слот для отмены Гамжуна (предупреждения)
void MyTcpServer::slotCancelWarning(Sportsman player) {
    if (player == Sportsman::RED && redWarning > 0) { // Если красный
        // Увеличение на 1 балл у всех судей
        for (unsigned long long i = 0; i < this->Judges.size(); i++) {
            Judges[i]->setRed(Judges[i]->getRed() + 1);
            emit this->signalScoreUpdate(static_cast<int>(i), Judges[i]->getRed(), Judges[i]->getBlue());
        }

        --redWarning;
    } else if (blueWarning > 0) { // Если синий
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
        qDebug() << array;

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
                case Mode::NEWTUL_1:
                case Mode::NEWTUL_2:
                case Mode::NEWTUL_3:
                    NewJudge->setScore(100, 100);
                    break;
            }
            Judges.push_back(NewJudge);

            int JudgeID = static_cast<int>(Judges.size() - 1 );
            QByteArray id = QString::number(JudgeID).toLocal8Bit();
            mTcpSocket->write(id);
            delete NewJudge;
        } else {
            if(data.getRawData() != "nan" && mainTimer.isActive()) {
                //qDebug() << "ID: " << data.getID() << " " << data.getButtons();
                ulong judgeNum = static_cast<ulong>(data.getID());
                if (judgeNum >= Judges.size()) { // Если подключился пульт без регистрации
                    emit this->signalJudgeNumError(judgeNum);
                } else {
                    // В зависимости от режима работы, выбираем алгоритм
                    switch(mode) {
                        case Mode::SPARRING: // Спарринг
                            Judges[judgeNum]->sparring(data);
                            break;
                        case Mode::CLASSICTUL: // Старый туль
                            Judges[judgeNum]->reset();
                            Judges[judgeNum]->classicTul(data);
                            break;
                        case Mode::NEWTUL_1:
                            Judges[judgeNum]->newTul_1(data);
                            break;
                        case Mode::NEWTUL_2:
                            Judges[judgeNum]->newTul_2(data);
                            break;
                        case Mode::NEWTUL_3:
                            Judges[judgeNum]->newTul_3(data);
                            break;
                    }
                    emit signalScoreUpdate(static_cast<int>(judgeNum), Judges[judgeNum]->getRed(), Judges[judgeNum]->getBlue());
                }
            }
        }
    }
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}
