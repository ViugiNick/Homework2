QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 7homework3

TEMPLATE = app

CONFIG += c++11
SOURCES += main.cpp\
        widget.cpp \
    tictactoe.cpp

HEADERS  += widget.h \
    tictactoe.h \
    testTic.h

FORMS    += widget.ui
