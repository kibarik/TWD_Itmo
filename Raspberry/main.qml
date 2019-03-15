import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Window 2.12
import "Sparring/"
import "OutMonitor/"
import "Tul/"


Window {
    id: name
    width: 320
    height: 480
    visible: true

    Sparring {
    }

    Tul {
        visible: false
    }

    OutMonitorSparring {
        visible: true
    }

    OutMonitorTul {
        visible: false
    }

}
