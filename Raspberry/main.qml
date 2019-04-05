import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Window 2.12
import "Sparring/"
import "OutMonitor/"
import "Tul/"
import "Categories/"

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
	id: mainWindow
    width: 320
    height: 480
    visible: true
	minimumHeight: 480
	minimumWidth: 320
	maximumHeight: 480
	maximumWidth: 320

    //flags: Qt.FramelessWindowHint // Отключаем обрамление окна

    Sparring {
        id: sparringWindow
		visible: false

        onCategoryShow: { // сигнал на отображение экрана категорий
            categoryWindow.show()
            mainWindow.opacity = 0.0
        }

    }

    OutMonitorSparring {
		visible: true
    }


    Tul {
		id: tulWindow
		visible: true

        onCategoryShow: { // сигнал на отображение экрана категорий
            categoryWindow.show()
            mainWindow.opacity = 0.0
        }
    }


    OutMonitorTul {
		visible: true
    }

    CategoryWindow {
        visible: false
        id: categoryWindow

        onSignalExit: { //из Category.qml сигнал на возврат в гл. окно
            mainWindow.opacity = 1.0
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

        onSignalExit: {
			categoryWindow.show()
			participantsWindow.close()
		}

		onSelectPair: {
			mainWindow.opacity = 1.0
			participantsWindow.close()
		//установить имена текущей и следующей пары
		//	sparringWindow.
		//	tulWindow.
		}

    }
}
