TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    stacktest.cpp \
    bsttest.cpp

HEADERS +=  stacktest.h \
    bsttest.h

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                    \
                ../gtest/googletest                         \
                ../gtest/googletest/include                 \
                ../gtest/googletest/include/gtest

HEADERS += ../templates/stack.h
LIBS += -lpthread
