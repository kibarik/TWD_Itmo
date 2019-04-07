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

	Item {
		id: topInfo
		width: 320
		height: 100

		Rectangle {
			id: rectangle2
			width: 300
			height: 50
			color: "#c0392b"
			anchors.right: parent.right

			Controls.Button {
				id: control
				width: 300
				height: 50

				contentItem: Text {
					text: mainQmlWindow.redParticipant
					color: "White"
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					elide: Text.ElideRight

				}
				background: Rectangle {
					implicitWidth: control.width
					implicitHeight: control.height
					color: "#f02e2e"
				}

				onClicked: {
					participantsWindow.show()
					participantsWindow.participantsNames = categoryAPI.setQmlParticipantsNames(mainQmlWindow.nowCategoryName)
					participantsWindow.categoryName = nowCategoryName
					participantsWindow.showParticipants()
				}
			}
		}


		Controls.Button {
			id: blue
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
				implicitWidth: control.width
				implicitHeight: control.height
				color: "#1F3A93"
			}

			onClicked: {
				participantsWindow.show()
				participantsWindow.participantsNames = categoryAPI.setQmlParticipantsNames(mainQmlWindow.nowCategoryName)
				participantsWindow.categoryName = nowCategoryName
				participantsWindow.showParticipants()
			}
		}

		Rectangle {
			id: nextNow
			width: 20
			height: 100
			color: "#27ae60"
			border.width: 0

			Controls.Label {
				id: label
				color: "#ffffff"
				text: qsTr("Сейчас")
				anchors.fill: nextNow
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
		 id: blue1
		 width: 300
		 height: 50
		 contentItem: Text {
			 color: "#ffffff"
			 text: mainQmlWindow.nextParticipant1
			 elide: Text.ElideRight
			 verticalAlignment: Text.AlignVCenter
			 horizontalAlignment: Text.AlignHCenter
		 }
		 anchors.bottom: parent.bottom
		 background: Rectangle {
			 color: "#34495e"
			 implicitWidth: control1.width
			 implicitHeight: control1.height
		 }
		 anchors.right: parent.right
	 }

	 Rectangle {
		 id: rectangle3
		 x: 20
		 y: 0
		 width: 300
		 height: 50
		 color: "#c0392b"
		 Controls.Button {
			 id: control1
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
				 implicitWidth: control1.width
				 implicitHeight: control1.height
			 }
		 }
		 anchors.right: parent.right
	 }

	 Rectangle {
		 id: nextNow1
		 width: 20
		 height: 100
		 color: "#95a5a6"
		 Controls.Label {
			 id: label2
			 color: "#ffffff"
			 text: qsTr("Готовятся")
			 rotation: 90
			 verticalAlignment: Text.AlignVCenter
			 horizontalAlignment: Text.AlignHCenter
			 anchors.fill: nextNow1
		 }
	 }
 }

}



































/*##^## Designer {
	D{i:2;anchors_width:300}
}
 ##^##*/
