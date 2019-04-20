import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
	id: element
	width: parent.width
	height: parent.height-50
	Grid {
		id: grid
		width: parent.width
		height: parent.height
		rows: 5
		columns: 2

		Label{
			width: 200
			height: 75
			color: "#ffffff"
			text: qsTr("1. Название соревнований")
			topPadding: 10
			verticalAlignment: Text.AlignVCenter
			leftPadding: 8
			font.bold: true
			font.pointSize: 12
			font.family: "Times New Roman"
			horizontalAlignment: Text.AlignLeft
		}

		TextArea {
			id: competitionName
			width: 500
			height: 75
			font.bold: true
			font.family: "Times New Roman"
			font.pointSize: 12
			wrapMode: Text.WordWrap
			horizontalAlignment: Text.AlignLeft
			placeholderText: "Введите название соревнований"
			color: "#fff"
			bottomPadding: 1
			topPadding: 10
			verticalAlignment: Text.AlignVCenter

		}


		Label{
			width: 200
			height: 50
			color: "#ffffff"
			text: qsTr("2. Уровень соревнований")
			leftPadding: 8
			font.capitalization: Font.MixedCase
			font.bold: true
			font.pointSize: 12
			font.family: "Times New Roman"
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignLeft
		}

		ComboBox {
			width: 300
			height: 50
			font.pointSize: 12
			font.family: "Times New Roman"
			model: ["1. Муниципальный", "2. Региональный","3. Межрегиональный", "4. Всероссийский", "5. Кубок", "6. Чемпионат и первенство"]
		}

		Label{
			width: 200
			height: 50
			color: "#ffffff"
			text: qsTr("3. Главный судья")
			leftPadding: 8
			font.capitalization: Font.MixedCase
			font.bold: true
			font.pointSize: 12
			font.family: "Times New Roman"
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignLeft
		}

		TextArea {
			id: competitionMainJudge
			width: 500
			height: 50
			font.bold: true
			font.family: "Times New Roman"
			font.pointSize: 12
			wrapMode: Text.WordWrap
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignLeft
			placeholderText: "Введите имя ответственного судьи"
			color: "#fff"

		}

		Label{
			width: 200
			height: 50
			color: "#ffffff"
			text: qsTr("4. Главный Бухгалтер")
			leftPadding: 8
			font.capitalization: Font.MixedCase
			font.bold: true
			font.pointSize: 12
			font.family: "Times New Roman"
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignLeft
		}

		TextArea {
			id: competitionMBookKeeper
			width: 500
			height: 50
			font.bold: true
			font.family: "Times New Roman"
			font.pointSize: 12
			wrapMode: Text.WordWrap
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignLeft
			placeholderText: "Введите имя ответственного судьи"
			color: "#fff"

		}

		Label{
			width: 200
			height: 50
			color: "#ffffff"
			text: qsTr("5. Город проведения")
			leftPadding: 8
			font.capitalization: Font.MixedCase
			font.bold: true
			font.pointSize: 12
			font.family: "Times New Roman"
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignLeft
		}

		TextArea {
			id: competitionTown
			width: 500
			height: 50
			font.bold: true
			font.family: "Times New Roman"
			font.pointSize: 12
			wrapMode: Text.WordWrap
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignLeft
			placeholderText: "Введите город проведения соревнований"
			color: "#fff"
		}

	}

}
















































































