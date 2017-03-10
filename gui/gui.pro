#-------------------------------------------------
#
# Project created by QtCreator 2017-03-06T10:39:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
        wormswindow.cpp \
        ../engines/engine.cpp \
        ../engines/worms.cpp \
        ../engines/robots.cpp \
        ../gui_robots/robotswindow.cpp

HEADERS  += mainwindow.h \
        wormswindow.h \
        ../engines/engine.h \
        ../engines/worms.h \
        ../engines/robots.h \
        ../gui_robots/robotswindow.h

FORMS    += mainwindow.ui \
            wormswindow.ui \
        ../gui_robots/robotswindow.ui

