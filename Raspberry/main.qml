import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 320
    height: 480
    color: "#222121"
    title: qsTr("Scroll")

    Button {
        id: button
        x: 0
        y: 0
        width: 324
        height: 82
        text: qsTr("Мальчики Личные Спарринг\nот 14 до 17 лет\n10гуп-3дан 70-75 кг")
        autoRepeat: false
        autoExclusive: false
        checked: false
        font.family: "Verdana"
        spacing: 5
        checkable: false
        highlighted: false
        flat: false
        anchors.top: parent.top
        anchors.topMargin: -8
        display: AbstractButton.TextBesideIcon
        transformOrigin: Item.Top

        ColorAnimation {
            from: "red"
            to: "black"
            duration: 200
        }
    }

    Grid {
        id: sportsments
        width: 320
        height: 200
        anchors.top: button.bottom
        anchors.topMargin: 0

        Row {
            id: now_block
            height: 100
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0

            Column {
                id: n_lbl
                x: 0
                width: 20
                height: 100
                anchors.left: parent.left
                anchors.leftMargin: 0

                Rectangle {
                    id: rectangle
                    color: "#3a8817"
                    border.width: 0
                    anchors.fill: parent

                    Label {
                        id: label
                        x: 0
                        y: 0
                        width: 15
                        color: "#ffffff"
                        text: qsTr("Сейчас")
                        lineHeight: 1
                        antialiasing: true
                        smooth: false
                        enabled: false
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        textFormat: Text.RichText
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        rotation: 90
                    }
                }

            }

            Column {
                id: now_fighters
                height: 100
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: n_lbl.right
                anchors.leftMargin: 0

                Rectangle {
                    id: rectangle2
                    width: 300
                    height: 50
                    color: "#cd0000"
                    anchors.right: parent.right
                    anchors.rightMargin: 0

                    ItemDelegate {
                        id: first
                        x: 20
                        y: 0
                        width: 300
                        height: 50
                        text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                        hoverEnabled: false
                        rightPadding: 8
                        leftPadding: 8
                        font.family: "Times New Roman"
                        spacing: 10
                        display: AbstractButton.TextOnly
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        transformOrigin: Item.Right
                    }
                }

                Rectangle {
                    id: rectangle3
                    x: 0
                    width: 300
                    height: 50
                    color: "#000ac4"
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 0

                    ItemDelegate {
                        id: second
                        x: 5
                        y: 50
                        width: 300
                        height: 50
                        text: qsTr("Корсунов Дмитрий\nВыборг 'Фанат'")
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 0
                        font.family: "Times New Roman"
                        spacing: 10
                        hoverEnabled: false
                        display: AbstractButton.TextOnly
                        anchors.right: parent.right
                        transformOrigin: Item.Right
                        rightPadding: 8
                        anchors.rightMargin: 0
                        leftPadding: 8
                    }
                }
            }
        }

        Row {
            id: next_block
            height: 100
            anchors.top: now_block.bottom
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            Column {
                id: a_lbl1
                x: 0
                width: 20
                height: 100
                anchors.left: parent.left
                anchors.leftMargin: 0
                Rectangle {
                    id: rectangle1
                    color: "#bd9818"
                    border.width: 0
                    Label {
                        id: label1
                        x: 0
                        y: 0
                        width: 15
                        color: "#ffffff"
                        text: qsTr("Готовятся")
                        rotation: 90
                        smooth: false
                        anchors.topMargin: 0
                        textFormat: Text.RichText
                        anchors.bottom: parent.bottom
                        antialiasing: true
                        enabled: false
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        lineHeight: 1
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.bottomMargin: 0
                        anchors.top: parent.top
                    }
                    anchors.fill: parent
                }
            }

            Column {
                id: a_fighters
                height: 100
                anchors.left: a_lbl1.right
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                Rectangle {
                    id: rectangle4
                    width: 300
                    height: 50
                    color: "#444444"
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    ItemDelegate {
                        id: ready1
                        x: 5
                        y: 50
                        width: 300
                        height: 50
                        text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                        font.underline: true
                        font.family: "Times New Roman"
                        spacing: 10
                        hoverEnabled: false
                        display: AbstractButton.TextOnly
                        anchors.right: parent.right
                        rightPadding: 8
                        transformOrigin: Item.Right
                        anchors.bottom: parent.bottom
                        anchors.rightMargin: 0
                        anchors.bottomMargin: 0
                        leftPadding: 8
                    }
                }

                Rectangle {
                    id: rectangle5
                    x: 0
                    width: 300
                    height: 50
                    color: "#393939"
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    ItemDelegate {
                        id: ready2
                        x: 5
                        y: 50
                        width: 300
                        height: 50
                        text: qsTr("Кто-то С ОченьДлиннымИменем\nВыборг 'Фанат'")
                        font.underline: true
                        font.family: "Times New Roman"
                        spacing: 10
                        hoverEnabled: false
                        display: AbstractButton.TextOnly
                        anchors.right: parent.right
                        rightPadding: 8
                        transformOrigin: Item.Right
                        anchors.bottom: parent.bottom
                        anchors.rightMargin: 0
                        anchors.bottomMargin: 0
                        leftPadding: 8
                    }
                }
            }
        }
    }

    Grid {
        id: judjes
        x: 0
        y: 0
        width: 320
        height: 200
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        transformOrigin: Item.Bottom

        Row {
            id: time
            height: 50
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            Text {
                id: min
                width: 200
                color: "#ffffff"
                text: qsTr("02:00")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.topMargin: 0
                font.pixelSize: 30
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
            }

            Text {
                id: rounds
                color: "#d2d2d2"
                text: qsTr("1")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Times New Roman"
                anchors.top: round.bottom
                anchors.topMargin: 0
                anchors.left: min.right
                anchors.leftMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                font.pixelSize: 30
            }

            Label {
                id: round
                text: qsTr("Раунд")
                lineHeight: 1.1
                topPadding: 0
                bottomPadding: 0
                rightPadding: 0
                leftPadding: 40
                padding: 1
                anchors.left: min.right
                anchors.leftMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
            }
        }

        Row {
            id: points
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: time.bottom
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Rectangle {
                id: red
                width: 125
                height: 2
                color: "#cd0000"
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0

                Text {
                    id: element
                    color: "#ffffff"
                    text: qsTr("0")
                    textFormat: Text.RichText
                    fontSizeMode: Text.FixedSize
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.pixelSize: 100
                }
            }

            Rectangle {
                id: blue
                width: 125
                height: 2
                color: "#0b00cc"
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                Text {
                    id: element1
                    color: "#ffffff"
                    text: qsTr("0")
                    textFormat: Text.RichText
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 100
                    fontSizeMode: Text.FixedSize
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                }
            }

            Item {
                id: element2
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.right: blue.left
                anchors.rightMargin: 0
                anchors.left: red.right
                anchors.leftMargin: 0

                Rectangle {
                    id: rectangle6
                    height: 75
                    color: "#a4a4a4"
                    anchors.right: parent.right
                    anchors.left: parent.left
                    anchors.top: parent.top

                    Text {
                        id: element3
                        text: qsTr("Чуй")
                        anchors.right: parent.right
                        anchors.left: parent.left
                        anchors.top: parent.top
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 14
                    }

                    Text {
                        id: element4
                        text: qsTr("0")
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.top: element3.bottom
                        anchors.topMargin: 0
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 0
                        font.pixelSize: 12
                    }
                }

                Rectangle {
                    id: rectangle7
                    color: "#2a2928"
                    anchors.top: rectangle6.bottom
                    anchors.topMargin: 0
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left

                    Text {
                        id: element5
                        text: qsTr("Камчун")
                        anchors.top: parent.top
                        anchors.left: parent.left
                        horizontalAlignment: Text.AlignHCenter
                        anchors.right: parent.right
                        font.pixelSize: 14
                        verticalAlignment: Text.AlignVCenter
                    }

                    Text {
                        id: element6
                        x: -8
                        text: qsTr("0")
                        anchors.top: element5.bottom
                        anchors.left: parent.left
                        horizontalAlignment: Text.AlignHCenter
                        anchors.leftMargin: 0
                        anchors.topMargin: -20
                        anchors.right: parent.right
                        font.pixelSize: 12
                        anchors.bottom: parent.bottom
                        anchors.rightMargin: 0
                        verticalAlignment: Text.AlignVCenter
                        anchors.bottomMargin: 0
                    }
                }
            }
        }
    }
}



































/*##^## Designer {
    D{i:1;anchors_y:"-8"}D{i:6;anchors_height:200;anchors_width:200}D{i:8;anchors_width:300;anchors_x:0}
D{i:4;anchors_height:400;anchors_width:200}D{i:15;anchors_height:200;anchors_width:200}
D{i:17;anchors_width:300;anchors_x:0}D{i:13;anchors_height:400;anchors_width:200}
D{i:24;anchors_x:17;anchors_y:298}D{i:23;anchors_width:320}D{i:35;anchors_x:0;anchors_y:0}
D{i:33;anchors_height:75;anchors_width:200}D{i:38;anchors_x:0;anchors_y:"-8"}D{i:36;anchors_height:75;anchors_width:200}
D{i:32;anchors_height:200;anchors_width:200}D{i:27;anchors_height:0;anchors_width:320;anchors_x:0}
}
 ##^##*/
