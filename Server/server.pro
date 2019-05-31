QT += quick xml
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        lib/competition.cpp \
        main.cpp \
        lib/category.cpp \
        lib/xmlio.cpp \
        sqldriver.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \

HEADERS += \
        lib/category.h \
        lib/competition.h \
        lib/xmlio.h \
        sqldriver.h

#icon for WINDOWS, LINUX, MACOS
win32: RC_ICONS = $$PWD/Img/logo.ico


#info for win
win32:{
    VERSION = 1.0.0
    QMAKE_TARGET_COMPANY = "AleksIshmanov and AleksMakurin"
    QMAKE_TARGET_PRODUCT = "Taekwon-Do server program"
    QMAKE_TARGET_DESCRIPTION = "Серверная часть программы для судейской системы Taekwon-Do ITF"
    QMAKE_TARGET_COPYRIGHT = "2Aleks"
}
