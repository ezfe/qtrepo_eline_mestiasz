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
            ../game_history/playergamehistory.h \
            ../game_history/dbtable.h \
            ../game_history/dbtool.h \
            ../game_history/dbtableplayers.h \
            ../game_history/dbtablegames.h

SOURCES +=  ../game_history/game.cpp \
            ../game_history/gamehistory.cpp \
            ../game_history/player.cpp \
            ../game_history/playergamehistory.cpp \
            ../game_history/dbtable.cpp \
            ../game_history/dbtool.cpp \
            ../game_history/dbtableplayers.cpp \
            ../game_history/dbtablegames.cpp

LIBS += -l sqlite3
