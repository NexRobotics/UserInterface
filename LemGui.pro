#-------------------------------------------------
#
# Project created by QtCreator 2015-11-02T01:39:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LemGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    socket/socketserver.cpp

HEADERS  += mainwindow.h \
    socket/socketserver.h

FORMS    += mainwindow.ui
