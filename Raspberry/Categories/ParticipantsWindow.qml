import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0


Window {
    id: mainWindow
    width: 320
    height: 480

    signal signalExit

	property var participantsNames: ({});

	function showParticipants(){
		//if (listModel.rowCount()=== 0){
		    for(var i = 0; i < participantsNames.length; i ++){
				listModel.append({participantName:participantsNames[i]})
				console.log(participantsNames[i]);
			}
		//}
	}

	 ListView {
		 id: listView
		 width: 320
		 height: 380

		 delegate: Item {
			 width: parent.width
			 height: 50
			 Row {
				 id: row1
				 spacing: 1
				 width: 320
				 height: 50
				 Button {
					 id: control
					 text: participantName
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
					 }
				 }
			 }
		 }

		 model: ListModel {
			 id: listModel
		 }
	 }


    Button {
        id: button
        height: 50
        text: qsTr(">>Назад<<")
        anchors.right: parent.right
        anchors.left: parent.left

        onClicked: {
            mainWindow.signalExit()
			listModel.clear()
			delete participantsNames
        }
    }
}


/*##^## Designer {
    D{i:9;anchors_width:320;anchors_x:0}
}
 ##^##*/
