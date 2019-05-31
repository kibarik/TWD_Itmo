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

	RightPanel {
		id: rightPanel
		anchors.right: parent.right
		anchors.bottom: parent.bottom
		anchors.top: topPanel.bottom

	}
}

















































/*##^## Designer {
	D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
