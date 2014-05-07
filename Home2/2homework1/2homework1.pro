QT += core
QT += testlib

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    bsorter.cpp \
    qsorter.cpp

HEADERS += \
    bsorter.h \
    qsorter.h \
    sorter.h \
    testQSorter.h

