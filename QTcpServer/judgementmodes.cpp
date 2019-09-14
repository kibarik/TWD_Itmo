#include "judgementmodes.h"

// Конструктор
JudgementModes::JudgementModes(QObject *parent) : QObject(parent)
{
    // Обнуление переменных, хранящие счёт команд
    red = 0;
    blue = 0;
}

// Функции-getter'ы
int JudgementModes::getRed() {return red;}
int JudgementModes::getBlue() {return blue;}

// Функции-setter'ы
void JudgementModes::setRed(int red) {this->red = red;}
void JudgementModes::setBlue(int blue) {this->blue = blue;}

// Устанавливает сразу и red и blue
void JudgementModes::setScore(int red, int blue) {
    this->red = red;
    this->blue = blue;
}

// Сброс переменных redDiff и blueDiff, redBuf и blueBuf
void JudgementModes::reset(int redDiff, int blueDiff, int redBuf, int blueBuf) {
    this->redDiff = redDiff;
    this->blueDiff = blueDiff;
    this->redBuf = redBuf;
    this->blueBuf = blueBuf;
}

// Режим спарринг
void JudgementModes::sparring(middleware &Data) {
    /*
     * ------Коды кнопок и их действия------
     *            0 - отмена
     *           1 - красный +1
     *           2 - красный +2
     *           3 - красный +3
     *            4 - синий +1
     *            5 - синий +2
     *            6 - синий +3
    */
    // Если нажата кнопка отмены баллов, то вычитаем
    if (Data.getButtons()[0] == 0) {
        switch(Data.getButtons()[1]) {
            case 1:
                red -= 1;
                break;
            case 2:
                red -= 2;
                break;
            case 3:
                red -= 3;
                break;
            case 4:
                blue -= 1;
                break;
            case 5:
                blue -= 2;
                break;
            case 6:
                blue -= 3;
                break;
            default:
                std::cout << Data.getButtons()[1] << std::endl;
                break;
        }
        if (blue < 0) blue = 0;
        if (red < 0) red = 0;
    } else { // Если просто была нажата кнопка
        switch(Data.getButtons()[0]) {
            case 1:
                red += 1;
                break;
            case 2:
                red += 2;
                break;
            case 3:
                red += 3;
                break;
            case 4:
                blue += 1;
                break;
            case 5:
                blue += 2;
                break;
            case 6:
                blue += 3;
                break;
            default:
                std::cout << Data.getButtons()[0] << std::endl;
                break;
        }
    }
}

// Режим старый туль
void JudgementModes::classicTul(middleware &Data) {
    /*
     * ------Коды кнопок и их действия------
     *            0 - отмена
     *           1 - красный -5
     *           2 - красный -10
     *           3 - красный 0
     *            4 - синий -5
     *            5 - синий -10
     *            6 - синий 0
    */
    if (Data.getButtons()[0] == 0) {
        switch(Data.getButtons()[1]) {
            case 1:
                red += 5;
                break;
            case 2:
                red += 10;
                break;
            case 3:
                red = redBuf;
                break;
            case 4:
                blue += 5;
                break;
            case 5:
                blue += 10;
                break;
            case 6:
                blue = blueBuf;
                break;
        }
    } else {
        switch(Data.getButtons()[0]) {
            case 1:
                red -= 5;
                break;
            case 2:
                red -= 10;
                break;
            case 3:
                redBuf = red;
                red = 0;
                break;
            case 4:
                blue -= 5;
                break;
            case 5:
                blue -= 10;
                break;
            case 6:
                blueBuf = blue;
                blue = 0;
                break;
        }
    }

    if (red > 100)
        red = 100;
    if (blue > 100)
        blue = 100;
    if (red < 0)
        red = 0;
    if (blue < 0)
        blue = 0;
}

