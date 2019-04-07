import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Window 2.0


Window {
	id: window
	width: 320
	height: 480
	color: "#34495e"
	visible: true

	BusyIndicator {
		id: busyIndicator
		width: 120
		height: 120
		anchors.topMargin: 10
		anchors.top: parent.top
		anchors.horizontalCenterOffset: 0
		anchors.horizontalCenter: parent.horizontalCenter
	}

	Label {
		id: problem
		width: 310
		color: "#c4c4c8"
		text: qsTr("Не удалось соединиться с сервером")
		font.bold: true
		font.italic: false
		font.underline: true
		anchors.verticalCenterOffset: -87
		  anchors.horizontalCenterOffset: 0
		  font.family: "Times New Roman"
		  font.pointSize: 14
		wrapMode: Text.WordWrap
		verticalAlignment: Text.AlignVCenter
		horizontalAlignment: Text.AlignHCenter
		anchors.verticalCenter: parent.verticalCenter
		anchors.horizontalCenter: parent.horizontalCenter
	}

	Text {
		id: element
		width: 315
		text: "Инструкция и анимация для человеков."
		 anchors.bottom: parent.bottom
		 anchors.topMargin: 10
		 anchors.top: problem.bottom
		 font.pixelSize: 12
 }

}



/*##^## Designer {
	D{i:3;anchors_height:299}
}
 ##^##*/
