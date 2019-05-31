import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
	id: topPanel
	color: mainWindow.lightColor
	//color: "#000"
	width: parent.width
	height: 40

	Button{
		id: close
		height: topPanel.height; width: height
		display: AbstractButton.IconOnly
		anchors.top: parent.top
		anchors.left: parent.left

		background: Rectangle {
			width: parent.width
			height: parent.height
			color: close.hovered ? mainWindow.hovColor : topPanel.color
			Image {
				source: "../../Img/back.png"
				width: close.width
				height: close.height
			}
		}

		onClicked: {
			holdingCompetitionWindow.visible=false
			choose.visible = true;
		}
	}

	Row {
		anchors.horizontalCenter: parent.horizontalCenter
		Button{
			id: plus
			height: topPanel.height; width: height

			display: AbstractButton.IconOnly
			background: Rectangle {
				width: parent.width + 10
				color: plus.hovered ? mainWindow.hovColor : topPanel.color
				Image {
					source: "../../Img/add.png"
					height: plus.height
					width: plus.width

				}
			}

			onClicked: {
				console.log("HoldingCompetition: button 'plus' clicked");
			}
		}

		Button{
			id: minus
			height: topPanel.height; width: height

			display: AbstractButton.IconOnly
			background: Rectangle {
				color: minus.hovered ? mainWindow.hovColor : topPanel.color
				Image {
					source: "../../Img/remove.png"
					height: minus.height
					width: minus.width

				}
			}

			onClicked: {
				console.log("HoldingCompetition: button 'minus' clicked");
			}
		}

		Button{
			id: edit
			height: topPanel.height; width: height

			display: AbstractButton.IconOnly
			background: Rectangle {
				color: edit.hovered ? mainWindow.hovColor : topPanel.color
				Image {
					source: "../../Img/edit.png"
					height: edit.height
					width: edit.width

				}
			}

			onClicked: {
				console.log("HoldingCompetition: button 'search' clicked");
			}
		}

		Button{
			id: search
			height: topPanel.height; width: height

			display: AbstractButton.IconOnly
			background: Rectangle {
				color: search.hovered ? mainWindow.hovColor : topPanel.color
				Image {
					source: "../../Img/search.png"
					height: search.height
					width: search.width

				}
			}

			onClicked: {
				console.log("HoldingCompetition: button 'search' clicked");
			}
		}

		Button{
			id: sort
			height: topPanel.height; width: height

			display: AbstractButton.IconOnly
			background: Rectangle {
				color: sort.hovered ? mainWindow.hovColor : topPanel.color
				Image {
					source: "../../Img/human.png"
					height: sort.height
					width: edit.width

				}
			}

			onClicked: {
				console.log("HoldingCompetition: button 'sort' clicked");
			}
		}


	}
}
