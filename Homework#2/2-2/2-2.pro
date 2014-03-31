TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    writer.cpp \
    ConsoleOut.cpp \
    FileOut.cpp

HEADERS += \
    writer.h \
    ConsoleOut.h \
    FileOut.h

