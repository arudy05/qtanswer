TEMPLATE = app
TARGET = qtanswer

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    src/boardwidget.cc \
    src/buzzer.cc \
    src/cluewidget.cc \
    src/gamewindow.cc \
    src/main.cc \
    src/player.cc \
    src/tile.cc

HEADERS += \
    include/boardwidget.h \
    include/buzzer.h \
    include/cluewidget.h \
    include/gamewindow.h \
    include/player.h \
    include/tile.h
