import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
	id: element

	TopPanel {
		id: topPanel;
		anchors.right: parent.right
		anchors.left: parent.left
	}

	LeftMenu {
		id: leftMenu;
		anchors.bottom: parent.bottom
		anchors.top: topPanel.bottom
		anchors.left: parent.left
		anchors.leftMargin: 0
	}



	Rectangle {
		id: rightMenu
		width: 250
		color: mainWindow.asphalt
		anchors.right: parent.right
		anchors.bottom: parent.bottom
		anchors.top: topPanel.bottom
		border.color: darkColor
		border.width: 1
	}
}

















































/*##^## Designer {
	D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
