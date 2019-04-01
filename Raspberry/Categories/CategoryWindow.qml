import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Window 2.5

Window {
    id: mainWindow
    width: 320
    height: 480
    flags: Qt.FramelessWindowHint // Отключаем обрамление окна

    signal signalExit
    signal openParticipants
    signal categoryShow

    property var categoryNames: categoryAPI.setCategoriesNames()

    function showCategories() {
        if (listModel.rowCount()=== 0){
            for(var i = 0; i < categoryNames.length; i ++){
                listModel.append({categoryName:categoryNames[i]})
                console.log(i, ">", categoryNames[i])
            }
        }
    }

   ListView {
        id: listView
        width: 320
        height: 380
        anchors.top: getcateg.bottom

        delegate: Item {
            width: parent.width
            height: 50
            Row {
                id: row1
                spacing: 1
                width: 320
                height: 50
                Button {
                    id: control
                    text: categoryName
                    contentItem: Text {
                        text: control.text
                        font: control.font
                        opacity: enabled ? 1.0 : 0.3
                        color: control.down ? "#22313f" : "#696969"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight

                    }
                    background: Rectangle {
                        implicitWidth: 320
                        implicitHeight: 50
                        opacity: enabled ? 1 : 0.3
                        border.color: control.down ? "#FA8072" : "#696969"
                        border.width: 1
                    }

                    onClicked: {
                        categoryWindow.openParticipants();
                    }
                }
            }
        }

        model: ListModel {
            id: listModel
        }
    }

    Button {
        id: back
        x: 0
        width: 320
        height: 50
        text: qsTr("> Назад <")
        anchors.bottom: parent.bottom

        onClicked: {
            mainWindow.signalExit()
        }
    }



}

