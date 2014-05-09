QT += core
QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    doublylinkedlist.cpp \
    list.cpp \
    listelement.cpp \
    singlylinkedlist.cpp

HEADERS += \
    doublylinkedlist.h \
    list.h \
    listelement.h \
    singlylinkedlist.h \
    testDoubly.h \
    testSingly.h

