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
    interfaces/socket/server/dialog_server.cpp \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/myserver.cpp \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/mythread.cpp \
    interfaces/socket/server/server.cpp

HEADERS  += mainwindow.h \
    interfaces/socket/server/dialog_server.h \
    interfaces/socket/server/watek.h \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/myserver.h \
/home/wojtekl/programowanie/Qt/LemGui/interfaces/socket/server/mythread.h \
    interfaces/socket/server/server.h

FORMS    += mainwindow.ui \
    interfaces/socket/server/dialog_server.ui \
    interfaces/socket/server/dialog.ui
