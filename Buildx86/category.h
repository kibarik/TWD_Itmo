#pragma once

//#include <mysql.h>
//#include <pch.h>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <utility>

#include <QObject>



struct Participant{
    std::string name, birth, club;
};

class Category
{
public:
    std::string name;
    enum MODE {
        PERSONAL_TUL,
        PERSONAL_SPARRING,
        TEAM_TUL,
        TEAM_SPARRING,
        TRADITIONAL_TUL,
        TRADITIONAL_SPARRING
    } mode;

    std::vector <Participant> participants;

    Participant &operator[](size_t index) {
        return participants[index];
    }

    std::vector <Participant> &operator()() {
        return participants;
    }
};


std::vector <std::string> split(std::string str, char delim);
int printCategories(const std::vector <Category>& categories);
Category::MODE getMode(const Category& category);
std::vector<Participant> getParticipants(const Category& category);
std::vector <Category> getCategTemplate(); //temlate category for tests


class CategoryAPI : public QObject {
    //API for interfaces
     Q_OBJECT
    public:
//        CategoryAPI();
        Category::MODE getMode(const Category& category);
        std::vector<Participant> getParticipants(const Category& category);
        std::vector <Category> getCategTemplate(); //temlate category for tests


//    signals: //From C++ to QML (Server to client) ->>
//        void noCategories(); //Error signal
//        std::vector <Category> getCategories();
//        void serverOff();
//        void wifiOff();
//        void displayOff();


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
