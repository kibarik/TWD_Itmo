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

	property var participantNowPairPositions: [
		    participantsNames[0],
		    participantsNames[1]
	] // динамический список. При выборе пары сюда передаются их порядковые номера

	property var participantNextPairPositions: [
		    participantsNames[2],
		    participantsNames[3]
	] // динамический список. При выборе пары сюда передаются их порядковые номера

	function showParticipants(){
		var temp = ""
		if(listModel.rowCount()===0){ // защита от дублирования
			for(var i = 1; i < participantsNames.length+1; i ++){
				if(i%2==0){
					listModel.append({ //четный
										 participantName1: temp, //красный (каждый нечетный)
										 participantName2: participantsNames[i-1], //синий (четные)
										 pairNum: Math.ceil(i/2), //округляем 1.5 до 2, 3.5 до 4 и т.п.
										 redID: i-2,
										 blueID: i-1
									 })
				}
				temp = participantsNames[i-1] //нечетные
			}
		}
		delete participantsNames;
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
				if (mainQmlWindow.nowCategoryName != categoryName){//очищать, если не зашли в непроводимую категория (баг пустого окна по выбору пары)
					participantsWindow.signalExit()
					listModel.clear()
					delete participantsNames
					console.log("очистка listModel для категории отличной от текущей")
				}
				else { //текущая и проводимая категория совпадают
					console.log("условие else ", mainQmlWindow.visible)
					participantsWindow.close()
					mainQmlWindow.opacity = 1.0
					listModel.clear()

				}
			}
		}

		Button { //провести категорию
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

				participantNowPairPositions =[
							        participantsNames[0],
							        participantsNames[1]
						    ]; // автоматически ставим первую пару участников 0 и 1

				participantNextPairPositions = [
							participantsNames[2],
							participantsNames[3]
						]; //автоматически ставим следующей пару участников 2 и 3

				mainQmlWindow.nowCategoryName = categoryName;
				participantsWindow.selectPair()


				if (mainQmlWindow.nowCategoryName != categoryName){//очищать, если не зашли в непроводимую категория (баг пустого окна по выбору пары)
					listModel.clear()
					delete participantsNames
					console.log("очистка listModel для категории отличной от текущей")
				}

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

				listModel.clear()
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
					id: mouseAreaRed
					anchors.fill: parent

					onClicked: {
						console.log("Select now pair->", redID, "-", blueID);

						participantNowPairPositions =[
									        participantsNames[redID],
									    participantsNames[blueID],
								    ]; // автоматически ставим первую пару и готовим следующих

						participantsWindow.selectPair();
						listModel.clear()
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
						property int redID;
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
					property int blueID;
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
