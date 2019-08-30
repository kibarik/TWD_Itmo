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
