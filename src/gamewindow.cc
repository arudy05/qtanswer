#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QStackedLayout},
    start{new StartWidget}, board{nullptr}, clueDisplay{nullptr}, results{nullptr}, file{nullptr} {

    // Add start widget; others will be added once the setup process is complete
    layout->addWidget(start);
    layout->setCurrentWidget(start);
    setLayout(layout);

    // Connections for setting player names
    connect(start, SIGNAL(gameStart(QString, QString, QString, std::string, int)),
            this, SLOT (onGameStart(QString, QString, QString, std::string, int)));
}

GameWindow::~GameWindow() {
    delete start;
    delete layout;
    delete board;
    delete clueDisplay;
    delete results;
    delete file;
}

void GameWindow::onGameStart(QString p1, QString p2, QString p3, std::string path, int scoreBase) {
    //Set score base
    this->scoreBase = scoreBase;

    // Create ClueFile based on given path
    file = new ClueFile(path);

    // Initialize BoardWidget
    board = new BoardWidget(scoreBase);
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
    connect(clueDisplay, SIGNAL (incorrectAns(int, int)), board, SLOT (onTileReturn(int, int)));

    // Connection for the end of a game (premature or not)
    connect(board, SIGNAL (gameOver(std::vector<Player*>)), this, SLOT (gameEndScreen(std::vector<Player*>)));

    // Switch view to the BoardWidget
    layout->setCurrentWidget(board);
}

void GameWindow::onTileSelect(int val, int cat) {
    // When a tile is selected, switch to the ClueWidget
    std::string clueCat = file->getCategory(cat);
    std::string clueText = file->getClue(cat, val/scoreBase-1);
    std::vector<std::string> clueAns = file->getAnswers(cat, val/scoreBase-1);
    clueDisplay->selectClue(val, clueCat, clueText, clueAns);
    layout->setCurrentWidget(clueDisplay);
}

void GameWindow::onTileReturn() {
    // Switch back to the BoardWidget after going through a clue
    layout->setCurrentWidget(board);
}

void GameWindow::gameEndScreen(std::vector<Player *> players) {
    results = new ResultsWidget(players);
    layout->addWidget(results);
    layout->setCurrentWidget(results);
    connect(results, &ResultsWidget::quitGame, this, &GameWindow::close);
    connect(results, &ResultsWidget::resetGame, this, &GameWindow::resetGame);
}


void GameWindow::resetGame() {
    layout->setCurrentWidget(start);
    delete board;
    delete clueDisplay;
    delete results;
}
