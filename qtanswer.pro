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
    src/startwidget.cc \
    src/tile.cc \
    src/cluefile.cc

HEADERS += \
    src/boardwidget.h \
    src/buzzer.h \
    src/cluewidget.h \
    src/gamewindow.h \
    src/player.h \
    src/startwidget.h \
    src/tile.h \
    src/cluefile.h
