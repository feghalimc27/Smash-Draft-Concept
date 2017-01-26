TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    schedule.cpp

HEADERS += \
    player.h \
    menu.h \
    schedule.h

DISTFILES += \
    smash4roster.txt
