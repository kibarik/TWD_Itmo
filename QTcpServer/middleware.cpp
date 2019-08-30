#include "middleware.h"

// Конструктор
middleware::middleware(QByteArray *Data)
{
    if (*Data != nullptr)
        this->parseData(*Data);
}

// Методы-getter'ы
int middleware::getID() {return id;}
QString middleware::getRawData() {return rawData;}
QVector <int> middleware::getButtons() {return buttons;}

// Получение данных из строки
void middleware::parseData(QByteArray &Data) {
    if (Data.size() == 0)
        return;
    this->rawData = QString(Data);
    QStringList rawValues = this->rawData.split("|");
    this->id = rawValues[0].toInt();
    qDebug() << this->rawData;
    for (int i = 1; i < rawValues.size(); i++)
        this->buttons.push_back(rawValues[i].toInt());
}
