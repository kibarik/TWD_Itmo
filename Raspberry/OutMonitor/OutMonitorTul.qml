import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    id: window
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    visible: true

    Grid {
        id: grid
        height: 100
        anchors.top: row1.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.topMargin: 0
        rows: 1
        columns: 2

        Rectangle {
            width: parent.width/2
            height: parent.height
            color: "Red"
            border.width: 4

            Text {
                id: blueName1
                color: "#ffffff"
                text: qsTr("Корчинский Дмитрий Андреевич")
                wrapMode: Text.WordWrap
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.leftMargin: 15
                anchors.fill: parent
                font.pixelSize: parent.height/3
                textFormat: Text.PlainText
                font.family: "Tahoma"
            }
        }

        Rectangle {
            width: parent.width/2
            height: parent.height
            color: "Blue"
            border.width: 4
            Text {
                id: blueName
                color: "#ffffff"
                text: qsTr("Ишманов Алексей Юрьевич \т 'Фанат' Ленинградская область")
                wrapMode: Text.WordWrap
                font.pixelSize: parent.height/3
                font.family: "Tahoma"
                anchors.leftMargin: 15
                textFormat: Text.PlainText
                fontSizeMode: Text.Fit
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
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
            border.width: 2
            anchors.fill: parent

            Text {
                id: element
                height: 100
                color: "#ffffff"
                text: qsTr("Туль Мальчики 14-17 лет 3 гуп - 1 дан")
                font.family: "Verdana"
                font.pixelSize: parent.height/3
                fontSizeMode: Text.Fit
                font.capitalization: Font.AllUppercase
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
    }

    Row {
        id: row
        width: parent.width
        height: width
        anchors.top: grid.bottom

        Rectangle {
            id: rectangle2
            width: parent.width/3
            height: width
            color: "#ff0000"
            Text {
                id: redPoints
                color: "#ffffff"
                text: qsTr("0")
                fontSizeMode: Text.VerticalFit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pixelSize: parent.width/2
                font.family: "Times New Roman"
            }
        }
        Rectangle {
            id: rectangle
            width: parent.width/3
            height: width
            color: "Grey"

            Text {
                id: otherPoint
                color: "#ffffff"
                text: qsTr("0")
                fontSizeMode: Text.VerticalFit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pixelSize: parent.width/2
                font.family: "Times New Roman"
            }
        }

        Rectangle {
            id: rectangle3
            width: parent.width/3
            height: width
            color: "#0000ff"
            Text {
                id: bluePoints
                color: "#ffffff"
                text: qsTr("0")
                fontSizeMode: Text.VerticalFit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pixelSize: parent.width/2
                font.family: "Times New Roman"
            }
        }
    }

}

