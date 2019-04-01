import QtQuick 2.5
import QtQuick.Controls 2.0 as Controls

/*
    Отображение участников определяется выбранной категорией
    Из категории получаем всех участников
    Программа распределяет их по парам
    Можно сделать в виде словаря ключ и значение - одна пара
    один участник тогда имя: пусто

    first.text: categoryFighters[0].first()
    second.text: categoryFighters[0].second()

    next1.text: categoryFighters[1].firstr()
    next2.text: categorybFightets[1].second()

*/

Rectangle {
    width: 320
    height: 200
    id: designer__Selection

    Row {
        id: now
        width: 320
        height: 100

        Column {
            id: column
            width: 300
            height: 100
            anchors.right: parent.right
            Rectangle {
                id: rectangle2
                width: 300
                height: 50
                color: "#c0392b"
                Controls.ItemDelegate {
                    id: first
                    width: 300
                    height: 50
                    text: qsTr("Спортсмен 1\n Город 'Клуб'")
                    padding: 5
                    font.family: "Times New Roman"
                    font.pointSize: 10
                }
            }

            Rectangle {
                id: rectangle3
                width: 300
                height: 50
                color: "#3867d6"
                anchors.bottom: parent.bottom
                Controls.ItemDelegate {
                    id: second
                    width: 300
                    height: 50
                    text: qsTr("Спортсмен 2\n Город 'Клуб'");
                    padding: 5
                    font.family: "Times New Roman"
                    font.pointSize: 10
                    hoverEnabled: false
                }
            }
        }

        Rectangle {
            id: rectangle1
            color: "#27ae60"
            anchors.right: column.left
            anchors.bottom: column.bottom
            anchors.top: parent.top
            anchors.left: parent.left
            border.width: 0

            Controls.Label {
                id: label
                color: "#ffffff"
                text: qsTr("Сейчас")
                anchors.fill: rectangle1
                rotation: 90
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    Row {
        id: after
        width: 320
        height: 100
        anchors.bottom: parent.bottom
        anchors.top: parent.butt

        Column {
            id: column1
            width: 300
            height: 100
            anchors.right: parent.right
            Rectangle {
                id: rectangle5
                width: 300
                height: 50
                color: "#95a5a6"
                Controls.ItemDelegate {
                    id: next1
                    width: 300
                    height: 50
                    text: qsTr("Спортсмен 1\n Город 'Клуб'")
                    padding: 5
                    font.pointSize: 10
                    font.family: "Times New Roman"
                }
            }

            Rectangle {
                id: rectangle6
                x: 0
                width: 300
                height: 50
                color: "#95a5a6"
                anchors.bottom: parent.bottom
                Controls.ItemDelegate {
                    id: next2
                    width: 300
                    height: 50
                    text: qsTr("Следующий спортсмен 2\n Город 'Клуб'");                  padding: 5
                    font.pointSize: 10
                    font.family: "Times New Roman"
                    hoverEnabled: false
                }
            }
        }

        Rectangle {
            id: rectangle4
            color: "#22313F"
            anchors.right: column1.left
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.top: parent.top
            border.width: 0

            Controls.Label {
                id: label1
                x: 0
                y: 0
                color: "#fff"
                text: qsTr("Следующий")
                anchors.fill: parent
                rotation: 90
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }

    }
}



















/*##^## Designer {
    D{i:7;anchors_x:5;anchors_y:3}
}
 ##^##*/
