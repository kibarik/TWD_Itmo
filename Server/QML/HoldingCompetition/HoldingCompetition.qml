import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
	id: element

	Rectangle {
		id: topPanel
		height: 50
		color: mainWindow.lightColor
		//color: "Black"
		anchors.right: parent.right
		anchors.left: parent.left

//		gradient: Gradient {
//			GradientStop {position: 0.0; color: mainWindow.lightColor}
//			GradientStop {position: 0.97; color: mainWindow.darkColor}
//			GradientStop {position: 1.0; color: "#808080"}
//		}

		Button{
			id: close
			width: 50
			height: 50
			display: AbstractButton.IconOnly
			anchors.top: parent.top
			anchors.left: parent.left

			background: Rectangle {
				width: parent.width
				height: parent.height
				color: close.hovered ? mainWindow.hovColor : mainWindow.lightColor
				Image {
					source: "../../Img/back.png"
					height: parent.height
					width: parent.width

				}
			}

			onClicked: {
				holdingCompetitionWindow.visible=false
				choose.visible = true;
			}
		}

		Row {
			anchors.horizontalCenter: parent.horizontalCenter
//			    Button{
//					id: plus
//					width: 50
//					height: 50
//					display: AbstractButton.IconOnly

//					background: Rectangle {
//						width: parent.width
//						height: parent.height
//						color: close.hovered ? mainWindow.hovColor : mainWindow.lightColor
//						Image {
//							source: "../../Img/back.png"
//							height: parent.height
//							width: parent.width

//						}
//					}

//					onClicked: {
//						holdingCompetitionWindow.visible=false
//						choose.visible = true;
//					}
//			}

			    Text {
					text: qsTr("кнопки панели быстрого управления")
					color: "#fff"
				}
		}
	}

	Rectangle {
		id: leftMenu
		width: 150
		color: "#2f3640"
		anchors.bottom: parent.bottom
		anchors.top: topPanel.bottom
		anchors.left: parent.left
		anchors.leftMargin: 0
		border.color: darkColor
		border.width: 1
	}

	Rectangle {
		id: rightMenu
		width: 250
		color: mainWindow.hovColor
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
