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
    void sparring(middleware &Data);
    int getRed();
    int getBlue();
    void setRed(int red);
    void setBlue(int blue);

private:
    int red, blue;
};

#endif // JUDGEMENTMODES_H
