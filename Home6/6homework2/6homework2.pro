#-------------------------------------------------
#
# Project created by QtCreator 2014-05-04T21:03:13
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 6homework2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    list.cpp \
    listelement.cpp \
    singlylinkedlist.cpp \
    uniquelist.cpp

HEADERS += \
    list.h \
    listelement.h \
    singlylinkedlist.h \
    uniquelist.h \
    uniquelisterrors.h \
    testuniquelist.h
