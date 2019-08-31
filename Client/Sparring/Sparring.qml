import QtQuick 2.4
import QtQuick.Controls 2.2
import "../Share"


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
            font.family: "Times New Roman"
            anchors.top: parent.top

            contentItem: Text {
                text: mainQmlWindow.nowCategoryName
                font.pointSize: 10
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight

            }
            background: Rectangle {
                implicitWidth: button.width
                implicitHeight: button.height
                color: "#ecf0f1"
            }

        onClicked: { //нажимаем на кнопку категорий
            sparringWindow.categoryShow()
            categoryWindow.categoryShow()
        }

    }

    PairDisplay {
        id: pairDisplay
        height: 200
        anchors.top: button.bottom
        width: 320
        visible: true
    }

    Time{
        id: time
        height: 46
        anchors.top: pairDisplay.bottom
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




