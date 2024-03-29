import QtQuick 2.5
import QtQuick.Window 2.0

Item {
	id: name
	width: 320



	Grid {
		id: judjesText
		width: 320
		height: 15
		columns: 5
		rows: 1

		Text {
			id: text1
			width: parent.width/5
			color: "#ffffff"
			text: qsTr("I")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

		Text {
			id: text2
			width: parent.width/5
			color: "#ffffff"
			text: qsTr("II")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

		Text {
			id: text3
			width: parent.width/5
			color: "#ffffff"
			text: qsTr("III")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

		Text {
			id: text4
			width: parent.width/5
			color: "#ffffff"
			text: qsTr("IV")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

		Text {
			id: text5
			width: parent.width/5
			color: "#ffffff"
			text: qsTr("V")
			verticalAlignment: Text.AlignVCenter
			horizontalAlignment: Text.AlignHCenter
		}

	}

	Grid {
		id: judjesPoints
		width: 320
		height: 25
		rows: 1
		columns: 10
		anchors.top: judjesText.bottom
		anchors.topMargin: 0

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Red"

			Text{
				id: j1rp
				color: "White"
                text: mainQmlWindow.server.qJudge1r;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Blue"

			Text{
				id: j1bp
				color: "White"
                text: mainQmlWindow.server.qJudge1b;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Red"

			Text{
				id: j2rp
				color: "White"
                text: mainQmlWindow.server.qJudge2r;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Blue"

			Text{
				id: j2bp
				color: "White"
                text: mainQmlWindow.server.qJudge2b;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Red"

			Text{
				id: j3rp
				color: "White"
                text: mainQmlWindow.server.qJudge3r;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Blue"

			Text{
				id: j3bp
				color: "White"
                text: mainQmlWindow.server.qJudge3b;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Red"

			Text{
				id: j4rp
				color: "White"
                text: mainQmlWindow.server.qJudge4r;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "Blue"

			Text{
				id: j4bp
				color: "White"
                text: mainQmlWindow.server.qJudge4b;
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "#ff0000"
			Text {
                id: j5rp
				color: "#ffffff"
                text: mainQmlWindow.server.qJudge5r
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				anchors.fill: parent
			}
		}

		Rectangle {
			width: parent.width/10
			height: parent.height
			color: "#0000ff"
			Text {
                id: j5bp
				color: "#ffffff"
                text: mainQmlWindow.server.qJudge5b
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
			}
		}
	}

}




















