#-------------------------------------------------
#
# Project created by QtCreator 2014-05-05T15:28:44
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kr2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    game.h

FORMS    += mainwindow.ui \
    game.ui
