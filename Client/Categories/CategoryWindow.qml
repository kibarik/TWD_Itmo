import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Window 2.5


/*
int categoryMode = переменная используется для запуска нужного монитора
	туль личный -> OutMonitorTul.qml
	туль коммандный -> OutMonitorTul.qml

	спарринг личный -> OutMonitorSparring.qml
	спарринг коммандный -> OutMonitorSparring.qml
	спарринг традиционный -> OutMonitorTul.qml

*/

Window {
	id: mainWindow
	width: 320
	height: 480
	//flags: Qt.FramelessWindowHint // Отключаем обрамление окна

	signal signalExit
	signal openParticipants
	signal categoryShow

	function showCategories() {
		var categoryNames = categoryAPI.setQmlCategoriesNames(); //получаем все локальные категории
		var mode;
		listModel.clear()
		for(var i = 0; i < categoryNames.length; i ++){ //проходимся по массиву
			mode = categoryNames[i].split(' ');
			mode = mode[6] + " " + mode[7] // Туль личные/Спарринг и др.
			listModel.append({
								 categoryName:categoryNames[i],
								 categoryMode: mode
							 })

		}
		delete categoryNames;
	}

   ListView {
	   id: listView
	   width: 320
	   height: 430
	   keyNavigationWraps: false
	   maximumFlickVelocity: 2500
	   anchors.top: parent.top

	    delegate: Item {
			width: parent.width
			height: 50

			Row {
				spacing: 1
				width: 320
				height: 50

				Button {
					id: control
					text: categoryName
					contentItem: Text {
						text: control.text
						font: control.font
						opacity: enabled ? 1.0 : 0.3
						color: control.down ? "#22313f" : "#696969"
						horizontalAlignment: Text.AlignHCenter
						verticalAlignment: Text.AlignVCenter
						elide: Text.ElideRight

					}
					background: Rectangle {
						implicitWidth: 320
						implicitHeight: 50
						opacity: enabled ? 1 : 0.3
						border.color: control.down ? "#FA8072" : "#696969"
						border.width: 1
					}

					onClicked: {
						categoryWindow.openParticipants();
						participantsWindow.participantsNames = categoryAPI.setQmlParticipantsNames(control.text)
						participantsWindow.showParticipants();
						participantsWindow.categoryName = categoryName
						participantsWindow.categoryMode = categoryMode
					}
				}
			}
		}

		model: ListModel {
			id: listModel
		}
    }

    Button {
		id: back
		x: 0
		y: 440
		width: 320
		height: 40
		text: qsTr("> Назад <")
		anchors.bottomMargin: 0
		anchors.bottom: parent.bottom
		focusPolicy: Qt.WheelFocus
		display: AbstractButton.TextOnly
		flat: false

		onClicked: {
			mainWindow.signalExit()
		}
	}



}

