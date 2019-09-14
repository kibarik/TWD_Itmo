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
    void reset(int redDiff = -1, int blueDiff = -1, int redBuf = 100, int blueBuf = 100);
    // Режимы работы с очками
    void sparring(middleware &Data);
    void classicTul(middleware &Data);
    void newTul_1(middleware &Data);
    void newTul_2(middleware &Data);
    void newTul_3(middleware &Data);

private:
    int red, blue;
    int redDiff = -1, blueDiff = -1, redBuf = 100, blueBuf = 100;
};

#endif // JUDGEMENTMODES_H
