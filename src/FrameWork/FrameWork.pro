#-------------------------------------------------
#
# Project created by QtCreator 2018-06-02T17:35:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FrameWork
TEMPLATE = app
DESTDIR = ../../bin


SOURCES += main.cpp\
        mainwindow.cpp \
    dllmanager.cpp \
    treemanager.cpp

HEADERS  += mainwindow.h \
    dllmanager.h \
    treemanager.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc

RC_FILE = FrameWork.rc
