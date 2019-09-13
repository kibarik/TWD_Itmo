#ifndef JUDGEMENTMODES_H
#define JUDGEMENTMODES_H
#include <QObject>
#include <iostream>


class JudgementModes : public QObject
{
    Q_OBJECT
public:
    explicit JudgementModes(QObject *parent = nullptr);
    void sparring(QByteArray array);

signals:
    void signalScoreUpdate(int red, int blue); // Сигнал, вызываемый при изменении счёта судьями

private:
    int red, blue;
};

#endif // JUDGEMENTMODES_H
