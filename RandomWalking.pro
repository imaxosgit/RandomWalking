TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sheep.cpp \
    creature.cpp \
    herdsman.cpp \
    wolf.cpp \
    board.cpp

HEADERS += \
    creature.h \
    cell.h \
    sheep.h \
    herdsman.h \
    wolf.h \
    board.h \
    pair.h

