import QtQuick 2.0
import QtQuick.Controls 2.0

    Grid {
        id: controlButtons
        width: parent.width
        height: parent.height
        rows: 1
        columns: 3
        anchors.bottom: parent.bottom

        signal started();
        signal stoped();
        signal paused();

        property bool isPauseActive: false;
        property bool isNewRound: true;

        Button {
            id: start
            width: parent.width/3
            height: parent.height
            clip: false

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
                if(controlButtons.isNewRound && !controlButtons.isPauseActive){
                    serverAPI.slotTimerStart()
                    element2.text = "Пауза" //Было 'Старт'.
//                    controlButtons.isNewRound = false;
                    controlButtons.isPauseActive = true;
                    console.log(1)
                }
                else if (!controlButtons.isNewRound && controlButtons.isPauseActive) {
                    serverAPI.slotTimerPause()
                    element2.text = "Старт" //Было 'Пауза'
                    controlButtons.isPauseActive = false;
                    console.log(2)
                }
                else { //в режиме паузы, возвращаем в старт
                    serverAPI.slotTimerPause()
                    element2.text="Старт"
                    controlButtons.isPauseActive = false;
                    console.log(3)
                }

                controlButtons.started() //получаем в main.qml
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
                text: qsTr("Стоп")
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit
                anchors.fill: parent
                font.pixelSize: 17
                verticalAlignment: Text.AlignVCenter
            }

            onClicked: {
                serverAPI.slotTimerStop()
                serverAPI.slotReset();
                serverAPI.timeChanged();
                controlButtons.isNewRound = true;
                controlButtons.isPauseActive = false;
                serverAPI.admonitionChanged();
                serverAPI.warningChanged();
                element2.text = "Старт";
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
                text: mainQmlWindow.server.qRound
                font.family: "Tahoma"
                fontSizeMode: Text.Fit
                anchors.top: element1.bottom
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 29
            }

            Text {
                id: element1
                color: "#ffffff"
                text: qsTr("Следующий раунд")
                horizontalAlignment: Text.AlignHCenter
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                font.pixelSize: 12
            }

            onClicked: {
                mainQmlWindow.server.qRound++;

            }
        }
    }
