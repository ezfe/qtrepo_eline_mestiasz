TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    robots.cpp \
    worms.cpp \
    engine.cpp \
    ../tui/screen.cpp

LIBS += -lncurses

HEADERS += \
    robots.h \
    worms.h \
    engine.h \
    ../tui/screen.h
