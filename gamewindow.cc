#include "gamewindow.h"
#include <iostream>
GameWindow::GameWindow(QWidget *parent) : QWidget{parent}, layout{new QGridLayout (this)} {

    for (int i = 0; i<30; ++i) {
        std::cout << i << std::endl;
        tiles.push_back(new QPushButton(QString::number(((i/6)+1)*200)));
        layout->addWidget(tiles[i], i/6, i%6);
    }

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
