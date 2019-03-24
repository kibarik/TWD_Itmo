import QtQuick 2.5
import QtQuick.Window 2.0


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
Item {
    id: name
    width: Screen.desktopAvailableWidth
    height: 200
    //color: "#000"
    visible: true

    Grid {
        id: grid
        width: parent.width
        height: 200
        rows: 3
        columns: 6
        anchors.fill: parent


        Text {
            text: qsTr("Замечания")
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/6
            height: parent.height/3
            color: "#ffffff"
        }

        Text {
            text: qsTr("Предупреждения")
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/6
            height: parent.height/3
            color: "#ffffff"
        }

        Text {
            text: qsTr("I")
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/6
            height: parent.height/3
            color: "#ffffff"
        }

        Text {
            text: qsTr("II")
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/6
            height: parent.height/3
            color: "#ffffff"
        }

        Text {
            text: qsTr("III")
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/6
            height: parent.height/3
            color: "#ffffff"
        }
        Text {
            text: qsTr("IV")
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/6
            height: parent.height/3
            color: "#ffffff"
        }

        Rectangle {
            color: "Red"
            border.width: 0
            width: parent.width/6
            height: parent.height/3
            Text {

                id: chuiR
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Red"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: gamjR
                text: qsTr("0")
                font.family: "Noto Sans"
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }


        Rectangle {
            color: "Red"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j1r //1 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Red"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j2r //2 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Red"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j3r //3 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Red"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j4r //1 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }


        Rectangle {
            color: "Blue"
            border.width: 0
            width: parent.width/6
            height: parent.height/3
            Text {

                id: chuib
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Blue"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: gamjB
                text: qsTr("0")
                font.family: "Noto Sans"
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }


        Rectangle {
            color: "Blue"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j1b //1 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Blue"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j2b //2 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Blue"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j3b //3 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }

        Rectangle {
            color: "Blue"
            width: parent.width/6
            height: parent.height/3

            Text {
                id: j4b //1 судья баллы красному
                text: qsTr("0")
                anchors.fill: parent
                fontSizeMode: Text.Fit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
        }


    }
}
