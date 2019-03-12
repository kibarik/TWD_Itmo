import QtQuick 2.4
import QtQuick.Controls 2.5

Rectangle {
    id: rectangle
    width: 320
    height: 480
    color: "#424141"
    border.color: "#ffffff"

    Now_after {
        anchors.top: categorybButton.bottom
        anchors.topMargin: 0
        height: 200
        width: 320
        visible: true
    }

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
                color: "#ffffff"
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
                color: "#ffffff"
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
                color: "#ffffff"
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
                color: "#ffffff"
                text: qsTr("0")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
            }
        }

    }

    Grid {
        id: judjesText
        width: 320
        height: 15
        rows: 1
        columns: 4
        anchors.top: grid.bottom

        Text {
            id: text1
            color: "White"
            width: parent.width/4
            text: qsTr("I")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text2
            color: "White"
            width: parent.width/4
            text: qsTr("II")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text3
            color: "White"
            width: parent.width/4
            text: qsTr("III")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text4
            color: "White"
            width: parent.width/4
            text: qsTr("IV")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Grid {
        id: points
        width: 320
        height: 50
        anchors.topMargin: 0
        rows: 1
        columns: 8
        anchors.top: judjesText.bottom
        anchors.bottom: parent.bottom


        Rectangle {
            id: j1l
            width: parent.width/8
            height: parent.height
            color: "Red"

            Text {
                id: j1R
                color: "#ffffff"
                text: qsTr("0")
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter

            }
        }

        Rectangle {
            id: j1r
            width: parent.width/8
            height: parent.height
            color: "Blue"

            Text {
                id: j1B
                color: "#ffffff"
                text: qsTr("0")
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter

            }


        }

        Rectangle {
            id: j2l
            width: parent.width/8
            height: parent.height
            color: "#ff3333"

            Text {
                id: j2R
                color: "#ffffff"
                text: qsTr("0")
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter

            }
        }

        Rectangle {
            id: j2r
            width: parent.width/8
            height: parent.height
            color: "#3632ff"

            Text {
                id: j2B
                color: "#ffffff"
                text: qsTr("0")
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter

            }
        }

            Rectangle {
                id: j3l
                width: parent.width/8
                height: parent.height
                color: "#ff3333"

                Text {
                    id: j3R
                    color: "#ffffff"
                    text: qsTr("0")
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter

                }

            }

            Rectangle {
                id: j3r
                width: parent.width/8
                height: parent.height
                color: "#3733ff"

                Text {
                    id: j3B
                    color: "#ffffff"
                    text: qsTr("0")
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter

                }
            }

            Rectangle {
                id: j4l
                width: parent.width/8
                height: parent.height
                color: "Red"

                Text {
                    id: j4R
                    color: "#ffffff"
                    text: qsTr("0")
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter

                }

            }

            Rectangle {
                id: j4r
                width: parent.width/8
                height: parent.height
                color: "Blue"

                Text {
                    id: j4B
                    color: "#ffffff"
                    text: qsTr("0")
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter

                }
            }


    }

}


















































/*##^## Designer {
    D{i:3;invisible:true}D{i:10;invisible:true}D{i:13;anchors_height:15;anchors_width:50}
D{i:9;invisible:true}D{i:16;invisible:true}D{i:29;invisible:true}D{i:40;anchors_height:15;anchors_width:50}
D{i:34;invisible:true}
}
 ##^##*/
