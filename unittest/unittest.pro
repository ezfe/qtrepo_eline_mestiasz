TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                    \
                ../gtest/googletest                         \
                ../gtest/googletest/include                 \
                ../gtest/googletest/include/gtest           \
                ../gtest/googletest/include/gtest/gtest.h

HEADERS += ../tools/config.h
SOURCES += ../tools/config.cpp

HEADERS += ../tools/log.h
SOURCES += ../tools/log.cpp
