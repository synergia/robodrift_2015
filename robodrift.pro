#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T11:05:03
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = robodrift
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    team.cpp \
    category.cpp \
    addteam.cpp \
    pugixml.cpp \
    racewindow.cpp \
    resultswindow.cpp

HEADERS  += mainwindow.h \
    team.h \
    category.h \
    addteam.h \
    pugiconfig.hpp \
    pugixml.hpp \
    racewindow.h \
    resultswindow.h

FORMS    += mainwindow.ui \
    addteam.ui \
    racewindow.ui \
    resultswindow.ui

RESOURCES += \
    files.qrc
