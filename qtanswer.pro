TEMPLATE = app
TARGET = qtanswer

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    gamewindow.cc \
    main.cc \
    player.cc \
    tile.cc

HEADERS += \
    gamewindow.h \
    player.h \
    tile.h
