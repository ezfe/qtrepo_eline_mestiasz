TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    log.cpp \
    config.cpp \
    baseclass.cpp

HEADERS += \
    log.h \
    config.h \
    baseclass.h \
    macros.h

DISTFILES += \
    test.txt \
    random.txt
