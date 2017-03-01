TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dbtool.cpp \
    dbtable.cpp \
    dbtableex.cpp

HEADERS += \
    dbtool.h \
    dbtableex.h \
    dbtable.h \
    dbtableplayers

LIBS += -l sqlite3
