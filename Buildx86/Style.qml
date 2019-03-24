// Style.qml
import QtQuick 2.0
import QtQuick.Controls 2.5
pragma Singleton

Button {
    id: control
    text: qsTr("Button")
    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#FA8072" : "#696969"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight

    }
    background: Rectangle {
        implicitWidth: 90
        implicitHeight: 30
        opacity: enabled ? 1 : 0.3
        border.color: control.down ? "#FA8072" : "#696969"
        border.width: 1
        radius: 4
    }
}
