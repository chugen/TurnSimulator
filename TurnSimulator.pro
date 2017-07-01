#-------------------------------------------------
#
# Project created by QtCreator 2016-10-23T16:09:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TurnSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawframe.cpp \
    calcturn.cpp

HEADERS  += mainwindow.h \
    drawframe.h \
    calcturn.h

FORMS    += mainwindow.ui \
    drawframe.ui

