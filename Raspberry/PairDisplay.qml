import QtQuick 2.0
import QtQuick.Controls 2.5


/*
    Отображение участников определяется выбранной категорией
    Из категории получаем всех участников
    Программа распределяет их по парам
    Можно сделать в виде словаря ключ и значение - одна пара
    один участник тогда имя: пусто

    first.text: categoryFighters[0].first()
    second.text: categoryFighters[0].second()

    next1.text: categoryFighters[1].first()
    next2.text: categorybFightets[1].second()

*/

    Rectangle {
    width: 320
    height: 200
    id: designer__Selection

    Row {
        id: now
        x: 0
        width: 320
        height: 100
        anchors.top: categorybButton.bottom
        Column {
            id: n_lbl
            width: 20
            height: 100
            Rectangle {
                id: rectangle1
                color: "#27ae60"
                anchors.fill: parent
                Label {
                    id: label
                    color: "#ffffff"
                    text: qsTr("Сейчас")
                    anchors.fill: parent
                    rotation: 90
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                border.width: 0
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
                color: "#c0392b"
                ItemDelegate {
                    id: first
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    padding: 5
                    display: AbstractButton.TextOnly
                    font.family: "Times New Roman"
                    font.pointSize: 10

                    onClicked: {

                    }
                }
            }

            Rectangle {
                id: rectangle3
                x: 0
                width: 300
                height: 50
                color: "#3867d6"
                anchors.bottom: parent.bottom
                ItemDelegate {
                    id: second
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    padding: 5
                    font.family: "Times New Roman"
                    font.pointSize: 10
                    hoverEnabled: false
                }
            }
        }
        anchors.topMargin: 0
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
                color: "#f1c40f"
                anchors.fill: parent
                Label {
                    id: label1
                    color: "#ffffff"
                    text: qsTr("Следующий")
                    anchors.fill: parent
                    rotation: 90
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
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
                color: "#95a5a6"
                ItemDelegate {
                    id: next1
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    padding: 5
                    display: AbstractButton.TextOnly
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
                ItemDelegate {
                    id: next2
                    width: 300
                    height: 50
                    text: qsTr("Ишманов Алексей\nВыборг 'Фанат'")
                    padding: 5
                    font.pointSize: 10
                    font.family: "Times New Roman"
                    hoverEnabled: false
                }
            }
        }
    }
}
