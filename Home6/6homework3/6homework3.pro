QT       += core
QT       += testlib
QT       -= gui

TARGET = 6homework3
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    sharedpointer.h \
    testPointer.h
