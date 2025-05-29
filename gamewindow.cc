#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QStackedLayout}, board{new BoardWidget} {
    layout->addWidget(board);
    setLayout(layout);
}

GameWindow::~GameWindow() {
    delete layout;
    delete board;
}
