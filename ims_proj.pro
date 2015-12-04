TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11 -lsimlib -lm
LIBS = -lsimlib -lm


SOURCES += main.cpp \
    krizovatka.cpp \
    rameno.cpp \
    semafor.cpp \
    dopravniprostredek.cpp \
    generator.cpp \
    pruh.cpp

HEADERS += \
    krizovatka.h \
    rameno.h \
    semafor.h \
    dopravniprostredek.h \
    generator.h \
    pruh.h

