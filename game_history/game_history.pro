TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    playergamehistory.cpp \
    player.cpp \
    gamehistory.cpp \
    game.cpp \
    dbtable.cpp \
    dbtool.cpp \
    dbtableplayers.cpp

HEADERS += \
    playergamehistory.h \
    player.h \
    gamehistory.h \
    game.h \
    dbtable.h \
    dbtool.h \
    dbtableplayers.h
