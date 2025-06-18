#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QStackedLayout}, start{new StartWidget}, board{new BoardWidget}, clueDisplay{new ClueWidget} {
    layout->addWidget(start);
    layout->addWidget(board);
    layout->addWidget(clueDisplay);
    layout->setCurrentIndex(0);
    setLayout(layout);
    for (int i = 0; i<30; ++i) {
        connect(board->getTile(i), SIGNAL (tilePressed(int, int)), this, SLOT (onTileSelect()));
        connect(board->getTile(i), SIGNAL (tilePressed(int, int)), clueDisplay, SLOT (selectClue(int, int)));
    }
    connect(clueDisplay, SIGNAL (clueReturn(int, int)), board, SLOT (onTileReturn(int, int)));
    connect(clueDisplay, SIGNAL (clueReturn(int, int)), this, SLOT (onTileReturn()));
    connect(start, SIGNAL(gameStart(QString, QString, QString)), board, SLOT (setPlayerNames(QString, QString, QString)));
    connect(start, SIGNAL(gameStart(QString, QString, QString)), clueDisplay, SLOT (setPlayerNames(QString, QString, QString)));
    connect(start, SIGNAL(gameStart(QString, QString, QString)), this, SLOT (onTileReturn()));
}

GameWindow::~GameWindow() {
    delete start;
    delete layout;
    delete board;
    delete clueDisplay;
}

void GameWindow::onTileSelect() {
    layout->setCurrentIndex(2);
}

void GameWindow::onTileReturn() {
    layout->setCurrentIndex(1);
}
