import QtQuick 2.0

Rectangle {
	id: rectangle
	width: 400
	height: parent.height
	color: mainWindow.asphalt

	Item {
		id: tableCategoryView
		width: parent.width
		height: 250

		Text {
			text: qsTr("Табличное представление категории")
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.verticalCenter: parent.verticalCenter
			color: "White"
		}

		Rectangle {
			width: parent.width
			height: 2
			color: "#808080"
			anchors.bottom: parent.bottom
		}

	}

	Item {
		id: participants
		width: parent.width
		anchors.bottom: parent.bottom
		anchors.top: tableCategoryView.bottom

		Text {
			text: qsTr("Список участников категории")
			anchors.verticalCenter: parent.verticalCenter
			anchors.horizontalCenter: parent.horizontalCenter
			color: "White"
		}

	}
}




































