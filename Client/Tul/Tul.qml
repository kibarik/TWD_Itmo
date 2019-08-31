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
        height: 60
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

        onClicked: {
            tulWindow.categoryShow()
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

    PointsTable {
        id: points
        height: 150
        anchors.top: pairDisplay.bottom
    }

    TulInfo {
        visible: true
        id: j_info
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: points.bottom
    }
}






























































/*##^## Designer {
    D{i:4;anchors_height:100;anchors_width:320;anchors_x:0;anchors_y:331}D{i:6;anchors_width:320;anchors_x:0}
}
 ##^##*/
