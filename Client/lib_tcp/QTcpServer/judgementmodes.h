#ifndef JUDGEMENTMODES_H
#define JUDGEMENTMODES_H
#include <QObject>
#include <QDebug>
#include <iostream>
#include "middleware.h"


class JudgementModes : public QObject
{
    Q_OBJECT
public:
    explicit JudgementModes(QObject *parent = nullptr);
    int getRed();
    int getBlue();
    void setRed(int red);
    void setBlue(int blue);
    void setScore(int red, int blue);
    // Режимы работы с очками
    void sparring(middleware &Data);
    void classicTul(middleware &Data);
    void newTul(middleware &Data, short level, bool &levelChanged);

private:
    int red, blue;
};

#endif // JUDGEMENTMODES_H
