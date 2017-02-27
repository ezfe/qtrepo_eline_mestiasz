TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    database.cpp \
    table.cpp

HEADERS += \
    database.h \
    table.h

LIBS += -lsqlite3
