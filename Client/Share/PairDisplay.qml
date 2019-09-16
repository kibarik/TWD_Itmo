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

	signal pairDisplayButtonClicked

	Item {
		id: topInfo
		width: 320
		height: 100

		Controls.Button {
			id: nowRed
			width: 300
			height: 50
			anchors.top: parent.top
			anchors.topMargin: 0
			anchors.right: parent.right

			contentItem: Text {
				text: mainQmlWindow.redParticipant
				color: "White"
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				elide: Text.ElideRight

			}

			background: Rectangle {
				implicitWidth: nowRed.width
				implicitHeight: nowRed.height
				color: "#f02e2e"
			}

			onClicked: {
				pairDisplayShare.pairDisplayButtonClicked();
			}

		}


		Controls.Button {
			id: nowBlue
			width: 300
			anchors.bottom: parent.bottom
			anchors.right: parent.right
			height: 50

			contentItem: Text {
				text: mainQmlWindow.blueParticipant
				color: "White"
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				elide: Text.ElideRight

			}
			background: Rectangle {
				implicitWidth: nowRed.width
				implicitHeight: nowRed.height
				color: "#1F3A93"
			}

			onClicked: {
				pairDisplayShare.pairDisplayButtonClicked();
			}
		}

		Rectangle {
			id: textNow
			width: 20
			height: 100
			color: "#27ae60"
			border.width: 0

			Controls.Label {
				id: now
				color: "#ffffff"
				text: qsTr("Сейчас")
				anchors.fill: textNow
				rotation: 90
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}
		}


	}

	Item {
		id: buttomInfo
		width: 320
		height: 100
		anchors.bottom: parent.bottom

		Controls.Button {
			id: nextBlue
			width: 300
			height: 50
			anchors.bottom: parent.bottom
			anchors.right: parent.right
			contentItem: Text {
				color: "#ffffff"
				text: mainQmlWindow.nextParticipant1
				elide: Text.ElideRight
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
			background: Rectangle {
				color: "#34495e"
				implicitWidth: nextRed.width
				implicitHeight: nextRed.height
			}

			onClicked: {
				pairDisplayShare.pairDisplayButtonClicked();
				participantsWindow.isNextPairClicked = true;
			}
		}

		Rectangle {
			id: textNext
			width: 20
			height: 100
			color: "#95a5a6"
			Controls.Label {
				id: next
				color: "#ffffff"
				text: qsTr("Готовятся")
				rotation: 90
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: textNext
			}
		}

		Controls.Button {
			id: nextRed
			x: 20
			y: 0
			width: 300
			height: 50
			contentItem: Text {
				color: "#ffffff"
				text: mainQmlWindow.nextParticipant2
				elide: Text.ElideRight
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
			background: Rectangle {
				color: "#34495e"
				implicitWidth: nextRed.width
				implicitHeight: nextRed.height
			}

			onClicked: {
				pairDisplayShare.pairDisplayButtonClicked();
				participantsWindow.isNextPairClicked = true;
			}
		}
	}

}
