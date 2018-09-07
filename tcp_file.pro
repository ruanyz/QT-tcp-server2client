#-------------------------------------------------
#
# Project created by QtCreator 2018-09-03T01:18:53
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp_file
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    client.cpp

HEADERS  += widget.h \
    client.h

FORMS    += widget.ui \
    client.ui
