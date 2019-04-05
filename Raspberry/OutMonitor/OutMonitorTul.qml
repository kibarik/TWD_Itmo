import QtQuick 2.0
import QtQuick.Window 2.12

/*
	на монитор выводится только общее количество, сколько судей за красного и за синего
	получив сигнал, слот направляет его в соответствующую колонку
	имена также, как в PairDisplay.qml


	QObject::connect(qml, SIGNAL(transmitOldText(QString)),
					 &ASD, SLOT(getOldText(QString)));

	https://habr.com/ru/post/171341/
	https://habr.com/ru/post/138837/
*/

Window {
	id: window
	width: Screen.width
	height: Screen.height
	x: 0
	y: 0
	color: "#000000"

	Row {
		id: participantNames
		width: parent.width
		height: parent.height/8
		anchors.top: categoryName.bottom

		Rectangle {
			width: parent.width/2
			height: parent.height
			color: "#ea2027"
			border.width: 4

			Text {
				id: blueName1
				color: "#ffffff"
				text: qsTr("Корчинский Дмитрий Андреевич\n'Орел' Калинингрдская область")
				wrapMode: Text.WordWrap
				fontSizeMode: Text.Fit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				anchors.leftMargin: 15
				anchors.fill: parent
				font.pixelSize: parent.height/3
				textFormat: Text.PlainText
				font.family: "Tahoma"
			}
		}

		Rectangle {
			width: parent.width/2
			height: parent.height
			color: "Blue"
			border.width: 4
			Text {
				id: blueName
				color: "#ffffff"
				text: qsTr("Ишманов Алексей Юрьевич \n 'Фанат' Ленинградская область")
				wrapMode: Text.WordWrap
				font.pixelSize: parent.height/3
				font.family: "Tahoma"
				anchors.leftMargin: 15
				textFormat: Text.PlainText
				fontSizeMode: Text.Fit
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}
	}

	Row {
		id: points
		width: parent.width
		anchors.bottom: parent.bottom
		anchors.top: participantNames.bottom

		Rectangle {
			id: rectangle2
			width: parent.width/3
			height: width
			color: "#ea2027"
			Text {
				id: redPoints
				color: "#ffffff"
				text: qsTr("0")
				fontSizeMode: Text.VerticalFit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				anchors.fill: parent
				font.pixelSize: parent.width/2
				font.family: "Times New Roman"
			}
		}
		Rectangle {
			id: rectangle
			width: parent.width/3
			height: width
			color: "#95a5a6"

			Text {
				id: otherPoint
				color: "#ffffff"
				text: qsTr("0")
				fontSizeMode: Text.VerticalFit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				anchors.fill: parent
				font.pixelSize: parent.width/2
				font.family: "Times New Roman"
			}
		}

		Rectangle {
			id: rectangle3
			width: parent.width/3
			height: width
			color: "#0000ff"
			Text {
				id: bluePoints
				color: "#ffffff"
				text: qsTr("0")
				fontSizeMode: Text.VerticalFit
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
				anchors.fill: parent
				font.pixelSize: parent.width/2
				font.family: "Times New Roman"
			}
		}
	}

	Rectangle {
		id: categoryName
		width: parent.width
		height: parent.height/8
		color: "#000000"
		anchors.top: parent.top
  anchors.topMargin: 0
        border.width: 2

		Text {
			id: element
			height: 100
			color: "#ffffff"
			text: qsTr("Туль Мальчики 14-17 лет 3 гуп - 1 дан")
			font.family: "Verdana"
			font.pixelSize: parent.height/3
			fontSizeMode: Text.Fit
			font.capitalization: Font.AllUppercase
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
			anchors.fill: parent
		}
	}


}









