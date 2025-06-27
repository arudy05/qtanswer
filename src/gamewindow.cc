#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QStackedLayout},
    start{new StartWidget}, board{nullptr}, clueDisplay{nullptr}, file{nullptr} {

    // Add start widget; others will be added once the setup process is complete
    layout->addWidget(start);
    layout->setCurrentIndex(0);
    setLayout(layout);

    // Connections for setting player names
    connect(start, SIGNAL(gameStart(QString, QString, QString, std::string)),
            this, SLOT (onGameStart(QString, QString, QString, std::string)));
}

GameWindow::~GameWindow() {
    delete start;
    delete layout;
    delete board;
    delete clueDisplay;
}

void GameWindow::onGameStart(QString p1, QString p2, QString p3, std::string path) {
    // Create ClueFile based on given path
    file = new ClueFile(path);

    // Initialize BoardWidget
    board = new BoardWidget();
    for(int i = 0; i <6; ++i) board->setCategoryHeader(i, file->getCategory(i));
    board->initGame(p1, p2, p3);

    // Initialize ClueWidget
    clueDisplay = new ClueWidget();
    clueDisplay->initGame(p1, p2, p3);

    // Add aforementioned widgets to QStackedLayout
    layout->addWidget(board);
    layout->addWidget(clueDisplay);

    // Connection for when a tile is selected
    connect(board, SIGNAL (tileSelect(int, int)), this, SLOT (onTileSelect(int, int)));

    // Connections for when we are done with a clue
    connect(clueDisplay, SIGNAL (clueReturn(int, int)), board, SLOT (onTileReturn(int, int)));
    connect(clueDisplay, SIGNAL (clueReturn(int, int)), this, SLOT (onTileReturn()));

    // Switch view to the BoardWidget
    layout->setCurrentIndex(1);
}

void GameWindow::onTileSelect(int val, int cat) {
    // When a tile is selected, switch to the ClueWidget
    std::string clueCat = file->getCategory(cat);
    std::string clueText = file->getClue(cat, val/200-1);
    clueDisplay->selectClue(val, clueCat, clueText);
    layout->setCurrentIndex(2);
}

void GameWindow::onTileReturn() {
    // Switch back to the BoardWidget after going through a clue
    layout->setCurrentIndex(1);
}
