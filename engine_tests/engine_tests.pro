TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    worms.cpp

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                    \
                ../gtest/googletest                         \
                ../gtest/googletest/include                 \
                ../gtest/googletest/include/gtest

HEADERS += ../engines/macros.h

HEADERS +=  ../engines/robots.h \
            ../engines/worms.h

SOURCES +=  ../engines/robots.cpp \
            ../engines/worms.cpp
