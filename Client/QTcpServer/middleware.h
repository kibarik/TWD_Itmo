#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H
#include <QObject>
#include <QVector>
#include <QDebug>

class middleware
{
public:
    middleware(QByteArray *Data = nullptr);
    void parseData(QByteArray &Data);

    QString getRawData();
    int getID();
    QVector <int> getButtons();

private:
    QString rawData;
    int id;
    QVector <int> buttons;
};

#endif // MIDDLEWARE_H
