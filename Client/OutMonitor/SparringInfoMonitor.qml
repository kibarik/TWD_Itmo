import QtQuick 2.5
import QtQuick.Window 2.0


/*
	Из файла логику пультов cpp при присуждении баллов получаем сигналы
	signalRedPlus() signalBluePlus() и т.п.

	id: redPoints прописываем слота приема сигнала.
	Сигнал отдает баллы спортсмена, слот записывает в redPoints.texе


	QObject::connect(qml, SIGNAL(transmitOldText(QString)),
					 &ASD, SLOT(getOldText(QString)));


	https://habr.com/ru/post/171341/
	https://habr.com/ru/post/138837/

*/
Item {
	id: name
	width: parent.width
	//color: "#000"
	visible: true

	Grid {
		id: grid
		width: parent.width
		height: 200
		rows: 3
		columns: 6
		anchors.fill: parent

		Rectangle{
			color: "Black"
			width: parent.width/6
			height: parent.height/3

			Text {
				text: qsTr("Замечания")
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
				color: "#ffffff"
			}
		}

		Rectangle{
			color: "Black"
			width: parent.width/6
			height: parent.height/3
			Text {
				text: qsTr("Предупреждения")
				anchors.fill: parent
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle{
			color: "Black"
			width: parent.width/6
			height: parent.height/3

			Text {
				text: qsTr("I")
				anchors.fill: parent
				fontSizeMode: Text.Fit
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle{
			color: "Black"
			width: parent.width/6
			height: parent.height/3
			Text {
				text: qsTr("II")
				anchors.fill: parent
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle{
			color: "Black"
			width: parent.width/6
			height: parent.height/3

			Text {
				text: qsTr("III")
				anchors.fill: parent
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle{
			color: "Black"
			width: parent.width/6
			height: parent.height/3

			Text {
				text: qsTr("IV")
				anchors.fill: parent
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Red"
			border.width: 0
			width: parent.width/6
			height: parent.height/3
			Text {

				id: chuiR
                text: mainQmlWindow.server.qRedAdmonition;
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				anchors.fill: parent
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Red"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: gamjR
                text: mainQmlWindow.server.qRedWarning
				font.family: "Times New Roman"
				font.pointSize:parent.height/4>0 ? parent.height/4 : 10
				anchors.fill: parent
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}


		Rectangle {
			color: "Red"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: j1r //1 судья баллы красному
                text: mainQmlWindow.server.qJudge1r;
				anchors.fill: parent
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Red"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: j2r //2 судья баллы красному
                text: mainQmlWindow.server.qJudge2r;
				anchors.fill: parent
				fontSizeMode: Text.Fit
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Red"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: j3r //3 судья баллы красному
                text: mainQmlWindow.server.qJudge3r
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				anchors.fill: parent
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Red"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: j4r //1 судья баллы красному
                text: mainQmlWindow.server.qJudge4r
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				anchors.fill: parent
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}


		Rectangle {
			color: "Blue"
			border.width: 0
			width: parent.width/6
			height: parent.height/3
			Text {

				id: chuib
                text: mainQmlWindow.server.qBlueAdmonition;
				anchors.fill: parent
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Blue"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: gamjB
                text: mainQmlWindow.server.qBlueWarning;
				font.family: "Noto Sans"
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				anchors.fill: parent
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}


		Rectangle {
			color: "Blue"
			width: parent.width/6
			height: parent.height/3

			Text {
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				id: j1b //1 судья баллы красному
                text: mainQmlWindow.server.qJudge1b;
				anchors.fill: parent
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Blue"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: j2b //2 судья баллы красному
                text: mainQmlWindow.server.qJudge2b;
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				anchors.fill: parent
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Blue"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: j3b //3 судья баллы красному
                text: mainQmlWindow.server.qJudge3b;
				anchors.fill: parent
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				fontSizeMode: Text.Fit
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}

		Rectangle {
			color: "Blue"
			width: parent.width/6
			height: parent.height/3

			Text {
				id: j4b //1 судья баллы красному
                text: mainQmlWindow.server.qJudge4b;
				anchors.fill: parent
				fontSizeMode: Text.Fit
				font.pointSize: parent.height/4>0 ? parent.height/4 : 10
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				color: "#ffffff"
			}
		}


	}
}

























/*##^## Designer {
	D{i:13;anchors_height:22.222222222222225;anchors_width:109.05555555555556}
}
 ##^##*/
