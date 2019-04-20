import QtQuick 2.0

Item {
	id: element
	width: parent.width
	height: parent.height

	Rectangle{
		width: 100
		height: 100
		Text {
			text: qsTr("Step 3")
		}
		color: "Blue"
		anchors.verticalCenter: parent.verticalCenter
		anchors.horizontalCenter: parent.horizontalCenter
	}

}
