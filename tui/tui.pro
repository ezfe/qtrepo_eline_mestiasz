TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    screen.cpp \
    ../engines/engine.cpp \
    ../engines/robots.cpp

LIBS += -lncurses

HEADERS += screen.h \
    ../engines/engine.h \
    ../engines/robots.h


