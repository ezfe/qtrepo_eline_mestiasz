TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                    \
                ../gtest/googletest                         \
                ../gtest/googletest/include                 \
                ../gtest/googletest/include/gtest

HEADERS += ../tools/config.h
SOURCES += ../tools/config.cpp

HEADERS += ../tools/log.h
SOURCES += ../tools/log.cpp

HEADERS += ../tools/baseclass.h
SOURCES += ../tools/baseclass.cpp

HEADERS += ../tools/macros.h
