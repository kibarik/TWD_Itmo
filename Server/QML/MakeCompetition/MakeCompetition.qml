import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0

Rectangle{
	id: rectangle
	color: mainWindow.bgColor
	Button{
		id: close
		width: 50
		height: 50
		display: AbstractButton.IconOnly
		anchors.top: parent.top
		anchors.right: parent.right

		background: Rectangle {
			width: parent.width
			height: parent.height
			color: close.hovered ? mainWindow.hovColor : mainWindow.lightColor
			Image {
				source: "../../Img/close.png"
				height: parent.height
				width: parent.width

			}
		}

		onClicked: {
			createCompetitionWindow.visible=false
			choose.opacity = 1.0
			mainWindow.color = mainWindow.background
		}


	}

//Top_panel
 Rectangle {
	 id: topPanel
	 height: 50
	 color: mainWindow.lightColor
	 anchors.right: close.left
	 anchors.left: parent.left

	 Text {
		 color: "#ffffff"
		 text: qsTr("Меню создания соревнований")
		 font.weight: Font.Bold
		 horizontalAlignment: Text.AlignHCenter
		 renderType: Text.NativeRendering
		 fontSizeMode: Text.VerticalFit
		 font.pointSize: 12
		 font.family: "Tahoma"
		 verticalAlignment: Text.AlignVCenter
		 anchors.fill: parent


	 }

	 Button {
		 id: ok
		 height: 50
		 width: 150
		 anchors.right: parent.right

		 background: Rectangle {
			 color: ok.hovered ? "#3FC380" : "#03A678";
		 }

		 contentItem: Text {
			 text: qsTr("Сохранить")
			 font.pointSize: 12
			 font.family: "Times New Roman"
			 color: "white"
			 horizontalAlignment: Text.AlignHCenter
			 verticalAlignment: Text.AlignVCenter
			 elide: Text.ElideRight

		 }
	 }
 }

//Left Menu
 function selectChecked(num){
	 console.log("Switch ", num);

	 switch (num) {
	    case 1: competitionInfo.checked = true;
			    categoryModel.checked = false;
			    showCategory.checked = false;
			    judges.checked = false;
			    downloadParticipants.checked = false;

			    makeCompetition1Step.visible = true;
			    makeCompetition2Step.visible = false;
			    makeCompetition3Step.visible = false;

//			    smallLeftPanel.visible = false;
//			    leftMenu.visible = true
		break;

		case 2:
			competitionInfo.checked = false;
			categoryModel.checked = true;
			showCategory.checked = false;
			judges.checked = false;
			downloadParticipants.checked = false;

			makeCompetition1Step.visible = false;
			makeCompetition2Step.visible = true;
			makeCompetition3Step.visible = false

//			smallLeftPanel.visible = true;
//			leftMenu.visible = false

		break;

		case 3:
			competitionInfo.checked = false;
			categoryModel.checked = false;
			showCategory.checked = true;
			judges.checked = false;
			downloadParticipants.checked = false;

			makeCompetition1Step.visible = false;
			makeCompetition2Step.visible = false;
			makeCompetition3Step.visible = true

//			smallLeftPanel.visible = true;
//			leftMenu.visible = false;
		break;

		case 4:
			competitionInfo.checked = false;
			categoryModel.checked = false;
			showCategory.checked = false;
			judges.checked = true;
			downloadParticipants.checked = false;
		break;

		case 5:
			competitionInfo.checked = false;
			categoryModel.checked = false;
			showCategory.checked = false;
			judges.checked = false;
			downloadParticipants.checked = true;
		break;
	 }
 }

 Column {

	 id: leftMenu
	 width: 200
	 height: parent.height - topPanel.height
	 anchors.left: parent.left
	 anchors.leftMargin: 0
	 anchors.top: topPanel.bottom

	 Button {
		 id: competitionInfo
		 width: parent.width
		 height: 50
		 checked: true


		 background: Rectangle {
			 color: competitionInfo.checked ? mainWindow.hovColor : mainWindow.bgColor
			 border.width: competitionInfo.hovered ? 1 : 0
			 border.color: "#fff"
		 }

		 Text {
			 color: "#d9d9d9"
			 text: qsTr("1. Сведения")
			 anchors.leftMargin: 10
			 font.bold: true
			 font.weight: Font.Bold
			 horizontalAlignment: Text.AlignLeft
			 font.pointSize: 12
			 font.family: "Times New Roman"
			 renderType: Text.NativeRendering
			 verticalAlignment: Text.AlignVCenter
			 anchors.fill: parent
		 }

		 onClicked: {
			 selectChecked(1);
		 }

	 }

	 Button {
		 id: categoryModel
		 width: parent.width
		 height: 50
		 checkable: true

		 background: Rectangle {
			 color: categoryModel.checked ? mainWindow.hovColor : mainWindow.bgColor
			 border.width: categoryModel.hovered ? 1 : 0
			 border.color: "#fff"
		 }

		 Text {
			 color: "#d9d9d9"
			 text: qsTr("2. Модель категорий")
			 anchors.leftMargin: 10
			 font.bold: true
			 font.weight: Font.Bold
			 horizontalAlignment: Text.AlignLeft
			 font.pointSize: 12
			 font.family: "Times New Roman"
			 renderType: Text.NativeRendering
			 verticalAlignment: Text.AlignVCenter
			 anchors.fill: parent
		 }

		 onClicked: {
			 selectChecked(2);
		 }
	 }

	 Button {
		 id: showCategory
		 width: parent.width
		 height: 50
		 checkable: true

		 background: Rectangle {
			 color: showCategory.checked ? mainWindow.hovColor : mainWindow.bgColor
			 border.width: showCategory.hovered ? 1 : 0
			 border.color: "#fff"
		 }

		 Text {
			 color: "#d9d9d9"
			 text: qsTr("3. Просмотр категорий")
			 anchors.leftMargin: 10
			 font.bold: true
			 font.weight: Font.Bold
			 horizontalAlignment: Text.AlignLeft
			 font.pointSize: 12
			 font.family: "Times New Roman"
			 renderType: Text.NativeRendering
			 verticalAlignment: Text.AlignVCenter
			 anchors.fill: parent
		 }

		 onClicked: {
			selectChecked(3);
		 }
	 }

	 Button {
		 id: judges
		 width: parent.width
		 height: 50
		 checkable: true

		 background: Rectangle {
			 color: judges.checked ? mainWindow.hovColor : mainWindow.bgColor
			 border.width: judges.hovered ? 1 : 0
			 border.color: "#fff"
		 }

		 Text {
			 color: "#d9d9d9"
			 text: qsTr("4. Судьи")
			 anchors.leftMargin: 10
			 font.bold: true
			 font.weight: Font.Bold
			 horizontalAlignment: Text.AlignLeft
			 font.pointSize: 12
			 font.family: "Times New Roman"
			 renderType: Text.NativeRendering
			 verticalAlignment: Text.AlignVCenter
			 anchors.fill: parent
		 }

		 onClicked: {
			selectChecked(4);
		 }
	 }

	 Button {
		 id: downloadParticipants
		 width: parent.width
		 height: 50
		 checkable: true

		 background: Rectangle {
			 color: downloadParticipants.checked ? mainWindow.hovColor : mainWindow.bgColor
			 border.width: downloadParticipants.hovered ? 1 : 0
			 border.color: "#fff"
		 }

		 Text {
			 color: "#d9d9d9"
			 text: qsTr("5. Загрузка заявок")
			 anchors.leftMargin: 10
			 font.bold: true
			 font.weight: Font.Bold
			 horizontalAlignment: Text.AlignLeft
			 font.pointSize: 12
			 font.family: "Times New Roman"
			 renderType: Text.NativeRendering
			 verticalAlignment: Text.AlignVCenter
			 anchors.fill: parent
		 }

		 onClicked: {
			selectChecked(5);
		 }
	 }
 }

 //-------<SmallPanel>

// MC_smallLeftPanel {
//	id: smallLeftPanel
//	visible: false
//	width: 50
//	height: leftMenu.height
//	anchors.left: parent.left
//	anchors.leftMargin: 0
//    anchors.top: topPanel.bottom

// }

//-------------<Steps>
 MC_Step1info {
	 id: makeCompetition1Step
	 anchors.left: leftMenu.right
	 anchors.top: topPanel.bottom
	 anchors.right: parent.right
 }

 MC_Step2Category {
	 id: makeCompetition2Step
	 visible: false
	 height: parent.height - topPanel.height
	 anchors.left: leftMenu.right
	 anchors.top: topPanel.bottom
	 anchors.bottom: parent.bottom
 }

 MC_Step3Participants {
	 id: makeCompetition3Step
	 visible: false
	 anchors.left: leftMenu.right
	 anchors.top: topPanel.bottom
	 anchors.right: parent.right
 }



}






















/*##^## Designer {
	D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
