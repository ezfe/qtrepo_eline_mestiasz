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
        ../engines/engine.cpp \
        ../engines/worms.cpp \
        ../engines/robots.cpp \
        ../gui_robots/robotswindow.cpp \
        ../gui_worms/wormswindow.cpp \
        ../game_history/playergamehistory.cpp \
        ../game_history/game.cpp \
        ../game_history/player.cpp \
        ../game_history/gamehistory.cpp \
        ../game_history/dbtable.cpp \
        ../game_history/dbtablegames.cpp \
        ../game_history/dbtableplayers.cpp \
        ../game_history/dbtool.cpp \
    addplayerwindow.cpp \
    topplayerswindow.cpp

LIBS +=  -l sqlite3

HEADERS  += mainwindow.h \
        ../engines/engine.h \
        ../engines/worms.h \
        ../engines/robots.h \
        ../gui_robots/robotswindow.h \
        ../gui_worms/wormswindow.h \
        ../game_history/playergamehistory.h \
        ../game_history/game.h \
        ../game_history/player.h \
        ../game_history/gamehistory.h \
        ../game_history/dbtable.h \
        ../game_history/dbtablegames.h \
        ../game_history/dbtableplayers.h \
        ../game_history/dbtool.h \
    addplayerwindow.h \
    topplayerswindow.h


FORMS    += mainwindow.ui \
        ../gui_robots/robotswindow.ui \
    addplayerwindow.ui \
    topplayerswindow.ui

