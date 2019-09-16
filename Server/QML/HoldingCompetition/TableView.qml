import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
	id: tableView
	width: parent.width
	height: parent.height

	Rectangle {
		id: topPanel
		color: mainWindow.lightColor
		//color: "#000"
		width: parent.width
		height: 40

		visible: false //появляется при полноразмерном раскрытии

		Button{
			id: close
			height: topPanel.height; width: height
			display: AbstractButton.IconOnly
			anchors.top: parent.top
			anchors.right: parent.right

			background: Rectangle {
				width: parent.width
				height: parent.height
				color: close.hovered ? mainWindow.hovColor : topPanel.color
				Image {
					source: "../../Img/close.png"
					width: close.width
					height: close.height
				}
			}

			onClicked: {
				tableView.width = 400
				tableView.height = 300
				topPanel.visible = false;
				rightPanel.width = rightPanelMinWidth;

				console.log("Table View in main length");
			    }
		    }
	    }

	    Item {
			width: parent.width
			anchors.bottom: parent.bottom
			anchors.top: topPanel.bottom


			MouseArea{
				id: categoryTableMouse
				anchors.fill: parent
				onClicked: {
					console.log("Table View in full length");
					rightPanel.width = rightPanelMaxWidth;
					participants.visible = false;
					tableView.width = rightPanelMaxWidth
					tableView.height = rightPanel.height
					topPanel.visible = true;
				}
			}

			Text {
				text: qsTr("Табличное представление категории")
				anchors.horizontalCenter: parent.horizontalCenter
				anchors.verticalCenter: parent.verticalCenter
				color: "White"
			}
		}

}
