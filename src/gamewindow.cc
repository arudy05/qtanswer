#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QStackedLayout}, start{new StartWidget}, board{new BoardWidget}, clueDisplay{new ClueWidget} {
    // Add all widgets one by one, set the StartWidget as the one at the top of the QStackedLayout
    layout->addWidget(start);
    layout->addWidget(board);
    layout->addWidget(clueDisplay);
    layout->setCurrentIndex(0);
    setLayout(layout);

    // Connections for when a tile is selected
    connect(board, SIGNAL (tileSelect(int, int)), this, SLOT (onTileSelect()));
    connect(board, SIGNAL (tileSelect(int, int)), clueDisplay, SLOT (selectClue(int, int)));

    // Connections for when we are done with a clue
    connect(clueDisplay, SIGNAL (clueReturn(int, int)), board, SLOT (onTileReturn(int, int)));
    connect(clueDisplay, SIGNAL (clueReturn(int, int)), this, SLOT (onTileReturn()));

    // Connections for setting player names
    connect(start, SIGNAL(gameStart(QString, QString, QString, std::string)), board, SLOT (initGame(QString, QString, QString, std::string)));
    connect(start, SIGNAL(gameStart(QString, QString, QString, std::string)), clueDisplay, SLOT (initGame(QString, QString, QString, std::string)));
    connect(start, SIGNAL(gameStart(QString, QString, QString, std::string)), this, SLOT (onTileReturn()));
}

GameWindow::~GameWindow() {
    delete start;
    delete layout;
    delete board;
    delete clueDisplay;
}

void GameWindow::onTileSelect() {
    // When a tile is selected, switch to the ClueWidget
    layout->setCurrentIndex(2);
}

void GameWindow::onTileReturn() {
    // Switch back to the BoardWidget after going through a clue
    layout->setCurrentIndex(1);
}
