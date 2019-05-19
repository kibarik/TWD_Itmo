import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
	id: element
	width: parent.width
	height: parent.height
	//property var nowCategoryName: makeCompetition1Step.


	//property string step3_lightColor: ;

 Rectangle {
	 id: topPanel
	 height: 25
	 color: step3_headerColor
	 anchors.right: parent.right
	 anchors.left: parent.left
	 anchors.leftMargin: 0
	 anchors.top: parent.top
	 anchors.topMargin: 0

	 Text {
		 id: categoryName
		 color: "#ffffff"
		 text: qsTr("ИМЯ КАТЕГОРИИ")
		 //text: qsTr("")
		 fontSizeMode: Text.HorizontalFit
		 horizontalAlignment: Text.AlignHCenter
		 verticalAlignment: Text.AlignVCenter
		 anchors.fill: parent
	 }
 }

 Rectangle {
	 color: step3_backgroundColor
	 anchors.top: topPanel.bottom
	 anchors.right: parent.right
	 anchors.bottom: parent.bottom
	 anchors.left: parent.left

	 border.color: step3_headerColor
	 border.width: 1

	 ListView {
		 id: listView
		 anchors.fill: parent

		 delegate: Item { //содержание модели отображения
			 id: element1

			 Row {
				 height: 30
				 width: parent.width

				 Text {
					 text: num
					 font.pointSize: 14
					 verticalAlignment: Text.AlignVCenter
					 horizontalAlignment: Text.AlignHCenter
					 width: 20
					 height: parent.height
					 color: "#fff"
				 }


				 Button {
					 id: button
					 width: parent.width - 20

					 background: Rectangle {
						 color: button.hovered ? hovColor : lightColor

					 }

					 contentItem: Text {
						 id: name
						 text: categoryName
						 font.family: "Times New Roman"
						 font.pointSize: 14
						 verticalAlignment: Text.AlignVCenter
						 color: "#fff"

					 }

				 }


			 }

		 }

		 model: ListModel { //объявление модели
			 id: categoryList
			 //num, categoryName

			 ListElement {
				 categoryName: qsTr("")
				 num: 0
			 }
		 }
	 }
 }



}









































/*##^## Designer {
	D{i:1;anchors_width:200}D{i:3;anchors_height:615;anchors_width:360}
}
 ##^##*/
