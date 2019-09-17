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

        property bool isRunning: true;

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
                if(isRunning){
                    element2.text = "Пауза"
                    serverAPI.slotTimerPause()
                    controlButtons.isRunning = false;
                }
                else {
                    element2.text = "Старт"
                    serverAPI.slotTimerStart()
                    controlButtons.isRunning = true;
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
                controlButtons.stoped() //получаем в main.qml
                serverAPI.slotTimerStop()
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
                text: "1"
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
                //сигнал для старта раунда или смены уровня туля
//                mainQmlWindow.server.slotTimerPause()
//                controlButtons.paused()
            }
        }
    }
