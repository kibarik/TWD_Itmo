import QtQuick 2.4
import QtQuick.Controls 2.2

Rectangle {
    id: rectangle
    width: 320
    height: 480
    color: "#424141"
    border.color: "#ffffff"

    Button {
        id: categorybButton
        width: 320
        height: 80
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

    Now_after {
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

    Sparring_attentions_and_judjes {
        width: 320
        height: 80
        anchors.top: points.bottom
        anchors.topMargin: 0
        visible: true
        id: j_info
    }


}































































