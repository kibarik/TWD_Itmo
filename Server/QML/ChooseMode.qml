import QtQuick 2.9
import QtQuick.Window 2.10
import QtQuick.Controls 2.0

Item {
	width: 900
	height: 400

	signal makeCompetition


	Image {
		source: "../Img/logo2.png"
		width: 200
		height: 200
		anchors.top: row.bottom
		anchors.horizontalCenter: parent.horizontalCenter
	}

	Row {
		id: row
		height: 200
		anchors.left: parent.left
		anchors.leftMargin: 0
		anchors.right: parent.right
		anchors.rightMargin: 0
		anchors.top: parent.top
		anchors.bottomMargin: 1


	  Button {
		  id: makeCompetition
		  width: parent.width/4
		  height: 200

		  Image {
			  source: "../Img/add.png"
			  width: 48
			  height: 48
			  anchors.verticalCenter: parent.verticalCenter
			  anchors.horizontalCenter: parent.horizontalCenter
		  }

		  contentItem: Text{
			  text: "Создать\nсоревнования"
			  font.pointSize: 14
			  bottomPadding: 20
			  verticalAlignment: Text.AlignBottom
			  horizontalAlignment: Text.AlignHCenter
			  color: "White"
		  }

		  background: Rectangle {
			  color: makeCompetition.hovered ? mainWindow.hovColor : mainWindow.bgColor
		  }

		  onClicked: {
			  choose.makeCompetition();
		  }
	  }

	  Button {
		  id: startCompetition
		  width: parent.width/4
		  height: 200

		  Image {
			  source: "../Img/start.png"
			  width: 48
			  height: 48
			  anchors.horizontalCenter: parent.horizontalCenter
			  anchors.verticalCenter: parent.verticalCenter
		  }

		  contentItem: Text{
			  text: "Провести\nсоревнования"
			  font.pointSize: 14
			  bottomPadding: 20
			  verticalAlignment: Text.AlignBottom
			  horizontalAlignment: Text.AlignHCenter
			  color: "White"
		  }

		  background: Rectangle {
			    color: startCompetition.hovered ? mainWindow.hovColor : mainWindow.bgColor

		  }
	  }

	  Button {
		  id: protocol
		  width: parent.width/4
		  height: 200

		  Image {
			  source: "../Img/protocol.png"
			  width: 48
			  height: 48
			  anchors.horizontalCenter: parent.horizontalCenter
			  anchors.verticalCenter: parent.verticalCenter

		  }

		  contentItem: Text{
			  text: "Отчет\nпо соревнованиям"
			  font.pointSize: 14
			  bottomPadding: 20
			  verticalAlignment: Text.AlignBottom
			  horizontalAlignment: Text.AlignHCenter
			  color: "White"
		  }

		  background: Rectangle {
			  color: protocol.hovered ? mainWindow.hovColor : mainWindow.bgColor
		  }
	  }

	  Button {
		  id: instruction
		  width: parent.width/4
		  height: 200

		  Image {
			  source: "../Img/instruction.png"
			  width: 48
			  height: 48
			  anchors.horizontalCenter: parent.horizontalCenter
			  anchors.verticalCenter: parent.verticalCenter
		  }

		  contentItem: Text{
			  text: "Документация"
			  font.pointSize: 14
			  bottomPadding: 20
			  verticalAlignment: Text.AlignBottom
			  horizontalAlignment: Text.AlignHCenter
			  color: "White"
		  }

		  background: Rectangle {
			  color: instruction.hovered ? mainWindow.hovColor : mainWindow.bgColor
		  }
	    }
	}
}
