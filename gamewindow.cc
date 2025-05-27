#include "gamewindow.h"
#include <iostream>
GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QGridLayout (this)} {
    // Category headers: leave text as "default" for now.
    for (int i = 0; i < 6; ++i) {
        catHeaders.push_back(new QLabel("default"));
        layout->addWidget(catHeaders[i], 0, i, Qt::AlignCenter);
    }

    // 30 tiles - 5 for each of the 6 categories, arranged in the vector such that
    // index [i*6+j] corresponds to the (i+1)th question of the (j+1)th category starting
    // at the top left of the grid.
    for (int i = 0; i<30; ++i) {
        std::cout << i << std::endl;
        tiles.push_back(new Tile(((i/6)+1)*200, i%6+1));
        layout->addWidget(tiles[i]->button, i/6+1, i%6);
        connect(tiles[i], SIGNAL (tilePressed(int, int)), this, SLOT (onTileSelect(int, int)));
    }

    // 3 players - in the future you should be able to add a custom amount of players.
    // QLabels for each player's name and score are stored in the Player objects themselves,
    for (int i = 0; i<3; ++i) {
        players.push_back(new Player());
        layout->addWidget(players[i]->getName(), 6, i*2, 1, 2, Qt::AlignCenter);
        layout->addWidget(players[i]->getScore(), 7, i*2, 1, 2, Qt::AlignCenter);
    }

}

GameWindow::~GameWindow() {
    // All tile and player objects were allocated by us, therefore we have to make
    // sure that all memory is freed properly.
    for (int i = 0; i < 30; ++i) delete tiles[i];
    for (int i = 0; i < 3;  ++i) delete players[i];
}

void GameWindow::onTileSelect(int val, int cat) {
    // In the future this will select the clue of corresponding value and category
    // and display it. For now, we just add the value to the first player's score.
    players[0]->addScore(val);
}
