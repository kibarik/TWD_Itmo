import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

Window {
	width: 320
	height: 480

	signal signalExit
	signal selectPair
	signal monitorSetTul
	signal monitorSetSparring

	property var categoryMode; //переменная для переключения экранов
	property var participantsNames: ({}); //получение структуры из C++ QList<QList<Participants>>
	property string categoryName: "Выберите категорию";

	property var participantPairPositions: [
		    participantsNames[0],
		    participantsNames[1],
		    participantsNames[2],
		    participantsNames[3]
	] // динамический список. При выборе пары сюда передаются их порядковые номера

	function showParticipants(){
		var temp = ""
		for(var i = 1; i < participantsNames.length+1; i ++){
			if(i%2==0){
				listModel.append({ //четный
									 participantName1:participantsNames[i-1],
									 participantName2:temp,
									 pairNum: Math.ceil(i/2) //округляем 1.5 до 2, 3.5 до 4 и т.п.
								 })
			}
			temp = participantsNames[i-1] //нечетные
		}
	}

	Row {
		id: row
		width: 320
		height: 40
		anchors.bottom: parent.bottom

		Button {
			id: back
			width: height
			height: parent.height
			text: qsTr("<")
			transformOrigin: Item.Left

			onClicked: {
				participantsWindow.signalExit()
				listModel.clear()
				delete participantsNames
			}
		}

		Button {
			id: start
			width: parent.width-back.width
			height: parent.height
			text: qsTr("Провести: ") + categoryName
			font.family: "Times New Roman"
			spacing: 5

			contentItem: Text {
				text: start.text
				color: "White"
				transformOrigin: Item.Right
				opacity: enabled ? 1.0 : 0.3
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				elide: Text.ElideRight

			}

			background: Rectangle {
				implicitWidth: 320
				implicitHeight: 50
				color: "#019875"
				border.width: 0
			}

			onClicked: {
				participantsWindow.close()
				participantPairPositions =[
							        participantsNames[0],
							        participantsNames[1],
							        participantsNames[2],
							        participantsNames[3]
						    ]; // автоматически ставим первую пару и готовим следующих

				mainQmlWindow.nowCategoryName = categoryName;
				participantsWindow.selectPair()

				switch(categoryMode){
				    case "Туль личный":
						participantsWindow.monitorSetTul();
						break;

					case "Туль командный":
						participantsWindow.monitorSetTul();
						break;

					case "Туль традиционный":
						participantsWindow.monitorSetTul();
						break;

					case "Спарринг традиционный":
						participantsWindow.monitorSetTul();
						break;

					case "Спарринг личный":
						participantsWindow.monitorSetSparring();
						break;

					case "Спарринг командный":
						participantsWindow.monitorSetSparring();
						break;

					case "Силовое разбивание":
						participantsWindow.monitorSetSparring();
						break;

					case "Спец. техника":
						participantsWindow.monitorSetSparring();
						break;

					default: console.log("UNKNOWN CATEGORY TYPE")
				}

			}
		}
	}

	ListView {
		id: listView
		width: 320
		height: 390
		anchors.top: parent.top

		delegate: Item {
			width: 320
			height: 50

			Rectangle {
				id: rectangle
				width: 320
				height: 50
				border.width: 0

				MouseArea {
					id: mouseArea
					anchors.fill: parent

					onClicked: {
						participantsWindow.selectPair();
						delete participantsNames
					}
				}

				Rectangle {
					color: "#e74c3c"
					height: parent.height/2
					anchors.left: num.right
					anchors.right: parent.right
					anchors.top: parent.top
					anchors.topMargin: parent.border.width

					Label {
						id: topL
						color: "White"
						text: participantName1
						verticalAlignment: Text.AlignVCenter
						padding: 1
						leftPadding: 5
						anchors.fill: parent
						horizontalAlignment: Text.AlignLeft
						fontSizeMode: Text.VerticalFit
					    }
				}

				Label {
					id: num
					width: 15
					height: parent.height
					text: pairNum
					anchors.left: parent.left
					verticalAlignment: Text.AlignVCenter
					horizontalAlignment: Text.AlignHCenter
				}

				Rectangle {
					color: "#2980b9"
					height: parent.height/2 - space.height

					anchors.left: num.right
					anchors.right: parent.right
					anchors.bottom: space.top

					Label {
						id: bottomL
						text: participantName2
						anchors.fill: parent
						color: "White"
						padding: 1
						leftPadding: 5
						fontSizeMode: Text.VerticalFit
						verticalAlignment: Text.AlignVCenter
					}
				}
				Rectangle {
					id: space
					height: 3
					width: parent.width
					color: "Black"
					anchors.bottom: parent.bottom
				}
			}
		}

		model: ListModel {
			id: listModel
		}
	}
}
