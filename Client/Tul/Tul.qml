import QtQuick 2.4
import QtQuick.Controls 2.2
import "../Share"


Rectangle {
	id: rectangle
	width: 320
	height: 480
	color: "#424141"
	border.color: "#ffffff"
	signal categoryShow

	Button {
	id: button
	width: 320
	height: 60
	font.family: "Times New Roman"
	anchors.top: parent.top

	contentItem: Text {
		text: mainQmlWindow.nowCategoryName
		font.pointSize: 10
		horizontalAlignment: Text.AlignHCenter
		verticalAlignment: Text.AlignVCenter
		elide: Text.ElideRight

	}
	background: Rectangle {
		implicitWidth: button.width
		implicitHeight: button.height
		color: "#ecf0f1"
	}

	    onClicked: {
			tulWindow.categoryShow()
			categoryWindow.categoryShow()
		}
	}

	PairDisplay {
		id: pairDisplay
		height: 200
		anchors.top: button.bottom
		width: 320
		visible: true
	}

	PointsTable {
		id: points
		anchors.top: pairDisplay.bottom
	}

	TulInfo {
		visible: true
		id: j_info
		anchors.right: parent.right
		anchors.rightMargin: 0
		anchors.left: parent.left
		anchors.leftMargin: 0
		anchors.bottom: controlButtons.top
		anchors.top: points.bottom
	}

	Grid {
		id: controlButtons
		width: 320
		height: 90
		rows: 1
		columns: 3
		anchors.bottom: parent.bottom

		Rectangle {
			id: start
			width: parent.width/3
			height: parent.height
			color: "#27ae60"
			clip: false

			Text {
				id: element2
				color: "#ffffff"
				text: qsTr("Старт")
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
				font.pixelSize: 17
			}
		}

		Rectangle {
			id: stop
			width: parent.width/3
			height: parent.height
			color: "#e74c3c"
			clip: false

			Text {
				id: element3
				color: "#ffffff"
				text: qsTr("Стоп")
				horizontalAlignment: Text.AlignHCenter
				fontSizeMode: Text.Fit
				anchors.fill: parent
				font.pixelSize: 17
				verticalAlignment: Text.AlignVCenter
			}
		}

		Rectangle {
			id: level
			width: parent.width/3
			height: parent.height
			color: "#f39c12"
			clip: false

			Text {
				id: element
				color: "#ffffff"
				text: "1"
				font.family: "Tahoma"
				fontSizeMode: Text.Fit
				anchors.top: element1.bottom
				anchors.right: parent.right
				anchors.bottom: parent.bottom
				anchors.left: parent.left
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				font.pixelSize: 29
			}

			Text {
				id: element1
				color: "#ffffff"
				text: qsTr("Суд. уровень")
				horizontalAlignment: Text.AlignHCenter
				anchors.right: parent.right
				anchors.left: parent.left
				anchors.leftMargin: 0
				anchors.top: parent.top
				anchors.topMargin: 0
				font.pixelSize: 12
			}
		}


	}


}




















































































/*##^## Designer {
	D{i:4;anchors_height:100;anchors_width:320;anchors_x:0;anchors_y:331}D{i:6;anchors_width:320;anchors_x:0}
D{i:9;anchors_x:107;anchors_y:0}D{i:12;anchors_x:213;anchors_y:0}D{i:7;anchors_x:107;anchors_y:0}
}
 ##^##*/
