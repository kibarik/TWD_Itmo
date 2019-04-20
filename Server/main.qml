import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import "QML/"
import "QML/MakeCompetition"

Window {
	id: mainWindow

	//flags: Qt.ForeignWindow;
	//flags: Qt.FramelessWindowHint;
	//flags: Qt.FramelessWindowHint;

	property string bgColor: "#2c3e50";
	property string hovColor: "#3d5770";
	property string background: "#181d23";
	property string lightColor: "#34495E"

	visible: true
	title: qsTr("Server taekwon-do")
	opacity: 1
	x: 0
	y: 0
	minimumWidth: 1024
	minimumHeight: 600
	width: Screen.width
	height: Screen.height
	color: background

	ChooseMode {
		id: choose
		anchors.horizontalCenter: parent.horizontalCenter
		width: parent.width
		anchors.verticalCenter: parent.verticalCenter
		visible: true

		onMakeCompetition: {
			createCompetitionWindow.visible = true;
			choose.opacity = 0.05
		}
	}

	MakeCompetition {
		id: createCompetitionWindow
		visible: false
		width: 1024
		height: 550
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter
	}
}
