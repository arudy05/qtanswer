#include "boardwidget.h"

BoardWidget::BoardWidget(int scoreBase, QWidget *parent) : QWidget{parent}, layout{new QGridLayout (this)},
scoreBase{scoreBase} {
    // Set up empty category headers
    for (int i = 0; i < 6; ++i) {
        catHeaders.push_back(new QLabel);
        layout->addWidget(catHeaders[i], 0, i, Qt::AlignCenter);
    }

    // 30 tiles - 5 for each of the 6 categories, arranged in the vector such that
    // index [i*6+j] corresponds to the (i+1)th question of the (j+1)th category starting
    // at the top left of the grid.
    for (int i = 0; i<30; ++i) {
        tiles.push_back(new Tile(((i/6)+1)*scoreBase, i%6+1));
        layout->addWidget(tiles[i]->button, i/6+1, i%6);
        connect(tiles[i], SIGNAL (tilePressed(int, int)), this, SLOT (onTileSelect(int, int)));
    }

    // 3 players - in the future you should be able to add a custom amount of players.
    // QLabels for each player's name and score are stored in the Player objects themselves,
    for (int i = 0; i<3; ++i) {
        players.push_back(new Player());
        layout->addWidget(players[i]->getName(),  6, i*2, 1, 2, Qt::AlignCenter);
        layout->addWidget(players[i]->getScore(), 7, i*2, 1, 2, Qt::AlignCenter);
    }
}

BoardWidget::~BoardWidget() {
    // All tile and player objects were allocated by us, therefore we have to make
    // sure that all memory is freed properly.
    delete layout;
    for (int i = 0; i < 6;  ++i) delete catHeaders[i];
    for (int i = 0; i < 30; ++i) delete tiles[i];
    for (int i = 0; i < 3;  ++i) delete players[i];
}

void BoardWidget::setCategoryHeader(int cat, std::string text) {
    catHeaders[cat]->setText(QString::fromStdString(text));
}

void BoardWidget::initGame(QString p1, QString p2, QString p3) {
    // takes 3 player names (from StartWidget via GameWindow) and sets them accordingly.
    // if i am ever to accomodate for a custom amount of players this should be changed
    // to something using vectors and a for loop but for now this works well enough
    players[0]->setName(p1);
    players[1]->setName(p2);
    players[2]->setName(p3);
}

void BoardWidget::onTileSelect(int val, int cat) {
    // Disables tiles; other functionality is handled by GameWindow
    int q = val/scoreBase -1;
    tiles[q*6+cat-1]->disable();
    emit tileSelect(val, cat-1);
}

void BoardWidget::onTileReturn(int player, int score) {
    // Adds given score to given player
    players[player]->addScore(score);

    static int tilesSelected = 0;
    if (++tilesSelected == 30) {
        tilesSelected = 0;
        emit gameOver(players);
    }

}

void BoardWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Escape:
        emit(gameOver(players));
    default:
        break;
    }
}
