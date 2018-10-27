#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T17:52:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoFilesBkup
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    auto_files_bkup/src/Transfer.cpp

HEADERS += \
        mainwindow.h \
    auto_files_bkup/src/helpers.hpp \
    /src/Transfer.hpp

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lboost_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lboost_system
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lboost_system

INCLUDEPATH += $$PWD/../../../usr/local/include/boost/system
DEPENDPATH += $$PWD/../../../usr/local/include/boost/system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/libboost_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/libboost_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/boost_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/boost_system.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/libboost_system.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/release/ -lboost_filesystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/local/lib/debug/ -lboost_filesystem
else:unix: LIBS += -L$$PWD/../../../usr/local/lib/ -lboost_filesystem

INCLUDEPATH += $$PWD/../../../usr/local/include/boost/filesystem
DEPENDPATH += $$PWD/../../../usr/local/include/boost/filesystem

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/libboost_filesystem.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/libboost_filesystem.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/release/boost_filesystem.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/debug/boost_filesystem.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/local/lib/libboost_filesystem.a
