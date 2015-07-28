#-------------------------------------------------
#
# Project created by QtCreator 2015-07-27T14:35:52
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = Test_Model
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    coords.cpp \
    radar.cpp \
    test_coord.cpp \
    test_radar.cpp

HEADERS += \
    coords.h \
    radar.h \
    AutoTest.h \
    test_coord.h \
    test_radar.h
LIBS += -lproj \
    -lGeographic