// Режим новый туль, уровень 1
void JudgementModes::newTul_1(middleware &Data) {
    /*
     * ------Коды кнопок и их действия------
     *            0 - отмена
     *           1 - красный -2
     *           2 - красный -100
     *            4 - синий -2
     *            5 - синий -100
    */
    int diff;
    const int judgeActions[3] = {2, 100, 0};
    const int maxDiff = 60;

    if (redDiff == -1) {
        redDiff = maxDiff;
    }

    if (blueDiff == -1) {
        blueDiff = maxDiff;
    }

    if (Data.getButtons()[0] == 0) {
        switch(Data.getButtons()[1]) {
            case 1:
                diff = judgeActions[0];
                if (this->red - diff > 0) {
                    if ((diff + redDiff) < maxDiff) {
                        this->red += diff;
                        redDiff += diff;
                    } else if (redDiff < maxDiff) {
                        this->red += maxDiff - redDiff;
                        redDiff = maxDiff;
                    }
                }
                break;
            case 2:
                //qDebug() << "Before getting buf: " << this->redBuf;
                this->red = this->redBuf;
                break;
            case 4:
                diff = judgeActions[0];
                if (this->blue - diff > 0) {
                    if ((diff + blueDiff) < maxDiff) {
                        this->blue += diff;
                        blueDiff += diff;
                    } else if (blueDiff < maxDiff) {
                        this->blue += maxDiff - blueDiff;
                        blueDiff = maxDiff;
                    }
                }
                break;
            case 5:
                this->blue = this->blueBuf;
                break;
        }
    } else
        switch(Data.getButtons()[0]) {
            case 1:
                diff = judgeActions[0];
                if (this->red - diff > 0) {
                    if ((redDiff - diff) > 0) {
                        this->red -= diff;
                        redDiff -= diff;
                    } else if (redDiff > 0) {
                        this->red -= redDiff;
                        redDiff = 0;
                    }
                }
                //qDebug() << "Pressed 1\n" << "Diff = " << diff;
                break;
            case 2:
                //qDebug() << "Before setting buf: " << this->redBuf;
                this->redBuf = this->red;
                this->red = 0;
                break;
            case 4:
                diff = judgeActions[0];
                if (this->blue - diff > 0) {
                    if ((blueDiff - diff) > 0) {
                        this->blue -= diff;
                        blueDiff -= diff;
                    } else if (blueDiff > 0) {
                        this->blue -= blueDiff;
                        blueDiff = 0;
                    }
                }
                break;
            case 5:
                this->blueBuf = this->blue;
                this->blue = 0;
                break;
        }
}

// Режим новый туль, уровень 2
void JudgementModes::newTul_2(middleware &Data) {
    /*
     * ------Коды кнопок и их действия------
     *            0 - отмена
     *           1 - красный -5
     *           2 - красный -10
     *            4 - синий -5
     *            5 - синий -10
     * ----------Третий уровень-------------
     *            0 - отмена
     *           1 - красный -5
     *           2 - красный -10
     *            4 - синий -5
     *            5 - синий -10
    */
    int diff;
    const int judgeActions[3] = {5, 10, 0};
    const int maxDiff = 20;

    if (redDiff == -1) {
        redDiff = maxDiff;
    }

    if (blueDiff == -1) {
        blueDiff = maxDiff;
    }

    if (Data.getButtons()[0] == 0) {
        switch(Data.getButtons()[1]) {
            case 1:
                diff = judgeActions[0];
                if (this->red - diff > 0) {
                    if ((diff + redDiff) < maxDiff) {
                        this->red += diff;
                        redDiff += diff;
                    } else if (redDiff < maxDiff) {
                        this->red += maxDiff - redDiff;
                        redDiff = maxDiff;
                    }
                }
                break;
            case 2:
                diff = judgeActions[1];
                if (this->red - diff > 0) {
                    if ((diff + redDiff) < maxDiff) {
                        this->red += diff;
                        redDiff += diff;
                    } else if (redDiff < maxDiff) {
                        this->red += maxDiff - redDiff;
                        redDiff = maxDiff;
                    }
                }
                break;
            case 4:
                diff = judgeActions[0];
                if (this->blue - diff > 0) {
                    if ((diff + blueDiff) < maxDiff) {
                        this->blue += diff;
                        blueDiff += diff;
                    } else if (blueDiff < maxDiff) {
                        this->blue += maxDiff - blueDiff;
                        blueDiff = maxDiff;
                    }
                }
                break;
            case 5:
                diff = judgeActions[1];
                if (this->blue - diff > 0) {
                    if ((diff + blueDiff) < maxDiff) {
                        this->blue += diff;
                        blueDiff += diff;
                    } else if (blueDiff < maxDiff) {
                        this->blue += maxDiff - blueDiff;
                        blueDiff = maxDiff;
                    }
                }
                break;
        }
    } else
        switch(Data.getButtons()[0]) {
            case 1:
                diff = judgeActions[0];
                if (this->red - diff > 0) {
                    if ((redDiff - diff) > 0) {
                        this->red -= diff;
                        redDiff -= diff;
                    } else if (redDiff > 0) {
                        this->red -= redDiff;
                        redDiff = 0;
                    }
                }
                break;
            case 2:
                diff = judgeActions[1];
                if (this->red - diff > 0) {
                    if ((redDiff - diff) > 0) {
                        this->red -= diff;
                        redDiff -= diff;
                    } else if (redDiff > 0) {
                        this->red -= redDiff;
                        redDiff = 0;
                    }
                }
                break;
            case 4:
                diff = judgeActions[0];
                if (this->blue - diff > 0) {
                    if ((blueDiff - diff) > 0) {
                        this->blue -= diff;
                        blueDiff -= diff;
                    } else if (blueDiff > 0) {
                        this->blue -= blueDiff;
                        blueDiff = 0;
                    }
                }
                break;
            case 5:
                diff = judgeActions[1];
                if (this->blue - diff > 0) {
                    if ((blueDiff - diff) > 0) {
                        this->blue -= diff;
                        blueDiff -= diff;
                    } else if (blueDiff > 0) {
                        this->blue -= blueDiff;
                        blueDiff = 0;
                    }
                }
                break;
        }
}

