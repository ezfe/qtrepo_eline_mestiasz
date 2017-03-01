TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dbtool.cpp \
    dbtable.cpp \
    dbtableplayers.cpp

HEADERS += \
    dbtool.h \
    dbtable.h \
    dbtableplayers.h

LIBS += -l sqlite3
