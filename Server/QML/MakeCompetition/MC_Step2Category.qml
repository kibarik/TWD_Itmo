import QtQuick 2.0

Item {
	id: element
	width: parent.width
	height: parent.height

	Rectangle{
		width: 100
		height: 100
		Text {
			text: qsTr("Step 2")
		}
		color: "Red"
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter
	}

}

/*##^## Designer {
	D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
