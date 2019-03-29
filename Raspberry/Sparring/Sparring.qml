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
        id: button
        width: 320
        height: 70
        text: qsTr("Мальчики Личные Спарринг\nот 14 до 17 лет\n10гуп-3дан 70-75 кг")
        anchors.top: parent.top
        anchors.topMargin: 0
        display: AbstractButton.TextOnly

        onClicked: { //нажимаем на кнопку категорий
            sparringWindow.categoryShow()
        }

    }

    PairDisplay {
        id: now_after
        height: 200
        anchors.top: button.bottom
        width: 320
        visible: true
    }

    Time{
        id: time
        height: 46
        anchors.top: now_after.bottom
        anchors.topMargin: 0

    }

    PointsTable {
        id: points
        height: 70
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
