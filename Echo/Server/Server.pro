#-------------------------------------------------
#
# Project created by QtCreator 2020-02-03T04:30:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
LIBS += C:\Qt\Qt5.2.0\Tools\mingw48_32\i686-w64-mingw32\lib\libwsock32.a


SOURCES += main.cpp \
    Socket_program.cpp

HEADERS += \
    Socket_interface.h
