import QtQuick 2.0

    Grid {
        id: controlButtons
        width: parent.width
        height: parent.height
        rows: 1
        columns: 3
        anchors.bottom: parent.bottom

        Rectangle {
            id: start
            width: parent.width/3
            height: parent.height
            color: "#27ae60"
            clip: false

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
        }

        Rectangle {
            id: stop
            width: parent.width/3
            height: parent.height
            color: "#e74c3c"
            clip: false

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
        }

        Rectangle {
            id: level
            width: parent.width/3
            height: parent.height
            color: "#f39c12"
            clip: false

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
                text: qsTr("Суд. уровень")
                horizontalAlignment: Text.AlignHCenter
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                font.pixelSize: 12
            }
        }
    }
