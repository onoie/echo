
QT += widgets

HEADERS    = core.h \
             echointerface.h \
             sandboxinterface.h
SOURCES    = core.cpp \
             main.cpp

TARGET     = navikit
QMAKE_PROJECT_NAME = corewindow

win32 {
    CONFIG(debug, release|debug):DESTDIR = ../debug/
    CONFIG(release, release|debug):DESTDIR = ../release/
} else {
    DESTDIR    = ../
}
