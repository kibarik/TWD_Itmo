import QtQuick 2.0
import QtQuick.Window 2.12

Window {
    GridView {
        id: gridView
        width: parent.width
        height: parent.height
        cellWidth: 70
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        cellHeight: 70
        delegate: Item {
            x: 5
            height: 50
            Column {
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    x: 5
                    text: name
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.bold: true
                }
                spacing: 5
            }
        }
    }

}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
