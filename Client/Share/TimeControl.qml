import QtQuick 2.0
import QtQuick.Controls 2.0

    Grid {
        id: controlButtons
        width: parent.width
        height: parent.height
        rows: 1
        columns: 3
        anchors.bottom: parent.bottom

        property bool isNewRound: true;
        property bool isRoundActive: false;
        property alias startButtonText: start.buttonText; //Изменяется в main.qml при завершении раунда

        Button {
            id: start
            width: parent.width/3
            height: parent.height
            clip: false
            property alias buttonText: element2.text;

            background: Rectangle {
                implicitWidth: parent.width
                implicitHeight: parent.height
                opacity: enabled ? 1 : 0.3
                color: "#27ae60"
                border.width: 1
            }

            Text {
                id: element2
                color: "#ffffff"
                text: qsTr("Старт")
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 17
            }

            onClicked: {
                if(controlButtons.isNewRound && !controlButtons.isRoundActive){
                    //Запуск для нового раунда, время сбрасывается после нажатия

                    serverAPI.slotTimerStart()
                    element2.text = "Пауза" //Было 'Старт'.
                    controlButtons.isNewRound = false;
                    controlButtons.isRoundActive = true;
                    console.log(1)
                }
                else if (!controlButtons.isNewRound && controlButtons.isRoundActive) {
                    //Постановка на паузу во время раунда, время не сбрасывается

                    element2.text = "Продолжить" //Было 'Пауза'
                    serverAPI.slotTimerPause() //включаем паузу
                    controlButtons.isRoundActive = false;
                    controlButtons.isNewRound = false;
                    console.log(2)
                }
                else {
                    //Отменяем паузу, продолжаем отсчет времени

                    element2.text = "Пауза" //Было 'продолжить'
                    serverAPI.slotTimerPause()
                    controlButtons.isRoundActive = true;
                    controlButtons.isNewRound = false;
                    console.log(3)
                }

            }
        }

        Button {
            id: stop
            width: parent.width/3
            height: parent.height
            clip: false

            background: Rectangle {
                implicitWidth: parent.width
                implicitHeight: parent.height
                opacity: enabled ? 1 : 0.3
                color: "#e74c3c"
                border.width: 1
            }

            Text {
                id: element3
                color: "#ffffff"
                text: qsTr("Сброс")
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit
                anchors.fill: parent
                font.pixelSize: 17
                verticalAlignment: Text.AlignVCenter
            }

            onClicked: {
                controlButtons.isNewRound = true;
                controlButtons.isRoundActive = false;
                serverAPI.qRoundCount = 1;
                mainQmlWindow.roundText = serverAPI.qRound + " : " + serverAPI.qRoundCount;
                element2.text = "Старт";
                mainQmlWindow.isDoctorRound = false;
                mainQmlWindow.isExtraRound = false;

                serverAPI.slotTimerStop();
                serverAPI.slotReset();
                serverAPI.timeChanged();
                serverAPI.admonitionChanged();
                serverAPI.warningChanged();
            }
        }

        Button {
            id: level
            width: parent.width/3
            height: parent.height

            clip: false

            background: Rectangle {
                implicitWidth: parent.width
                implicitHeight: parent.height
                opacity: enabled ? 1 : 0.3
                color: "#f39c12"
                border.width: 1
            }

            Text {
                id: element
                color: "#ffffff"
                text: "Вызов врача"
                font.family: "Tahoma"
                fontSizeMode: Text.Fit
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 17
            }

//            Text {
//                id: element1
//                color: "#ffffff"
//                text: qsTr("Вызов врача")
//                horizontalAlignment: Text.AlignHCenter
//                anchors.right: parent.right
//                anchors.left: parent.left
//                anchors.leftMargin: 0
//                anchors.top: parent.top
//                anchors.topMargin: 0
//                font.pixelSize: 17
//            }

            onClicked: {
                controlButtons.isNewRound = false;
                controlButtons.isRoundActive = false;

                mainQmlWindow.server.doctorSignal();
            }
        }
    }
