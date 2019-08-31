import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
	id: element
	property var step1_LabelWidth: 250;
	property var step1_InputWidth: 400;
	//property string nowCompetitionName: competitionName.text

	Rectangle {
		id: rectangle
		border.width: 2
		border.color: darkColor

		color: lightColor
		width: parent.width
		height: parent.height

		Grid {
			id: grid
			anchors.horizontalCenter: parent.horizontalCenter
			//width: step1_LabelWidth + step1_InputWidth
			height: 480
			rows: 5
			columns: 2



			Label{
				width: step1_LabelWidth
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
				width: step1_InputWidth;
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

				onEditingFinished: competitionData.name = competitionName.text
			}


			Label{
				width: step1_LabelWidth
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
				id: competitionLevel
				width: step1_InputWidth
				height: 50
				font.pointSize: 12
				font.family: "Times New Roman"
				model: ["1. Муниципальный", "2. Региональный","3. Межрегиональный", "4. Всероссийский", "5. Кубок", "6. Чемпионат и первенство"]
				onActivated: competitionData.level = competitionLevel.currentText;

			}

			Label{
				width: step1_LabelWidth
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
				width: step1_InputWidth
				height: 50
				font.bold: true
				font.family: "Times New Roman"
				font.pointSize: 12
				wrapMode: Text.WordWrap
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignLeft
				placeholderText: "Введите имя ответственного судьи"
				color: "#fff"
				onEditingFinished: competitionData.theJudge = competitionMainJudge.text

			}

			Label{
				width: step1_LabelWidth
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
				width: step1_InputWidth
				height: 50
				font.bold: true
				font.family: "Times New Roman"
				font.pointSize: 12
				wrapMode: Text.WordWrap
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignLeft
				placeholderText: "Введите имя ответственного судьи"
				color: "#fff"
				onEditingFinished: competitionData.bookkeeper = competitionMBookKeeper.text

			}

			Label{
				width: step1_LabelWidth
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
				id: competitionCity
				width: step1_InputWidth
				height: 50
				font.bold: true
				font.family: "Times New Roman"
				font.pointSize: 12
				wrapMode: Text.WordWrap
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignLeft
				placeholderText: "Введите город проведения соревнований"
				color: "#fff"
				onEditingFinished: competitionData.city = competitionCity.text
			}

		}

	}

}


/*##^## Designer {
	D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
