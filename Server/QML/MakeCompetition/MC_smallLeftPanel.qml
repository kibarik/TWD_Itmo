import QtQuick 2.0
import QtQuick.Controls 2.0

Column {
	id: smallPanel
//	color: leftMenu.color

	Button {
		id: smallMenu_step1
		width: parent.width;
		height: width
		checkable: true


		contentItem: Text {
			text: qsTr("1")
			font.bold: true
			anchors.fill: parent
			font.pointSize: 15
			font.family: "Times New Roman"
			color: "white"
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

		}


		background:  Rectangle {
			color: smallMenu_step1.checked ? mainWindow.hovColor : mainWindow.bgColor
			border.width: smallMenu_step1.hovered ? 1 : 0
			border.color: "#fff"
		}

		onClicked: {
			selectChecked(1);
		}
	}

	Button {
		id: smallMenu_step2
		width: parent.width;
		height: width
		checkable: true


		contentItem: Text {
			text: qsTr("2")
			font.bold: true
			anchors.fill: parent
			font.pointSize: 15
			font.family: "Times New Roman"
			color: "white"
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

		}


		background:  Rectangle {
			color: smallMenu_step2.checked ? mainWindow.hovColor : mainWindow.bgColor
			border.width: smallMenu_step2.hovered ? 1 : 0
			border.color: "#fff"
		}

		onClicked: {
			selectChecked(2);
		}
	}

	Button {
		id: smallMenu_step3
		width: parent.width;
		height: width
		checkable: true


		contentItem: Text {
			text: qsTr("3")
			font.bold: true
			anchors.fill: parent
			font.pointSize: 15
			font.family: "Times New Roman"
			color: "white"
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

		}


		background:  Rectangle {
			color: smallMenu_step3.checked ? mainWindow.hovColor : mainWindow.bgColor
			border.width: smallMenu_step3.hovered ? 1 : 0
			border.color: "#fff"
		}

		onClicked: {
			selectChecked(3);
		}
	}

	Button {
		id: smallMenu_step4
		width: parent.width;
		height: width
		checkable: true


		contentItem: Text {
			text: qsTr("4")
			font.bold: true
			anchors.fill: parent
			font.pointSize: 15
			font.family: "Times New Roman"
			color: "white"
			horizontalAlignment: Text.AlignHCenter
			verticalAlignment: Text.AlignVCenter

		}


		background:  Rectangle {
			color: smallMenu_step4.checked ? mainWindow.hovColor : mainWindow.bgColor
			border.width: smallMenu_step4.hovered ? 1 : 0
			border.color: "#fff"
		}

		onClicked: {
			selectChecked(4);
		}
	}
}

/*##^## Designer {
	D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
