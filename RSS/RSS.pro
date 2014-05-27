#-------------------------------------------------
#
# Project created by QtCreator 2014-05-24T22:11:34
#
#-------------------------------------------------

QT += core
QT += gui
QT += webkitwidgets
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RSS
TEMPLATE = app

CONFIG += c++11
SOURCES += main.cpp\
        widget.cpp \
    xmlsimplehendler.cpp

HEADERS  += widget.h \
    xmlsimplehendler.h

FORMS    += widget.ui

OTHER_FILES += \
    ../build-RSS-Desktop_Qt_5_2_1_MinGW_32bit-Debug/sample1.rss \
    ../build-RSS-Desktop_Qt_5_2_1_MinGW_32bit-Debug/sample.rss
