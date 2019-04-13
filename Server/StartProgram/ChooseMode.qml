import QtQuick 2.9
import QtQuick.Window 2.2

Item {
	visible: true

	x: 0
	y: 0
	width: Screen.width
	height: Screen.height


	    Row {
			id: row
			width: parent.width
			height: 400
			anchors.bottom: parent.bottom

			Rectangle{
				color: "red"
				width: parent.width
				height: 400
			}
		}

 }
