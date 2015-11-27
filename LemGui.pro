#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T01:39:55
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LemGui
CONFIG   += console
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/myserver.cpp \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/mythread.cpp \
    control/controler.cpp \
    control/gamepads/dualshok3.cpp \
    control/gamepads/padreader.cpp \
    control/basecontroller.cpp \
    control/keyboard.cpp

HEADERS  += mainwindow.h \
    interfaces/socket/server/watek.h \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/myserver.h \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/mythread.h \
    control/controler.h \
    control/gamepads/dualshok3.h \
    control/gamepads/padreader.h \
    control/basecontroller.h \
    control/keyboard.h

FORMS    += mainwindow.ui
