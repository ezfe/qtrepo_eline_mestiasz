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
    main.cpp \
    menu.cpp \
    gamescreen.cpp \
    menuitemscreen.cpp \
    newplayer.cpp \
    selectplayer.cpp \
    topplayers.cpp \
    topgames.cpp \
    statistics.cpp \
    ../game_history/playergamehistory.cpp

LIBS += -lncurses -lform

HEADERS += screen.h \
    ../engines/engine.h \
    ../engines/robots.h \
    ../engines/worms.h \
    robotsscreen.h \
    wormsscreen.h \
    menu.h \
    gamescreen.h \
    menuitemscreen.h \
    newplayer.h \
    selectplayer.h \
    topplayers.h \
    topgames.h \
    statistics.h \
    ../game_history/playergamehistory.h


