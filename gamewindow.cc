#include "gamewindow.h"
#include <iostream>
GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QGridLayout (this)} {

    // 30 tiles - 5 for each of the 6 categories, arranged in the vector such that
    // index [i*6+j] corresponds to the (i+1)th question of the (j+1)th category starting
    // at the top left of the grid.
    for (int i = 0; i<30; ++i) {
        std::cout << i << std::endl;
        tiles.push_back(new QPushButton(QString::number(((i/6)+1)*200)));
        layout->addWidget(tiles[i], i/6, i%6);
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
    for (int i = 0; i < 30; ++i) {
        delete tiles[i];
    }
    for (int i = 0; i < 3; ++i) {
        delete players[i];
    }
}
