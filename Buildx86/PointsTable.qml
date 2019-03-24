import QtQuick 2.0


/*
    Из файла логику пультов cpp при присуждении баллов получаем сигналы
    signalRedPlus() signalBluePlus() и т.п.

    id: redPoints прописываем слота приема сигнала.
    Сигнал отдает баллы спортсмена, слот записывает в redPoints.texе


    QObject::connect(qml, SIGNAL(transmitOldText(QString)),
                     &ASD, SLOT(getOldText(QString)));


    https://habr.com/ru/post/171341/
    https://habr.com/ru/post/138837/

*/

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
        color: "#c0392b"
        transformOrigin: Item.Right
        Text {
            id: redPoints
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
    width: 160
    height: 70
    Rectangle {
        id: blue1
        width: 160
        height: 70
        color: "#2980b9"
        border.width: 0
        transformOrigin: Item.Left
        Text {
            id: bluePoints
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
}
