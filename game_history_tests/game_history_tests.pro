TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gametest.cpp \
    gamehistorytest.cpp \
    playertest.cpp \
    playergamehistorytest.cpp

HEADERS += \
    gametest.h \
    gamehistorytest.h \
    playertest.h \
    playergamehistorytest.h

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                    \
                ../gtest/googletest                         \
                ../gtest/googletest/include                 \
                ../gtest/googletest/include/gtest

HEADERS +=  ../game_history/game.h \
            ../game_history/gamehistory.h \
            ../game_history/player.h \
            ../game_history/playergamehistory.h

SOURCES +=  ../game_history/game.cpp \
            ../game_history/gamehistory.cpp \
            ../game_history/player.cpp \
            ../game_history/playergamehistory.cpp
