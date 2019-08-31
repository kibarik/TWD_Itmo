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
    static int redBuf = 100, blueBuf = 100;
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

// Режим новый туль
void JudgementModes::newTul(middleware &Data, short level, bool &levelChanged) {
    /*
     * ------Коды кнопок и их действия------
     * ----------Первый уровень-------------
     *            0 - отмена
     *           1 - красный -2
     *           2 - красный -100
     *            4 - синий -2
     *            5 - синий -100
     * ----------Второй уровень-------------
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
    static int redDiff, blueDiff, redBuf = 100, blueBuf = 100;
    int action;
    const int judgeActions[3][3] = {
        {2, 100, 0},
        {5, 0, 0},
        {5, 0, 0}
    };
    const int maxDiffs[3] = {60, 20, 20};
    if (levelChanged) {
        redDiff = maxDiffs[level];
        blueDiff = maxDiffs[level];
    }

    if (Data.getButtons()[0] == 0){
        switch(Data.getButtons()[0]) {
            case 1:
                action = judgeActions[level][Data.getButtons()[0] - 1];
                if ((action + redDiff) < maxDiffs[level]) {
                    red += action;
                    redDiff += action;
                } else if (redDiff < maxDiffs[level]) {
                    red += maxDiffs[level] - redDiff;
                    redDiff = maxDiffs[level];
                }
                break;
            case 2:
                if (level == 0)
                    red = redBuf;
                break;
            case 4:
                action = judgeActions[level][Data.getButtons()[0] % 3 - 1];
                if ((action + blueDiff) < maxDiffs[level]) {
                    blue += action;
                    blueDiff += action;
                } else if (blueDiff < maxDiffs[level]) {
                    blue += maxDiffs[level] - blueDiff;
                    blueDiff = maxDiffs[level];
                }
                break;
            case 5:
                if (level == 0) {
                    blue = blueBuf;
                }
                break;
        }
    } else
        switch(Data.getButtons()[0]) {
            case 1:
                action = judgeActions[level][Data.getButtons()[0] - 1];
                if ((redDiff - action) > 0) {
                    red -= action;
                    redDiff -= action;
                } else if (redDiff > 0) {
                    red -= redDiff;
                    redDiff = 0;
                }
                break;
            case 2:
                redBuf = red;
                if (level == 0)
                    red = 0;
                break;
            case 4:
                action = judgeActions[level][Data.getButtons()[0] % 3 - 1];
                if ((blueDiff - action) > 0) {
                    blue -= action;
                    blueDiff -= action;
                } else if (blueDiff > 0) {
                    blue -= blueDiff;
                    blueDiff = 0;
                }
                break;
            case 5:
                blueBuf = blue;
                if (level == 0)
                    blue = 0;
                break;
        }
}
