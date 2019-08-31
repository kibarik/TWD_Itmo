#include "judgementmodes.h"

// Конструктор
JudgementModes::JudgementModes(QObject *parent) : QObject(parent)
{
    // Обнуление переменных, хранящие счёт команд
    red = 0;
    blue = 0;
}

// Режим спарринг
void JudgementModes::sparring(QByteArray array) {
    // Если нажата кнопка отмены баллов, то вычитаем
    if (static_cast<uint>(array[0] - '0') == 0) {
        switch(static_cast<uint>(array[1] - '0')) {
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
                std::cout << static_cast<uint>(array[1] - '0') << std::endl;
                break;
        }
        if (blue < 0) blue = 0;
        if (red < 0) red = 0;
    } else { // Если просто была нажата кнопка
        switch(static_cast<uint>(array[0] - '0')) {
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
                std::cout << static_cast<uint>(array[0] - '0') << std::endl;
                break;
        }
    }
    emit signalScoreUpdate(red, blue);
}
