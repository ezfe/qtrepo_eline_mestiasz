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
    ../game_history/playergamehistory.cpp \
    ../game_history/game.cpp \
    ../game_history/player.cpp \
    ../game_history/gamehistory.cpp \
    ../game_history/dbtable.cpp \
    ../game_history/dbtablegames.cpp \
    ../game_history/dbtableplayers.cpp \
    ../game_history/dbtool.cpp

LIBS += -lncurses -lform -l sqlite3

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
    ../game_history/playergamehistory.h \
    ../game_history/game.h \
    ../game_history/player.h \
    ../game_history/gamehistory.h \
    ../game_history/dbtable.h \
    ../game_history/dbtablegames.h \
    ../game_history/dbtableplayers.h \
    ../game_history/dbtool.h


