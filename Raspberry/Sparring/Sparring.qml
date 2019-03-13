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

    Time{
        id: time
        height: 50
        anchors.top: now_after.bottom
        anchors.topMargin: 0

    }

    PointsTable {
        id: points
        anchors.top: time.bottom
        anchors.topMargin: 0
    }

    SparringInfo {
        width: 320
        height: 80
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: points.bottom
        anchors.topMargin: 0
        visible: true
        id: j_info
    }


}
































































/*##^## Designer {
    D{i:5;anchors_height:80}
}
 ##^##*/
