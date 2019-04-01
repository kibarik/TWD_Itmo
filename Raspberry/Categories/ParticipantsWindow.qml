import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0


Window {
    id: mainWindow
    width: 320
    height: 480

    signal signalExit


    Button {
        id: button
        height: 50
        text: qsTr(">>Назад<<")
        anchors.right: parent.right
        anchors.left: parent.left

        onClicked: {
            mainWindow.signalExit()
        }
    }
}


/*##^## Designer {
    D{i:9;anchors_width:320;anchors_x:0}
}
 ##^##*/
