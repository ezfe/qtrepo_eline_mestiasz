TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    screen.cpp \
    ../engines/engine.cpp \
    ../engines/robots.cpp \
    ../engines/worms.cpp \
    robotsscreen.cpp \
    wormsscreen.cpp \
    main.cpp

LIBS += -lncurses

HEADERS += screen.h \
    ../engines/engine.h \
    ../engines/robots.h \
    ../engines/worms.h \
    robotsscreen.h \
    wormsscreen.h


