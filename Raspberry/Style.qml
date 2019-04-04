import QtQuick.Controls 2.0
import QtQuick 2.0

Button {
	id: control
	text: categoryName
	contentItem: Text {
		text: control.text
		font: control.font
		opacity: enabled ? 1.0 : 0.3
		color: control.down ? "#22313f" : "#696969"
		horizontalAlignment: Text.AlignHCenter
		verticalAlignment: Text.AlignVCenter
		elide: Text.ElideRight

	}
	background: Rectangle {
		implicitWidth: 320
		implicitHeight: 50
		opacity: enabled ? 1 : 0.3
		border.color: control.down ? "#FA8072" : "#696969"
		border.width: 1
	}
}
