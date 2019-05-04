import QtQuick 2.0
import QtQuick.Controls 2.0

//import FileIO 1.0
//import XmlIO 1.0
import Category 1.0

Item {
	property string step2_NameColor: "#22313F"
	property string step2_ColumnColor: "#34495E"

	width: 824
	height: 550
//---------------функции---------------------//
	function showSparringOption (num)  {
		if (num === 1) sparringOption.visible = true
		else sparringOption.visible = false
	}

	function setMode(num) { //устанавливаем мод, обязательно избежать двойного выбор. Иначе могут быть баги
		switch (num) {
		    case 0:
				tempCategory.mode = "Туль личный";
				tul_team.checked = false;
				sparring_self.checked = false;
				sparring_team.checked = false;
				sparring_traditional.checked = false;
				kick.checked = false;
				specTech.checked = false;



			break;

			case 1:
				tempCategory.mode = "Туль командный";
				tul_self.checked = false;
				sparring_self.checked = false;
				sparring_team.checked = false;
				sparring_traditional.checked = false;
				kick.checked = false;
				specTech.checked = false;

			break;

			case 2:
				tempCategory.mode = "Спарринг личный";
				tul_self.checked = false;
				tul_team.checked = false;
				sparring_team.checked = false;
				sparring_traditional.checked = false;
				kick.checked = false;
				specTech.checked = false;
			break;

			case 3:
				tempCategory.mode = "Спарринг коммандный";
				tul_self.checked = false;
				tul_team.checked = false;
				sparring_self.checked = false;
				sparring_traditional.checked = false;
				kick.checked = false;
				specTech.checked = false;

			break;

			case 4:	tempCategory.mode = "Спарринг традиц." ;
				tul_self.checked = false;
				tul_team.checked = false;
				sparring_self.checked = false;
				sparring_team.checked = false;
				kick.checked = false;
				specTech.checked = false;
			break;

			case 5:
				tempCategory.mode = "Силовое разбивание";
				tul_self.checked = false;
				tul_team.checked = false;
				sparring_self.checked = false;
				sparring_team.checked = false;
				sparring_traditional.checked = false;
				specTech.checked = false;
			break;

			case 6:	tempCategory.mode = "Спец.техника";
				tul_self.checked = false;
				tul_team.checked = false;
				sparring_self.checked = false;
				sparring_team.checked = false;
				sparring_traditional.checked = false;
				kick.checked = false;
			break;

		}
	}

//----------------------------------------------

//	FileIO { //объект ввода и вывода
//		id: tempFile
//		source: "temp.csv"
//		onError: console.log(msg)
//	}

//	XmlIO {
//		id: xmlFile
//		source: "category.xml"
//		onError: console.log(msg)
//	}

	Category { //структура из category.h сохраняет параметры до СОХРАНЕНИЯ, В последующем передает их в XML в ПЗУ
		id: tempCategory;
		gender: man.checked ? "м." : "ж."

		onCategoryChanged: console.log("Parameter changed: ", what)
	}

	Column {
		id: col12
		width: 200
		height: parent.height
		anchors.left: parent.left
		anchors.top: parent.top

		Rectangle{
			id: age_name
			height: 25; width: parent.width
			color: step2_NameColor

			Text {
				text: qsTr("1. Возраст")
				font.bold: true
				anchors.fill: parent
				font.pointSize: 15
				font.family: "Times New Roman"
				color: "white"
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}

		}

		Rectangle{
			id: age
			width: parent.width;
			height: (parent.height - age_name.height)/3
			color: step2_ColumnColor
			border.width: 1
			border.color: step2_NameColor

			TextField {
				id: yearFrom
				x: 10
				y: 10
				width: parent.width -20
				height: 40
				font.pointSize: 8
				horizontalAlignment: Text.AlignHCenter
				placeholderText: "Год от (пример: 2002)"

				onEditingFinished: {
					tempCategory.yearFrom = yearFrom.text
				}
			}

			MouseArea{
				id: test
			}

			TextField {
				id: yearTo
				x: 10
				y: 60
				width: parent.width - 20
				height: 40
				font.pointSize: 8
				horizontalAlignment: Text.AlignHCenter
				placeholderText: "Год до (пример: 2005)"

				onEditingFinished: {
					tempCategory.yearTo = yearTo.text
				}
			}
		}

		Rectangle{
			id: gender
			height: age_name.height; width: parent.width
			color: step2_NameColor

			Text {
				text: qsTr("2. Пол")
				font.bold: true
				anchors.fill: parent
				font.pointSize: 15
				font.family: "Times New Roman"
				color: "white"
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}

		}

		Rectangle {
			width: parent.width;
			height: parent.height-age.height-age_name.height-gender.height
			color: step2_ColumnColor
			border.width: 1
			border.color: step2_NameColor

			CheckBox {
				id: man
				x: 5
				y: 10
				width: 140
				height: 40
				text: "Мужской"

				checked: woman.checked ? false : true

				contentItem: Text {
					text: man.text
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					elide: Text.ElideRight
				}
			}

			CheckBox {
				id: woman
				x: 5
				y: 60
				width: 140
				height: 40
				text: qsTr("Женский")
				checked: man.checked ? false : true

				contentItem: Text {
					text: woman.text
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					elide: Text.ElideRight

				}
			}
		}
	}


	Column {
		id: col3
		width: 200
		height: parent.height
		anchors.left: col12.right
		anchors.top: parent.top

		Rectangle{
			id: chooseMod_name
			height: 25; width: parent.width
			color: step2_NameColor

			Text {
				text: qsTr("3. Тип категории")
				font.bold: true
				anchors.fill: parent
				font.pointSize: 15
				font.family: "Times New Roman"
				color: "white"
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}
		}

		Rectangle{
			//id: age
			width: parent.width; height: (parent.height - age_name.height)
			color: step2_ColumnColor
			border.width: 1
			border.color: step2_NameColor


			CheckBox {
				id: tul_self
				x: 5
				y: 10
				width: parent.width - 10
				height: 40
				text: qsTr("Туль личный")
				checked: true;

				//checked: man.checked ? false : true

				contentItem: Text {
					width: 191
					text: tul_self.text
					anchors.leftMargin: 45
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					elide: Text.ElideRight
					font.family: "Times New Roman"
					font.pointSize: 12

				}

				onClicked: {
					showSparringOption(0);
					setMode(0);
				}
			}

			CheckBox {
				id: tul_team
				x: 5
				y: 60
				width: parent.width - 10
				height: 40
				text: qsTr("Туль командный")
				//checked: man.checked ? false : true

				contentItem: Text {
					text: tul_team.text
					anchors.leftMargin: 45
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					elide: Text.ElideRight
					font.family: "Times New Roman"
					font.pointSize: 12
				}

				onClicked: {
					showSparringOption(0);
					//tul_team.checked? setMode(1) : setMode(-1);
					setMode(1)
				}
			}

			Rectangle {
				color: step2_NameColor
				width: parent.width
				height: 2
				y: tul_team.y+43
			}

			CheckBox {
				id: sparring_self
				x: 5
				y: 110
				width: parent.width - 10
				height: 40
				text: qsTr("Спарринг личный")
				//checked: man.checked ? false : true

				contentItem: Text {
					text: sparring_self.text
					anchors.leftMargin: 45
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					elide: Text.ElideRight
					font.family: "Times New Roman"
					font.pointSize: 12
				}

				onClicked: {
					sparring_self.checked ? showSparringOption(1) : showSparringOption(0)
					setMode(2)
				}
			}

			CheckBox {
				id: sparring_team
				x: 5
				y: 160
				width: parent.width - 10
				height: 40
				text: qsTr("Спарринг командный")
				//checked: man.checked ? false : true

				contentItem: Text {
					text: sparring_team.text
					anchors.leftMargin: 45
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignRight
					verticalAlignment: Text.AlignVCenter
					elide: Text.ElideRight
					font.family: "Times New Roman"
					font.pointSize: 11

				}

				onClicked: {
					showSparringOption(0)
					setMode(3)
				}
			}

			CheckBox {
				id: sparring_traditional
				x: 5
				y: 210
				width: parent.width - 10
				height: 40
				text: qsTr("Спарринг традиц.")
				//checked: man.checked ? false : true

				contentItem: Text {
					text: sparring_traditional.text
					anchors.leftMargin: 45
					style: Text.Normal
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					font.family: "Times New Roman"
					font.pointSize: 12
				}

				onClicked: {
					setMode(4)
					showSparringOption(0)
				}
			}

			Rectangle {
				color: step2_NameColor
				width: parent.width
				height: 2
				y: sparring_traditional.y+43
			}

			CheckBox {
				id: kick
				x: 5
				y: 260
				width: parent.width - 10
				height: 40
				text: qsTr("Силовое разбивание")
				//checked: man.checked ? false : true

				contentItem: Text {
					text: kick.text
					anchors.leftMargin: 45
					style: Text.Normal
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					font.family: "Times New Roman"
					font.pointSize: 12

				}

				onClicked: {
					showSparringOption(0);
					setMode(5)
				}
			}

			CheckBox {
				id: specTech
				x: 5
				y: 310
				width: parent.width - 10
				height: 40
				text: qsTr("Спец. техника")
				//checked: man.checked ? false : true

				contentItem: Text {
					text: specTech.text
					anchors.leftMargin: 45
					style: Text.Normal
					font.pointSize: 12
					anchors.fill: parent
					color: '#fff'
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter

				}


				onClicked: {
					showSparringOption(0);
					setMode(6)
				}
			}
		}
	}

	Column {
		width: 200
		height: parent.height
		anchors.left: col3.right
		anchors.top: parent.top
		id: col4

		Rectangle{
			id: gup_name
			height: 25; width: parent.width
			color: step2_NameColor

			Text {
				text: qsTr("4. Пояс")
				font.bold: true
				anchors.fill: parent
				font.pointSize: 15
				font.family: "Times New Roman"
				color: "white"
				horizontalAlignment: Text.AlignHCenter
				verticalAlignment: Text.AlignVCenter
			}
		}

		Rectangle{
			//id: age
			width: parent.width; height: (parent.height - age_name.height)
			color: step2_ColumnColor
			border.width: 1
			border.color: step2_NameColor

			TextField {
				id: belt_from
				width: 93
				height: 30
				horizontalAlignment: Text.AlignHCenter
				font.pointSize: 9
				placeholderText: "Пояс от:"
				x: 5
				y: 10

				onEditingFinished: {
					//tempCategory. .yearFrom = belt_from.text
				}
			}

			CheckBox {
				id: is_gup_from
				x: 104
				y: 5
			}

			Text {
				text: qsTr("Гуп")
				font.pixelSize: 12
				color: "#fff"
				x: 118
				y: 40
			}

			CheckBox {
				id: is_dan_from
				x: 150
				y: 5

			}

			Text {
				x: 163
				y: 40
				text: qsTr("Дан")
				font.pixelSize: 12
				color: "#fff"
			}


			TextField {
				id: belt_to
				width: 93
				height: 30
				horizontalAlignment: Text.AlignHCenter
				font.pointSize: 9
				placeholderText: "Пояс до:"
				x: 5
				y: 62
			}

			CheckBox {
				id: is_gup_to
				x: 104
				y: 57
			}

			Text {
				text: qsTr("Гуп")
				font.pixelSize: 12
				color: "#fff"
				x: 118
				y: 92
			}

			CheckBox {
				id: is_dan_to
				x: 150
				y: 57

			}

			Text {
				x: 163
				y: 92
				text: qsTr("Дан")
				font.pixelSize: 12
				color: "#fff"
			}

			Item {
				visible: false

				id: sparringOption
				width: parent.width
				height: parent.height*2/3
				y: parent.height/3

				Rectangle{
					height: age_name.height; width: parent.width
					color: step2_NameColor

					Text {
						text: qsTr("4.1. Вес (спарринг)")
						font.bold: true
						anchors.fill: parent
						font.pointSize: 15
						font.family: "Times New Roman"
						color: "white"
						horizontalAlignment: Text.AlignHCenter
						verticalAlignment: Text.AlignVCenter
					}
				}

				TextField {
					width: parent.width/3
					id: weight_from
					x: 25
					y: 30
					placeholderText: "Вес от"
					font.pointSize: 8
					padding: 6
					horizontalAlignment: Text.AlignHCenter
				}

				Text {
					x: 97
					y: 35
					width: 8
					height: 40
					text: qsTr("-")
					verticalAlignment: Text.AlignVCenter
					font.pixelSize: 20
				}

				TextField {
					width: parent.width/3
					id: weight_to
					x: weight_from.x + weight_from.width + 20
					y: weight_from.y
					placeholderText: "Вес до"
					font.pointSize: 8
					padding: 6
					horizontalAlignment: Text.AlignHCenter
				}

//раунды
				Rectangle{
					id: rounds
					height: age_name.height; width: parent.width
					color: step2_NameColor
					y: weight_from.height + weight_from.y + 10

					Text {
						text: qsTr("4.2. Раунды")
						font.bold: true
						anchors.fill: parent
						font.pointSize: 15
						font.family: "Times New Roman"
						color: "white"
						horizontalAlignment: Text.AlignHCenter
						verticalAlignment: Text.AlignVCenter
					}
				}
//раунды от
				TextField {
					width: parent.width/3
					id: rounds_standart
					x: 25
					y: rounds.y + rounds.height + 5
					placeholderText: "1"
					font.pointSize: 14
					padding: 6
					horizontalAlignment: Text.AlignHCenter
				}

				Text {
					x: rounds_standart.x
					y: rounds_standart.y + rounds_standart.height + 2
					text: qsTr("Стандартный")
					color: "#fff"
				}

				Text {
					x: rounds_standart.x + rounds_standart.width + 4
					y: rounds_standart.y
					height: 40
					text: qsTr("И")
					verticalAlignment: Text.AlignVCenter
					font.pointSize: 12
					color: "#fff"
				}

				TextField {
					width: parent.width/3
					id: rounds_final
					x: rounds_standart.x + rounds_standart.width + 20
					y: rounds_standart.y
					placeholderText: "2"
					font.pointSize: 14
					padding: 6
					horizontalAlignment: Text.AlignHCenter
				}


				Text {
					x: rounds_final.x + 5
					y: rounds_standart.y + rounds_standart.height + 2
					text: qsTr("Финальный")
					color: "#fff"
				}

//настройка времени
				Rectangle{
					id: time
					x: 0
					y: rounds_standart.y + rounds.height + 35
					height: age_name.height; width: parent.width
					color: step2_NameColor

					Text {
						text: qsTr("4.3. Время")
						font.bold: true
						anchors.fill: parent
						font.pointSize: 15
						font.family: "Times New Roman"
						color: "white"
						horizontalAlignment: Text.AlignHCenter
						verticalAlignment: Text.AlignVCenter
					}

				}

//время стандартное
				TextField {
					id: rounds_min_from
					x: 25
					y: time.y + time.height + 5
					width: 40
					placeholderText: "1"
					//id: rounds_to
					font.pointSize: 14
					padding: 6
					horizontalAlignment: Text.AlignHCenter
				}

				Text {
					x: rounds_min_from.x + rounds_min_from.width + 2
					y: rounds_min_from.y
					width: 13
					height: 40
					text: qsTr(":")
					verticalAlignment: Text.AlignVCenter
					font.pixelSize: 22
				}

				TextField {
					id: rounds_sec_from
					x: rounds_min_from.x + rounds_min_from.width + 12
					y: rounds_min_from.y
					width: 80
					height: 40
					placeholderText: "30"
					font.pointSize: 14
					horizontalAlignment: Text.AlignHCenter
					padding: 6
				}

				Text {
					x: rounds_sec_from.x + rounds_sec_from.width
					y: rounds_min_from.y
					width: 25
					height: 40
					color: "#ffffff"
					text: qsTr("Стандарт")
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					font.pixelSize: 9
					rotation: 90
				}


//время финальное
				TextField {
					id: rounds_min_final
					x: 25
					y: rounds_min_from.y + rounds_min_from.height + 4
					width: 40
					placeholderText: "2"
					//id: rounds_to
					font.pointSize: 14
					padding: 6
					horizontalAlignment: Text.AlignHCenter
				}

				Text {
					x: rounds_min_from.x + rounds_min_from.width + 2
					y: rounds_min_final.y
					width: 13
					height: 40
					text: qsTr(":")
					verticalAlignment: Text.AlignVCenter
					font.pixelSize: 22
				}

				TextField {
					id: rounds_sec_final
					x: rounds_min_from.x + rounds_min_from.width + 12
					y: rounds_min_final.y
					width: 80
					height: 40
					placeholderText: "00"
					font.pointSize: 14
					horizontalAlignment: Text.AlignHCenter
					padding: 6
				}

				Text {
					x: rounds_sec_from.x + rounds_sec_from.width
					y: rounds_min_final.y
					width: 25
					height: 40
					color: "#ffffff"
					text: qsTr("Финал")
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
					font.pixelSize: 11
					rotation: 90
				}
			}
		}
	}


	Column {
		height: parent.height
		anchors.right: parent.right
		anchors.left: col4.right
		anchors.top: parent.top
		id: col5

		    Rectangle{
				id: options_name
				height: 25; width: parent.width
				color: step2_NameColor

				Text {
					text: qsTr("5. Доп. функции")
					font.bold: true
					anchors.fill: parent
					font.pointSize: 15
					font.family: "Times New Roman"
					color: "white"
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
				}
			}

			Rectangle {
				width: parent.width; height: (parent.height - options_name.height)
				color: step2_ColumnColor
				border.width: 1
				border.color: step2_NameColor

				Text {
					width: parent.width
					height: parent.height
					color: "#ffffff"
					text: "Я пока еще думаю над экраном для Raspberry. Если будет 7-10 дюймовый экран, то можно прям на клиенте отображать сетку участников и все функции жеребьевки скинуть на судей. Если останется 3.5 TFT, то надо научить систему жеребить с дополнительными функциями : дивизионы по 4 человека, 2 третьих места, крговая система, командная система, спец. техника и т.п."
					font.pointSize: 14
					verticalAlignment: Text.AlignVCenter
					horizontalAlignment: Text.AlignLeft
					wrapMode: Text.WordWrap
				}
			}


	}
}
