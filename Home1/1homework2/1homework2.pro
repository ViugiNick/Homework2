QT += core
QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    arraystack.cpp \
    calculator.cpp \
    linkedstack.cpp \
    stackelement.cpp

HEADERS += \
    arraystack.h \
    calculator.h \
    linkedstack.h \
    stack.h \
    stackelement.h \
    testStack.h

