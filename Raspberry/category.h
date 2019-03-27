#pragma once

//#include <mysql.h>
//#include <pch.h>
#include <iostream>
#include <QVector>
#include <iostream>
#include <QString>
#include <utility>
#include <QObject>

struct Participant{
    QString name, birth, club;
};

class Category
{
public:
    QString name;
    enum MODE {
        PERSONAL_TUL,
        PERSONAL_SPARRING,
        TEAM_TUL,
        TEAM_SPARRING,
        TRADITIONAL_TUL,
        TRADITIONAL_SPARRING
    } mode;

    QVector <Participant> participants;

    Participant &operator[](int index) {
        return participants[index];
    }

    QVector <Participant> &operator()() {
        return participants;
    }

    QVector <Participant> getParticipants(){
        return participants;
    }
    Category::MODE getMode(const Category& category){
      return category.mode;
    }
};



QVector <QString> split(QString, char delim);
int printCategories(const QVector <Category>& categories);
//Category::MODE getMode(const Category& category);
//std::vector<Participant> getParticipants(const Category& category);
QVector <Category> getCategTemplate(); //temlate category for tests
QVector <Category> getCategories();

class CategoryAPI : public QObject {
    //API for interfaces
    Q_OBJECT
    public:
//        CategoryAPI();

    signals: //From C++ to QML (Server to client) ->>
        //void noCategories(); //Error signal

        //std::vector <Category> getCategories();
        //void serverOff();
        //void wifiOff();
        //void displayOff();


//    public slots: //From QML to C++ <<-
//        void categoryEnd();
//        void setWin(); //присудить место участнику
//        std::pair<Participant, Participant> nextPair();
//        Category selectCategory();

//        //sparring
//        void start();
//        void stop();
//        void pause();
//        void chui(); //Чуй спарринг
//        void gamj(); //Гамчун спарринг

//        //tul
//        void nextLvl(); //уровень судейства
};
