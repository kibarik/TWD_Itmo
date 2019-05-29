import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
	id: rectangle
	 color: lightColor
	 width: parent.width
	 height: parent.height
	 border.width: 1
	 border.color: darkColor

  Button {
	  id: downloadParticipants
	  y: 25
	  width: 200
	  height: 40
	  text: qsTr("Выбрать таблицы участников")
	  anchors.left: parent.left
	  anchors.leftMargin: 50
  }

  Button {
	  id: donloadDjudges
	  x: 25
	  y: 25
	  width: 200
	  height: 40
	  text: qsTr("Выбрать таблицы судей")
	  anchors.right: parent.right
	  anchors.rightMargin: 50
  }

//  Grid{
//	  id: process
//	  anchors.top: downloadParticipants.bottom
//	  anchors.topMargin: 25
//	  anchors.bottom: parent.bottom
//	  anchors.right: parent.right
//	  anchors.rightMargin: 25
//	  anchors.left: parent.left
//	  anchors.leftMargin: 25
//	  rows: 4
//	  columns: 3

//	    Text {
//			width: 100
//			color: "#000000"
//			text: qsTr("Всего таблиц:")
//		}

//		Text {
//			id: allTablesParticipants
//			text: qsTr("No")
//		}

//		Text {
//			id: allTablesJudges
//			text: qsTr("No")
//		}

//		Text {
//			width: 100
//			text: qsTr("Кол-во участников/судей")
//		}

//		Text {
//			id: foundParticipants
//			width: 100
//			text: "No"
//		}

//		Text {
//			id: foundJudges
//			width: 100
//			text: "No"
//		}

//		Text {
//			width: 150
//			text: qsTr("Найденные клубы")
//		}


//    }


}

























/*##^## Designer {
	D{i:1;anchors_x:5}
}
 ##^##*/
