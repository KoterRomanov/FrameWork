#-------------------------------------------------
#
# Project created by QtCreator 2018-06-07T21:29:07
#
#-------------------------------------------------

QT       += gui widgets

TARGET = Games
TEMPLATE = lib
DESTDIR = ../../bin

DEFINES += GAMESMODULE_LIBRARY

SOURCES += gamesmodule.cpp \
    lightgame.cpp

HEADERS += gamesmodule.h\
        gamesmodule_global.h \
        ../../shared/shared_module.h \
    lightgame.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
