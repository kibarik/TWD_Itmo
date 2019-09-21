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

Item {
    id: timeInside
    x: 0
    y: 0
    width: 350
    height: 50
    anchors.top: after.bottom

    //заменить цифры буквами на сигнал onExtraRoundSetted от сервера
    property alias extraRoundText: rounds.text;

    Button {
        id: rounds
        width: parent.width/2
        height: 50
        anchors.top: roundText.bottom
        anchors.left: timeText.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        contentItem: Text {
            color: "#d2d2d2"
            text: mainQmlWindow.server.qRound+" : "+ mainQmlWindow.server.qRoundCount
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
        }
        background: Rectangle {
            color: "#424141" //из sparring.qml
        }

        onClicked: {
            mainQmlWindow.server.qRound++
        }
    }

    Text {
        id: timeText
        width: parent.width/2
        color: "#ffffff"
        text: mainQmlWindow.server.qMinutesNow+":"+mainQmlWindow.server.qSecondsNow
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

    Label {
        id: roundText
        color: "#ffffff"
        text: qsTr("Раунд")
        fontSizeMode: Text.HorizontalFit
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignHCenter
        anchors.left: rounds.right
        topPadding: 0
        bottomPadding: 0
        anchors.right: rounds.left
        lineHeight: 1.1
        padding: 10
    }
}


























