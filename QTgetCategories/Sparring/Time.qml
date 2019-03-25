import QtQuick 2.0
import QtQuick.Controls 2.2

/*
    на монитор выводится только общее количество, сколько судей за красного и за синего
    получив сигнал, слот направляет его в соответствующую колонку
    имена также, как в PairDisplay.qml


    QObject::connect(qml, SIGNAL(transmitOldText(QString)),
                     &ASD, SLOT(getOldText(QString)));

    https://habr.com/ru/post/171341/
    https://habr.com/ru/post/138837/
*/

Row {
id: time
    x: 0
    y: 0
    width: 320
    height: 50
    anchors.top: after.bottom
    anchors.topMargin: 0

    Column {
        id: row
        width: 200
        height: 50
        Text {
            id: min
            width: 200
            color: "#ffffff"
            text: qsTr("02:00")
            anchors.topMargin: 0
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 30
            anchors.leftMargin: 0
            horizontalAlignment: Text.AlignHCenter
            anchors.bottomMargin: 0
        }
    }

    Column {
        id: row1
        x: 200
        width: 120
        height: 50
        Text {
            id: rounds
            color: "#d2d2d2"
            text: qsTr("1")
            font.family: "Times New Roman"
            anchors.bottom: parent.bottom
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            anchors.bottomMargin: 0
        }

        Label {
            id: round
            text: qsTr("Раунд")
            rightPadding: 0
            topPadding: 0
            anchors.left: parent.left
            bottomPadding: 0
            anchors.right: parent.right
            lineHeight: 1.1
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            leftPadding: 40
            padding: 1
        }
    }
}



/*##^## Designer {
    D{i:0;invisible:true}
}
 ##^##*/
