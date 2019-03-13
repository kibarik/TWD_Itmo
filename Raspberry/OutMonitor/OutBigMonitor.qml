import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    id: window
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight

    Grid {
        id: grid
        width: parent.width
        anchors.top: row1.bottom
        rows: 2
        columns: 2

        Rectangle {
            width: parent.width/2
            height: parent.height/6
            color: "Red"
            Text {
                id: redName
                color: "#ffffff"
                text: qsTr("Ишманов Алексей Юрьевич\n'Фанат' Ленинградская область")
                anchors.fill: parent
            }
        }

        Rectangle {
            x: 0
            width: parent.width/2
            height: parent.height/6
            color: "Blue"
            Text {
                id: blueName
                color: "#ffffff"
                text: qsTr("Ишманов Алексей Юрьевич\n'Фанат' Ленинградская область")
                anchors.fill: parent
            }
        }
        Rectangle {
            id: rectangle2
            width: parent.height/2
            height: 200
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle3
            x: 400
            y: 360
            width: 200
            height: 200
            color: "#ffffff"
        }
    }

    Row {
        id: row1
        width: parent.width
        height: parent.height/8
        anchors.top: parent.top
        anchors.topMargin: 0

        Rectangle {
            color: "#000000"
            anchors.fill: parent
        }
    }



}









