TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    robotstest.cpp \
    wormstest.cpp

HEADERS +=  robotstest.h \
            wormstest.h

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                    \
                ../gtest/googletest                         \
                ../gtest/googletest/include                 \
                ../gtest/googletest/include/gtest

HEADERS +=  ../engines/robots.h \
            ../engines/worms.h \
            ../engines/engine.h

SOURCES +=  ../engines/robots.cpp \
            ../engines/worms.cpp \
            ../engines/engine.cpp
LIBS += -lpthread
