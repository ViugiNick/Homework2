QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    pointerstack.cpp \
    arraystack.cpp \
    stack.cpp

HEADERS += \
    stack.h \
    pointerstack.h \
    arraystack.h \
    stackcalculatortest.h