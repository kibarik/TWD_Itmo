import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
	id: rectangle
	width: 400
	height: parent.height
	color: mainWindow.asphalt

	TableView {
		id: tableCategoryView
		width: parent.width
		height: 300

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





/*##^## Designer {
	D{i:1;anchors_height:250;anchors_width:400}
}
 ##^##*/
