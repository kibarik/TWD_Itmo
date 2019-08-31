import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Window 2.12
import "Sparring/"
import "OutMonitor/"
import "Tul/"
import "Categories/"
import "Share/"

/*
  подключение структуры
  из структуры вытащить все категории в список
  категория проведена - удалить элемент из списка
  список вида: < [туль, имя категории, участники], [спарринг, имя категории, участники] >

  Если туль: отдаем сигнал signalModeTul для туль
  Иначе: отдаем signalModeSparring для спарринга

  в Window для слота определяем логику:
    signalModeTul -> отображение Tul и OutMonitorTul
    signalModeSparring -> отображение Sparring и OutMonitorSparring

  Изменить порядок категорий можно из окна категорий

  https://evileg.com/ru/post/305/

*/

Window {
	id: mainQmlWindow
    width: 320
    height: 480
    visible: true
	minimumHeight: 480
	minimumWidth: 320
	maximumHeight: 480
	maximumWidth: 320

	//flags: Qt.FramelessWindowHint // Отключаем обрамление окна

	property string redParticipant: "Красный";
	property string blueParticipant: "Синий";
	property string nextParticipant1;
	property string nextParticipant2;
	property string nowCategoryName: "Выберите категорию";

/*===============Main Mode Windows=============================*/

    Sparring {
        id: sparringWindow
		visible: false

		onCategoryShow: {

			categoryWindow.show()
			mainQmlWindow.opacity = 0.0
		}
    }


	Tul {
		id: tulWindow
		visible: true
		onCategoryShow: {
			categoryWindow.show()
			mainQmlWindow.opacity = 0.0
		}
	}

/*===============Out Big monitors=============================*/

    OutMonitorSparring {
		id: monitorSparring
		visible: false
    }



    OutMonitorTul {
		id: monitorTul
		visible: true
    }

/*===============Control Windows=============================*/

	PairDisplay {
		id: pairDisplayShare
		visible: false

		onPairDisplayButtonClicked: {
			participantsWindow.show()
			participantsWindow.participantsNames = categoryAPI.setQmlParticipantsNames(mainQmlWindow.nowCategoryName)
			participantsWindow.categoryName = nowCategoryName
			participantsWindow.showParticipants()
		}
	}

    CategoryWindow {
        visible: false
        id: categoryWindow
        //flags: Qt.FramelessWindowHint // Отключаем обрамление окна

        onSignalExit: { //из Category.qml сигнал на возврат в гл. окно
			mainQmlWindow.opacity = 1.0
            categoryWindow.close()
        }

        onCategoryShow: {
            categoryWindow.showCategories()
        }

        onOpenParticipants: {
			participantsWindow.show()
			categoryWindow.close()
			//остальные действия прописаны в CategoryWindow control.onclicked
        }
    }

    ParticipantsWindow {
        visible: false
        id: participantsWindow
		flags: Qt.FramelessWindowHint // Отключаем обрамление окна

		onSignalExit: {
			categoryWindow.show()
			participantsWindow.close()
		}

		onSelectNowPair: {
			mainQmlWindow.opacity = 1.0
			participantsWindow.close()

			//устанавливаем имена участников на главном экране для "Сейчас"
			mainQmlWindow.redParticipant = participantNowPairPositions[0]
			mainQmlWindow.blueParticipant = participantNowPairPositions[1]

		}

		onSelectNextPair: {
			mainQmlWindow.opacity = 1.0
			participantsWindow.close()

			//устанавливаем имена участников на главном экране для "Следующие"
			mainQmlWindow.nextParticipant1 = participantNextPairPositions[0]
			mainQmlWindow.nextParticipant2 = participantNextPairPositions[1]

		}

		onMonitorSetTul: { //переключение монитора на туль
			console.log("Monitor set TUL")
			monitorTul.show()
			monitorSparring.close()

			sparringWindow.visible = false
			tulWindow.visible = true
		}

		onMonitorSetSparring: { //переключение монитора на спарринг
			console.log("Monitor set SPARRING")
			monitorTul.close()
			monitorSparring.show()

			sparringWindow.visible = true
			tulWindow.visible = false
		}
    }
}
