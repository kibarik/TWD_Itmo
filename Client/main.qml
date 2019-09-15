import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Window 2.12

import ServerAPI 1.0

import "Sparring/"
import "OutMonitor/"
import "Tul/"
import "Categories/"
import "Share/"
import "lib_tcp/"

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
//    maximumHeight: 480
//    maximumWidth: 320

    //flags: Qt.FramelessWindowHint // Отключаем обрамление окна

    property string redParticipant: "Красный";
    property string blueParticipant: "Синий";
    property string nextParticipant1;
    property string nextParticipant2;
    property string nowCategoryName: "Выберите категорию";



/*-----------------------MyTCP server--------------------------------*/
    //Данная структура объявлена в main.cpp
    //обеспечивает ввод/вывод из QML в C++
    ServerAPI {
        id: serverAPI
        qRedAdmonition: 0

//        onAdmonitionChanged: {
//            console.log("Admonition signal: "+qRedAdmonition +" blue->"+qBlueAdmonition)
//        }

        onSignalAdmonition: {
            console.log("Admonition signal: "+qRedAdmonition +" blue->"+qBlueAdmonition)
        }

        onSignalDisqualification: {
            console.log("Diskvalification")
        }

        onSignalJudgeNumError: {
            console.log("Client disconnected")
        }

        onSignalScoreUpdate: {
            console.log("Score updated: ")
        }

        onSignalWarning: {
            console.log(qRedWarning + " " +qBlueWarning)
        }

        onTimeChanged: {
            console.log("Time: ", qRoundTime-qRoundTimeElapsed)
        }

        onSignalTimerEvent: {
            console.log("Time: ", qRoundTime-qRoundTimeElapsed)
        }

        onSignalTimeOver: {
            console.log("Time over!")
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
                        console.log('red Remark plus');
                        serverAPI.slotAdmonition(0); //добавления чуя на систему счета, waning - камчун, admonition - чуй
                        console.log(serverAPI.qRedAdmonition)
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
                        console.log('red warning plus');
                        serverAPI.slotWarning(0) //добавления камчуна на систему счета, waning - камчун, admonition - чуй
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
                        console.log('red Remark undo');
                        serverAPI.slotCancelAdmonition(0); //отменить чуй красному
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
                        console.log('red warning minus');
                        serverAPI.slotCancelWarning(0); //добавить камчун красному
                    }
                }
        }
    }




    Tul {
        id: tulWindow
        anchors.horizontalCenter: parent.horizontalCenter
        visible: true
        onCategoryShow: {
            categoryWindow.show()
            mainQmlWindow.opacity = 0.0
        }
    }

    TimeControl {
        width: 320
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: tulWindow.bottom

        //все действия с serverAPI выполнены в Share/TimeControl.qml
        onStarted: {
            console.log('started');
        }

        onStoped: {
            console.log('stoped');
        }

        onPaused: {
            console.log('paused');
        }
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
        visible: false
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
        visible: true
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
        }

        onMonitorSetSparring: { //переключение монитора на спарринг
            console.log("Monitor set SPARRING")
            monitorTul.close()
            monitorSparring.show()

            sparringWindow.visible = true
            tulWindow.visible = false
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
                    console.log("Blue admonition added");
                    serverAPI.slotAdmonition(1);
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
                    console.log("Blue warning added");
                    serverAPI.slotWarning(1);
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
                    console.log("Cancel admonition blue")
                    serverAPI.slotCancelAdmonition(1);
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
                    console.log("Cancel warning blue")
                    serverAPI.slotCancelWarning(1);
                }
            }
        }
    }
}

















/*##^## Designer {
    D{i:23;anchors_x:1}
}
 ##^##*/
