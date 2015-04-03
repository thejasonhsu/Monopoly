#-------------------------------------------------
#
# Project created by QtCreator 2014-04-25T00:15:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sorry
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    centralwidget.cpp \
    guiplayer.cpp \
    guiplayerhorizontal.cpp \
    guiplayervertical.cpp \
    player.cpp \
    sorry.cpp

HEADERS  += mainwindow.h \
    centralwidget.h \
    guiplayer.h \
    guiplayerhorizontal.h \
    guiplayervertical.h \
    player.h

FORMS    += mainwindow.ui

RESOURCES += \
    application.qrc

OTHER_FILES += \
    sorry.pro.user
