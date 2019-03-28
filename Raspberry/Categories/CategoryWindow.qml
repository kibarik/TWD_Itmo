import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Window 2.0

Window {
    id: mainWindow
    width: 320
    height: 480
    flags: Qt.FramelessWindowHint // Отключаем обрамление окна

    signal signalExit
    signal getCategory

    ListView {
        id: listView
        width: 320
        height: 430
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
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
    }

    Button {
        id: back
        width: 320
        height: 50
        text: qsTr("> Назад <")
        anchors.bottom: parent.bottom
        anchors.top: listView.bottom

        onClicked: {
            mainWindow.signalExit()
        }
    }



}

