import QtQuick 2.5
import QtQuick.Window 2.0

/*
	на монитор выводится только общее количество, сколько судей за красного и за синего
	получив сигнал, слот направляет его в соответствующую колонку
	имена также, как в PairDisplay.qml


	QObject::connect(qml, SIGNAL(transmitOldText(QString)),
					 &ASD, SLOT(getOldText(QString)));

	https://habr.com/ru/post/171341/
	https://habr.com/ru/post/138837/
*/

Item {
	id: name
	width: 320
	height: 100

	Grid {
		id: chui
		width: 320
		height: 50
		rows: 2
		columns: 3

		Rectangle {
			width: 50
			height: chui.height/2
			color: "#ea2027"
			Text {
				id: redChui
				color: "#ffffff"
				text: qsTr("0")
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}

		Rectangle {
			width: 220
			height: chui.height/2
			color: "#34495e"
			Text {
				id: vlavla
				width: 320
				color: "#ffffff"
				text: qsTr("Замечание")
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}

		}

		Rectangle {
			width: 50
			height: chui.height/2
			color: "#0652dd"
			Text {
				id: blueChui
				color: "#ffffff"
                text: "0";
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}

		Rectangle {
			width: 50
			height: chui.height/2
			color: "#ea2027"
			Text {
				id: redGamj
				color: "#ffffff"
				text: qsTr("0")
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}

		Rectangle {
			width: 220
			height: chui.height/2
			color: "#34495e"
			Text {
				id: name2
				color: "#ffffff"
				text: qsTr("Предупреждение")
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}

		Rectangle {
			width: 50
			height: chui.height/2
			color: "#0652dd"
			    Text {
					id: blueGamj
					color: "#ffffff"
					text: qsTr("0")
					anchors.fill: parent
					verticalAlignment: Text.AlignVCenter
					horizontalAlignment: Text.AlignHCenter
				}
		    }

	}
	Grid {
		id: judjesText
		width: 320
		height: 15
		anchors.top: chui.bottom
		anchors.topMargin: 0
		columns: 4
		rows: 1

		Text {
			id: text1
			width: parent.width/4
			color: "#ffffff"
			text: qsTr("I")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

		Text {
			id: text2
			width: parent.width/4
			color: "#ffffff"
			text: qsTr("II")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

		Text {
			id: text3
			width: parent.width/4
			color: "#ffffff"
			text: qsTr("III")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

		Text {
			id: text4
			width: parent.width/4
			color: "#ffffff"
			text: qsTr("IV")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

	}

	Grid {
		id: judjesPoints
		width: 320
		height: 25
		rows: 1
		columns: 8
		anchors.top: judjesText.bottom
		anchors.topMargin: 0

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "Red"

			Text{
				id: j1rp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "Blue"

			Text{
				id: j1bp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "#ea2027"

			Text{
				id: j2rp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "#0652dd"

			Text{
				id: j2bp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "#ea2027"

			Text{
				id: j3rp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "#0652dd"

			Text{
				id: j3bp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "Red"

			Text{
				id: j4rp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/8
			height: parent.height
			color: "Blue"

			Text{
				id: j4bp
				color: "White"
				text: qsTr("0")
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}
	}

}
