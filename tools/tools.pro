TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    log.cpp \
    config.cpp

HEADERS += \
    log.h \
    config.h

DISTFILES += \
    test.txt
