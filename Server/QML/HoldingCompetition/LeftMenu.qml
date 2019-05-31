import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
	id: main
	width: 150
	color: mainWindow.asphalt

	Column {
		Button{
			id: dojangs
			height: 40; width: main.width

			display: AbstractButton.IconOnly
			background: Rectangle {
				color: dojangs.hovered ? mainWindow.hovColor : mainWindow.darkColor
				Image {
					source: "../../Img/dojangs.png"
					height: 24; anchors.verticalCenter: parent.verticalCenter; width: 24
				}
			}

			contentItem: Text {
				color: "#ffffff"
				text: qsTr("Доянги")
				font.bold: true
				font.pointSize: 12
				font.family: "Times New Roman"
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}

		Rectangle {
			width: main.width
			height: 1
			color: "Grey"
		}

		Button{
			id: categories
			height: 40; width: main.width

			display: AbstractButton.IconOnly
			background: Rectangle {
				color: categories.hovered ? mainWindow.hovColor : mainWindow.darkColor
				Image {
					source: "../../Img/group.png"
					height: 24; width: 24
					anchors.verticalCenter: parent.verticalCenter;
				}
			}

			contentItem: Text {
				color: "#ffffff"
				text: qsTr("Категории")
				font.bold: true
				font.pointSize: 12
				font.family: "Times New Roman"
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}

		Rectangle {
			width: main.width
			height: 1
			color: "Grey"
		}

		Button{
			id: search
			height: 40; width: main.width

			display: AbstractButton.IconOnly
			background: Rectangle {
				color: search.hovered ? mainWindow.hovColor : mainWindow.darkColor
				Image {
					source: "../../Img/search.png"
					height: 24; width: 24
					anchors.verticalCenter: parent.verticalCenter;
				}
			}

			contentItem: Text {
				color: "#ffffff"
				text: qsTr("Поиск")
				font.bold: true
				font.pointSize: 12
				font.family: "Times New Roman"
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}
	}
}
