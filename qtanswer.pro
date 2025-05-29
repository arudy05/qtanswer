TEMPLATE = app
TARGET = qtanswer

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    boardwidget.cc \
    gamewindow.cc \
    main.cc \
    player.cc \
    tile.cc

HEADERS += \
    boardwidget.h \
    gamewindow.h \
    player.h \
    tile.h
