QT       += core
QT       += testlib
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

SOURCES += main.cpp \
    tree.cpp

HEADERS += \
    treenode.h \
    devvertex.h \
    multvertex.h \
    sumvertex.h \
    negvertex.h \
    numvertex.h \
    tree.h \
    testTree.h

OTHER_FILES += \
    file.txt

