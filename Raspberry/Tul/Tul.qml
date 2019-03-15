import QtQuick 2.4
import QtQuick.Controls 2.2
import "../"


Rectangle {
    id: rectangle
    width: 320
    height: 480
    color: "#424141"
    border.color: "#ffffff"

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
        flat: false
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Top
    }

    PairDisplay {
        id: now_after
        anchors.top: categorybButton.bottom
        anchors.topMargin: 0
        height: 200
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
            color: "Green"
            clip: false

            Image {
                id: image
                anchors.rightMargin: 5
                anchors.leftMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5
                anchors.fill: parent
                sourceSize.height: 50
                sourceSize.width: 50
                source: "../Img/start.png"
                fillMode: Image.PreserveAspectFit
            }
        }

        Rectangle {
            id: stop
            width: parent.width/3
            height: parent.height
            color: "Red"
            clip: false

            Image {
                id: image1
                source: "../Img/stop.png"
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
            }
        }

        Rectangle {
            id: level
            width: parent.width/3
            height: parent.height
            color: "Yellow"
            clip: false

            Text {
                id: element
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
    D{i:4;anchors_height:100;anchors_width:320;anchors_x:0;anchors_y:331}D{i:7;anchors_height:100;anchors_width:100}
D{i:9;anchors_height:100;anchors_width:100}D{i:12;anchors_x:213;anchors_y:0}
}
 ##^##*/
