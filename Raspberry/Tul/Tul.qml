import QtQuick 2.4
import QtQuick.Controls 2.2
import "../"


Rectangle {
    id: rectangle
    width: 320
    height: 480
    color: "#424141"
    border.color: "#ffffff"
    signal categoryShow

    Button {
        id: categorybButton
        width: 320
        height: 70
        text: qsTr("Мальчики Личные Спарринг\nот 14 до 17 лет\n10гуп-3дан 70-75 кг")
        autoRepeat: false
        autoExclusive: false
        checked: false
        font.family: "Verdana"
        spacing: 5
        checkable: false
        highlighted: false
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Top

        onClicked: {
			tulWindow.categoryShow()
			categoryWindow.categoryShow()
        }
    }

    PairDisplay {
        id: now_after
        height: 200
        anchors.top: categorybButton.bottom
        width: 320
        visible: true
    }

    PointsTable {
        id: points
        anchors.top: now_after.bottom
    }

    TulInfo {
        visible: true
        id: j_info
        x: 0
        width: 320
        anchors.bottom: controlButtons.top
        anchors.top: points.bottom
    }

    Grid {
        id: controlButtons
        width: 320
        height: 90
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


}








































































/*##^## Designer {
    D{i:4;anchors_height:100;anchors_width:320;anchors_x:0;anchors_y:331}D{i:7;anchors_x:107;anchors_y:0}
D{i:9;anchors_x:107;anchors_y:0}D{i:12;anchors_x:213;anchors_y:0}
}
 ##^##*/
