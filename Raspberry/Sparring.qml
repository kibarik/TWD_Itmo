import QtQuick 2.4
import QtQuick.Controls 2.5

Rectangle {
    id: rectangle
    width: 320
    height: 480
    color: "#424141"

    Button {
        id: categorybButton
        width: 320
        height: 80
        text: qsTr("Мальчики Личные Спарринг\nот 14 до 17 лет\n10гуп-3дан 70-75 кг")
        autoRepeat: false
        autoExclusive: false
        checked: false
        font.family: "Verdana"
        spacing: 5
        checkable: false
        highlighted: false
        flat: false
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Top
    }

    Row {
        id: now
        x: 0
        width: 320
        height: 100
        anchors.top: categorybButton.bottom
        anchors.topMargin: 0

        Column {
            id: n_lbl
            width: 20
            height: 100

            Rectangle {
                id: rectangle1
                color: "#3a8817"
                anchors.fill: parent
                border.width: 0

                Label {
                    id: label
                    color: "#ffffff"
                    text: qsTr("Сейчас")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    rotation: 90
                }
            }
        }

        Column {
            id: column
            width: 300
            height: 100

            Rectangle {
                id: rectangle2
                width: 300
                height: 50
                color: "#cd0000"

                ItemDelegate {
                    id: first
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    display: AbstractButton.TextOnly
                    padding: 5
                    font.pointSize: 10
                    font.family: "Times New Roman"
                }
            }

            Rectangle {
                id: rectangle3
                x: 0
                width: 300
                height: 50
                color: "#0043d2"
                anchors.bottom: parent.bottom

                ItemDelegate {
                    id: second
                    x: 0
                    y: 0
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    padding: 5
                    font.pointSize: 10
                    hoverEnabled: false
                    font.family: "Times New Roman"
                }
            }
        }
    }

    Row {
        id: after
        width: 320
        height: 100
        anchors.top: now.bottom
        Column {
            id: n_lbl1
            width: 20
            height: 100
            Rectangle {
                id: rectangle4
                color: "Orange"
                anchors.fill: parent
                Label {
                    id: label1
                    color: "#ffffff"
                    text: qsTr("Следующий")
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    rotation: 90
                }
                border.width: 0
            }
        }

        Column {
            id: column1
            width: 300
            height: 100


            Rectangle {
                id: rectangle5
                width: 300
                height: 50
                color: "Grey"


                ItemDelegate {
                    id: first1
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    font.family: "Times New Roman"
                    padding: 5
                    display: AbstractButton.TextOnly
                    font.pointSize: 10
                }
            }

            Rectangle {
                id: rectangle6
                x: 0
                width: 300
                height: 50
                color: "Grey"
                anchors.bottom: parent.bottom
                ItemDelegate {
                    id: second1
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    font.family: "Times New Roman"
                    hoverEnabled: false
                    padding: 5
                    font.pointSize: 10
                }
            }
        }
        anchors.topMargin: 0
    }

    Row {
        id: time
        x: 0
        y: 0
        width: 320
        height: 50

        Row {
            id: row
            width: 200
            height: 50

            Text {
                id: min
                width: 200
                color: "#ffffff"
                text: qsTr("02:00")
                horizontalAlignment: Text.AlignHCenter
                anchors.leftMargin: 0
                anchors.left: parent.left
                font.pixelSize: 30
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                verticalAlignment: Text.AlignVCenter
                anchors.top: parent.top
                anchors.topMargin: 0
            }
        }

        Row {
            id: row1
            x: 200
            width: 120
            height: 50

            Text {
                id: rounds
                color: "#d2d2d2"
                text: qsTr("1")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 30
                verticalAlignment: Text.AlignVCenter
                font.family: "Times New Roman"
            }

            Label {
                id: round
                text: qsTr("Раунд")
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                padding: 1
                lineHeight: 1.1
                leftPadding: 40
                rightPadding: 0
                topPadding: 0
                bottomPadding: 0
            }
        }
        anchors.top: after.bottom
        anchors.topMargin: 0
    }

    Row {
        id: result
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
                    horizontalAlignment: Text.AlignHCenter
                    fontSizeMode: Text.FixedSize
                    font.pixelSize: 80
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
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
                transformOrigin: Item.Left
                border.width: 0

                Text {
                    id: element11
                    color: "#ffffff"
                    text: qsTr("0")
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    fontSizeMode: Text.FixedSize
                    font.pixelSize: 80
                    textFormat: Text.RichText
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    Grid {
        id: grid
        width: 320
        height: 30
        rows: 2
        columns: 3
        anchors.top: result.bottom

        Rectangle {
            color: "Red"
            width: 50
            height: grid.height/2
            Text {
                id: redChui
                text: qsTr("0")
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }
        Rectangle {
            color: "Grey"
            width: 220
            height: grid.height/2
            Text {
                id: name
                text: qsTr("Замечание")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        Rectangle {
            color: "Blue"
            width:50
            height: grid.height/2
            Text {
                id: blueChui
                text: qsTr("0")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }

        Rectangle {
            width: 50
            height: 15
            color: "Red"
            Text {
                id: redGamj
                text: qsTr("0")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
        Rectangle {
            color: "Grey"
            width: 220
            height: grid.height/2
            Text {
                id: name2
                text: qsTr("Предупреждение")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
        Rectangle {
            color: "Blue"
            width:50
            height: grid.height/2
            Text {
                id: blueGamj
                text: qsTr("0")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }

    }

    Grid {
        id: judjes
        width: 320
        rows: 2
        columns: 4
        anchors.top: grid.bottom
        anchors.bottom: parent.bottom

        Text {
            id: text1
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("I")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text2
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("II")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text3
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("III")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text4
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("IV")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: j1 //judje1
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: j2
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: j3
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: j4
            color: "White"
            width: parent.width/4
            height: parent.height/2
            text: qsTr("0")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

    }



}















































































































/*##^## Designer {
    D{i:40;anchors_height:15;anchors_width:50}D{i:46;anchors_height:50}
}
 ##^##*/
