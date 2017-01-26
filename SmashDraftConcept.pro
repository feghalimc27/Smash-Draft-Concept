TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    matches.cpp

HEADERS += \
    player.h \
    menu.h \
    matches.h

DISTFILES += \
    smash4roster.txt
