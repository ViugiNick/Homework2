#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T02:20:38
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = 4homework1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    listelement.cpp \
    hashtable.cpp \
    singlylinkedlist.cpp \
    countinghash.cpp

HEADERS += \
    list.h \
    listelement.h \
    hashtable.h \
    singlylinkedlist.h \
    countinghash.h \
    testHashTable.h \
    hashtableinterface.h
