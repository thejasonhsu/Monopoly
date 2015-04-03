#-------------------------------------------------
#
# Project created by QtCreator 2014-05-04T13:51:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = monopoly
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Action.cpp \
    Bank.cpp \
    Board.cpp \
    Card.cpp \
    centralwidget.cpp \
    GotoAction.cpp \
    guiplayer.cpp \
    guiplayerhorizontal.cpp \
    guiplayervertical.cpp \
    MoneyAction.cpp \
    moveaction.cpp \
    player.cpp \
    Space.cpp

HEADERS  += mainwindow.h \
    Action.h \
    Bank.h \
    Board.h \
    Card.h \
    centralwidget.h \
    GotoAction.h \
    guiplayer.h \
    guiplayerhorizontal.h \
    guiplayervertical.h \
    MoneyAction.h \
    moveaction.h \
    player.h \
    Space.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    monopoly.pro.user \
    ../../../../images/battleship.png \
    ../../../../images/board.png \
    ../../../../images/dog.png \
    ../../../../images/shoe.png \
    ../../../../images/thimble.png