// Режим новый туль, уровень 3
void JudgementModes::newTul_3(middleware &Data) {
    /*
     * ------Коды кнопок и их действия------
     *            0 - отмена
     *           1 - красный -5
     *           2 - красный -10
     *            4 - синий -5
     *            5 - синий -10
     * ----------Третий уровень-------------
     *            0 - отмена
     *           1 - красный -5
     *           2 - красный -10
     *            4 - синий -5
     *            5 - синий -10
    */
    int diff;
    const int judgeActions[3] = {5, 10, 0};
    const int maxDiff = 20;

    if (redDiff == -1) {
        redDiff = maxDiff;
    }

    if (blueDiff == -1) {
        blueDiff = maxDiff;
    }

    if (Data.getButtons()[0] == 0) {
        switch(Data.getButtons()[1]) {
            case 1:
                diff = judgeActions[0];
                if (this->red - diff >= 0) {
                    if ((diff + redDiff) < maxDiff) {
                        this->red += diff;
                        redDiff += diff;
                    } else if (redDiff < maxDiff) {
                        this->red += maxDiff - redDiff;
                        redDiff = maxDiff;
                    }
                }
                break;
            case 2:
                diff = judgeActions[1];
                if (this->red - diff >= 0) {
                    if ((diff + redDiff) < maxDiff) {
                        this->red += diff;
                        redDiff += diff;
                    } else if (redDiff < maxDiff) {
                        this->red += maxDiff - redDiff;
                        redDiff = maxDiff;
                    }
                }
                break;
            case 4:
                diff = judgeActions[0];
                if (this->blue - diff >= 0) {
                    if ((diff + blueDiff) < maxDiff) {
                        this->blue += diff;
                        blueDiff += diff;
                    } else if (blueDiff < maxDiff) {
                        this->blue += maxDiff - blueDiff;
                        blueDiff = maxDiff;
                    }
                }
                break;
            case 5:
                diff = judgeActions[1];
                if (this->blue - diff >= 0) {
                    if ((diff + blueDiff) < maxDiff) {
                        this->blue += diff;
                        blueDiff += diff;
                    } else if (blueDiff < maxDiff) {
                        this->blue += maxDiff - blueDiff;
                        blueDiff = maxDiff;
                    }
                }
                break;
        }
    } else
        switch(Data.getButtons()[0]) {
            case 1:
                diff = judgeActions[0];
                if (this->red - diff >= 0) {
                    if ((redDiff - diff) > 0) {
                        this->red -= diff;
                        redDiff -= diff;
                    } else if (redDiff > 0) {
                        this->red -= redDiff;
                        redDiff = 0;
                    }
                }
                break;
            case 2:
                diff = judgeActions[1];
                if (this->red - diff >= 0) {
                    if ((redDiff - diff) > 0) {
                        this->red -= diff;
                        redDiff -= diff;
                    } else if (redDiff > 0) {
                        this->red -= redDiff;
                        redDiff = 0;
                    }
                }
                break;
            case 4:
                diff = judgeActions[0];
                if (this->blue - diff >= 0) {
                    if ((blueDiff - diff) > 0) {
                        this->blue -= diff;
                        blueDiff -= diff;
                    } else if (blueDiff > 0) {
                        this->blue -= blueDiff;
                        blueDiff = 0;
                    }
                }
                break;
            case 5:
                diff = judgeActions[1];
                if (this->blue - diff >= 0) {
                    if ((blueDiff - diff) > 0) {
                        this->blue -= diff;
                        blueDiff -= diff;
                    } else if (blueDiff > 0) {
                        this->blue -= blueDiff;
                        blueDiff = 0;
                    }
                }
                break;
        }
}
