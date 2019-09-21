import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Window 2.12

import ServerAPI 1.0

import "Sparring/"
import "OutMonitor/"
import "Tul/"
import "Categories/"
import "Share/"
import "QTcpServer/"

//import ServerAPI 1.0
/*
  подключение структуры
  из структуры вытащить все категории в список
  категория проведена - удалить элемент из списка
  список вида: < [туль, имя категории, участники], [спарринг, имя категории, участники] >

  Если туль: отдаем сигнал signalModeTul для туль
  Иначе: отдаем signalModeSparring для спарринга

  в Window для слота определяем логику:
    signalModeTul -> отображение Tul и OutMonitorTul
    signalModeSparring -> отображение Sparring и OutMonitorSparring

  Изменить порядок категорий можно из окна категорий

  https://evileg.com/ru/post/305/

*/

Window {
    id: mainQmlWindow
    width: 320+170
    height: 480+85
    visible: true
    minimumHeight: 480
    minimumWidth: 320

    //данный параметр скрывает управлению спаррингом
    //вызывается при переключении в режим туль
//    maximumHeight: 480
//    maximumWidth: 320

    //flags: Qt.FramelessWindowHint // Отключаем обрамление окна

    property string redParticipant: "Выберите участников";
    property string blueParticipant: "Выберите участников";
    property string nextParticipant1: "Следующий участник";
    property string nextParticipant2: "Следующий участник";
    property string nowCategoryName: "Выберите категорию";

    property alias server: serverAPI //объявляем serverAPI глобальным

    /* Используется в ./sparring/Time.qml  */
    property string roundText: serverAPI.qRound + " : " + serverAPI.qRoundCount;
    property string timeText:  serverAPI.qMinutesNow+":"+ serverAPI.qSecondsNow
    property bool isDoctorRound: false
    property bool isExtraRound: false
/*-----------------------MyTCP server--------------------------------*/
    /* обеспечивает ввод/вывод из QML в C++
    * Данная структура объявлена в main.cpp
    * Cостоит из ядра QTcpServer/mytcpserver.h и обертки QTcpServer/extendedmytcpserver.h
    */
    ServerAPI {
        id: serverAPI
        qRoundTime: 5 //время раунда
        qPauseTime: 5 //время паузы
        qRound: 2 //количество раундов по программе задано
        qRoundCount: 1 //Текущий раунд

        /* Share/TimeControl.qml
        *  В контроллере обрабатываются сигналы времени
        */

        //Сигналы от myTcpServer.cpp (библиотека функций для времени + пульты)
        onSignalAdmonition: {
            console.log("Admonition signal: "+qRedAdmonition +" blue->"+qBlueAdmonition)
            admonitionChanged() //необходимо, чтобы заработал Alias
        }

        onSignalDisqualification: {
            console.log("Disqualification!")
            admonitionChanged()
            warningChanged()
            timeChanged()
        }

        onSignalJudgeNumError: {
            console.log("Client disconnected")
        }

        onSignalScoreUpdate: {
            console.log("Signal updated: red->", serverAPI.qRedScore()," blue->", serverAPI.qBlueScore())
            scoreChanged()
        }

        onSignalWarning: {
            console.log("Signal warning: red->",qRedWarning," blue->" ,qBlueWarning)
            warningChanged()
        }

        onSignalTimerEvent: {
            timeChanged() //Превращает сигнал от TcpServer::onSignalTimerEvent в QML сигнал
        }

        onSignalTimeOver: {
            console.log("Time over!")
            serverAPI.qRoundCount++;
            mainQmlWindow.isDoctorRound = false;

            timeControl.isNewRound=true;
            timeControl.isRoundActive = false;
            timeControl.startButtonText  = "Следующий\n раунд"
        }


        //сигналы от ExtendedMyTcpServer (библиотека-обертка для перевода из C++ в QT)
        onTimeChanged: {
            console.log("onTimeChanged");
        }


        onRoundChanged: {
            console.log("Round set: ", serverAPI.qRound)

            if(!mainQmlWindow.isExtraRound){
                mainQmlWindow.roundText = serverAPI.qRound +" : "+ serverAPI.qRoundCount
            }
        }

        onScoreChanged: {
            console.log("Score changed")
        }

        //Данный сигнал использует property alias в Sparring.qml и Time.qml
        onExtraRoundSetted: {
            console.log("Extra round setted")
            mainQmlWindow.roundText = mainQmlWindow.server.qRound+" : "+ "Д"
            mainQmlWindow.isExtraRound = true
            timeChanged();
        }

        onClearPointRoundSetted: {
            console.log("First clear point round setted")
            mainQmlWindow.roundText = mainQmlWindow.server.qRound+" : "+ "К"
            mainQmlWindow.isExtraRound = true
        }

        onDoctorSignal: {
            console.log("Doctor signal")
            serverAPI.qRoundTime = 60;
            mainQmlWindow.isDoctorRound = true; //флаг изменения цвета текста
            serverAPI.slotTimerStart();
        }
    }


/*===============Main Mode Windows=============================*/
    Column {
        id: leftPanel
        width: 85
        height: parent.height
        anchors.rightMargin: 3
        anchors.right: sparringWindow.left

        Rectangle {
            id: rectangle
            width: parent.width
            height: parent.height
            color: "#34495e"


                Button {
                    id: redRemark
                    width: parent.width
                    height: width
                    background: Rectangle {
                        color: redRemark.hovered ? "#c0392b" : "#e74c3c"
                    }
                    contentItem: Text {
                        color: "#fff"
                        text: "Чуй"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    onClicked: {
                        if(timeControl.isRoundActive){
                            console.log('red Remark plus');
                            serverAPI.slotAdmonition(ServerAPI.RED); //добавления чуя на систему счета, waning - камчун, admonition - чуй
                        }
                    }

                }

                Button {
                    id: redWarning
                    width: parent.width
                    height: width
                    anchors.topMargin: 3
                    anchors.top: redRemark.bottom
                    background: Rectangle {
                        color: redWarning.hovered ? "#c0392b" : "#e74c3c"
                    }
                    contentItem: Text {
                        color: "#fff"
                        text: "Камчун"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    onClicked: {
                        if(timeControl.isRoundActive){
                            console.log('red Warning plus');
                            serverAPI.slotWarning(ServerAPI.RED) //добавления камчуна на систему счета, waning - камчун, admonition - чуй
                        }
                    }
                }

                Button {
                    id: redRemarkUndo
                    width: parent.width
                    height: width
                    anchors.topMargin: 3
                    anchors.top: redWarning.bottom
                    background: Rectangle {
                        color: redRemarkUndo.hovered ? "#33d9b2" : "#218c74"
                    }
                    contentItem: Text {
                        color: "#fff"
                        text: "Отменить \n Чуй"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    onClicked: {
                        if(timeControl.isRoundActive){
                            serverAPI.slotCancelAdmonition(ServerAPI.RED); //отменить чуй красному
                        }
                    }
                }

                Button {
                    id: redWarningUndo
                    width: parent.width
                    height: width
                    anchors.topMargin: 3
                    anchors.top: redRemarkUndo.bottom
                    background: Rectangle {
                        color: redWarningUndo.hovered ? "#33d9b2" : "#218c74"
                    }
                    contentItem: Text {
                        color: "#fff"
                        text: "Отменить\nКамчун"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    onClicked: {
                        if(timeControl.isRoundActive){
                            serverAPI.slotCancelWarning(ServerAPI.RED); //добавить камчун красному
                        }
                    }
                }
        }
    }




    Tul {
        id: tulWindow
        anchors.horizontalCenter: parent.horizontalCenter
        visible: false
        onCategoryShow: {
            categoryWindow.show()
            mainQmlWindow.opacity = 0.0
        }
    }


    TimeControl { /* ./Share/TimeControl.qml */
        id: timeControl
        width: 320
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: tulWindow.bottom
    }

/*===============Out Big monitors=============================*/

    Sparring {
        id: sparringWindow
        anchors.horizontalCenter: parent.horizontalCenter
        visible: true

        onCategoryShow: {
            categoryWindow.show()
            mainQmlWindow.opacity = 0.0
        }
    }

    OutMonitorSparring {
        id: monitorSparring
        visible: true
    }

    PairDisplay {
        id: pairDisplayShare
        visible: false

        onPairDisplayButtonClicked: {
            participantsWindow.show()
            participantsWindow.participantsNames = categoryAPI.setQmlParticipantsNames(mainQmlWindow.nowCategoryName)
            participantsWindow.categoryName = nowCategoryName
            participantsWindow.showParticipants()
        }
    }

    OutMonitorTul {
        id: monitorTul
        visible: false
    }

    /*===============Control Windows=============================*/


    CategoryWindow {
        visible: false
        id: categoryWindow
        flags: Qt.FramelessWindowHint // Отключаем обрамление окна

        onSignalExit: { //из Category.qml сигнал на возврат в гл. окно
            mainQmlWindow.opacity = 1.0
            categoryWindow.close()
        }

        onCategoryShow: {
            categoryWindow.showCategories()
        }

        onOpenParticipants: {
            participantsWindow.show()
            categoryWindow.close()
            //остальные действия прописаны в CategoryWindow control.onclicked
        }
    }

    /*   Контролирует переключение между режимами   */
    ParticipantsWindow {
        visible: false
        id: participantsWindow
        flags: Qt.FramelessWindowHint // Отключаем обрамление окна

        onSignalExit: {
            categoryWindow.show()
            participantsWindow.close()
        }

        onSelectNowPair: {
            mainQmlWindow.opacity = 1.0
            participantsWindow.close()

            //устанавливаем имена участников на главном экране для "Сейчас"
            mainQmlWindow.redParticipant = participantNowPairPositions[0]
            mainQmlWindow.blueParticipant = participantNowPairPositions[1]

        }

        onSelectNextPair: {
            mainQmlWindow.opacity = 1.0
            participantsWindow.close()

            //устанавливаем имена участников на главном экране для "Следующие"
            mainQmlWindow.nextParticipant1 = participantNextPairPositions[0]
            mainQmlWindow.nextParticipant2 = participantNextPairPositions[1]

        }

        onMonitorSetTul: { //переключение монитора на туль
            console.log("Monitor set TUL")
            monitorTul.show()
            monitorSparring.close()

            sparringWindow.visible = false
            tulWindow.visible = true

            //Переводим в режим туля
            serverAPI.qRoundTime = 6000
            mainQmlWindow.width = 320
            mainQmlWindow.maximumWidth = 320
//            mainQmlWindow.minimumHeight = 480
        }

        onMonitorSetSparring: { //переключение монитора на спарринг
            console.log("Monitor set SPARRING")
            monitorTul.close()
            monitorSparring.show()

            sparringWindow.visible = true
            tulWindow.visible = false

            //переводим в режим спарринга
            serverAPI.qRoundTime = 60
            mainQmlWindow.maximumWidth = 320+170
            mainQmlWindow.width = 320+170
        }
    }

    Column {
        id: rightPanel
        width: 85
        height: parent.height
        anchors.left: sparringWindow.right
        anchors.leftMargin: 3
        Rectangle {
            width: parent.width
            height: parent.height
            color: "#34495e"
            Button {
                id: blueRemark
                width: parent.width
                height: width
                contentItem: Text {
                    color: "#ffffff"
                    text: "Чуй"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                background: Rectangle {
                    color: blueRemark.hovered ? "#60a3bc" : "#1e3799"
                }

                onClicked: {
                    if(timeControl.isRoundActive){
                        serverAPI.slotAdmonition(ServerAPI.BLUE);
                    }
                }
            }

            Button {
                id: blueWarning
                width: parent.width
                height: width
                contentItem: Text {
                    color: "#ffffff"
                    text: "Камчун"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                anchors.topMargin: 3
                anchors.top: blueRemark.bottom
                background: Rectangle {
                    color: blueWarning.hovered ? "#60a3bc" : "#1e3799"
                }

                onClicked: {
                    if(timeControl.isRoundActive){
                        console.log("Blue warning added clicked")
                        serverAPI.slotWarning(ServerAPI.BLUE);
                    }
                }
            }

            Button {
                id: blueRemarkUndo
                width: parent.width
                height: width
                contentItem: Text {
                    color: "#ffffff"
                    text: "Отменить \n Чуй"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                anchors.topMargin: 3
                anchors.top: blueWarning.bottom
                background: Rectangle {
                    color: blueRemarkUndo.hovered ? "#33d9b2" : "#218c74"
                }

                onClicked: {
                    if(timeControl.isRoundActive){
                        serverAPI.slotCancelAdmonition(ServerAPI.BLUE);
                    }
                }
            }

            Button {
                id: blueWarningUndo
                width: parent.width
                height: width
                contentItem: Text {
                    color: "#ffffff"
                    text: "Отменить\nКамчун"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                anchors.topMargin: 3
                anchors.top: blueRemarkUndo.bottom
                background: Rectangle {
                    color: blueWarningUndo.hovered ? "#33d9b2" : "#218c74"
                }


                onClicked: {
                    if(timeControl.isRoundActive){
                        serverAPI.slotCancelWarning(ServerAPI.BLUE);
                    }
                }
            }
        }
    }
}

/*##^## Designer {
    D{i:23;anchors_x:1}
}
 ##^##*/
