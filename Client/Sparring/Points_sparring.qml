import QtQuick 2.0

Row {
id: bigPoints
width: 320
height: 70
anchors.top: time.bottom
anchors.topMargin: 0

Column {
    id: column2
    width: 160
    height: 70
    Rectangle {
        id: red1
        width: 160
        height: 70
        color: "#cd0000"
        transformOrigin: Item.Right
        Text {
            id: element7
            color: "#ffffff"
            text: qsTr("0")
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 80
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.FixedSize
        }
    }
}

Column {
    id: column3
    x: 0
    width: 160
    height: 70
    Rectangle {
        id: blue1
        width: 160
        height: 70
        color: "#0b00cc"
        border.width: 0
        transformOrigin: Item.Left
        Text {
            id: element11
            color: "#ffffff"
            text: qsTr("0")
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 80
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.FixedSize
            textFormat: Text.RichText
        }
    }
}
}/*##^## Designer {
    D{i:0;invisible:true}
}
 ##^##*/
