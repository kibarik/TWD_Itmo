import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

import "QML/"
import "QML/MakeCompetition"
import "QML/HoldingCompetition"


Window {
	id: mainWindow

	//flags: Qt.ForeignWindow;
	//flags: Qt.FramelessWindowHint;
	//flags: Qt.FramelessWindowHint;\

	//палитра цветов
	property string bgColor: "#2c3e50";
	property string hovColor: "#3d5770";
	property string lightColor: "#34495E";
	property string darkColor: "#22313F";
	property string asphalt: "#2f3640";

	visible: true
	title: qsTr("Server taekwon-do")
	opacity: 1
	x: 0
	y: 0
	minimumWidth: 1024
	minimumHeight: 600
	width: Screen.width
	height: Screen.height
	color: "#181d23"

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

		onHoldingCompetition: {
			holdingCompetitionWindow.visible = true;
			choose.visible = false;
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

	HoldingCompetition {
		id: holdingCompetitionWindow
		visible: false
		width: parent.width
		height: parent.height
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.verticalCenter: parent.verticalCenter
	}

}
