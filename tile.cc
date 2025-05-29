#include "tile.h"


Tile::Tile(int val, int cat): value{val}, category{cat}, button{new QPushButton(QString::number(val))} {
    connect(button, SIGNAL (clicked(bool)), this, SLOT (onButtonPress()));
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Tile::~Tile() {
    // you get the point
    delete button;
}

void Tile::disable() {
    button->setDisabled(true);
}

void Tile::onButtonPress() {
    // When the button is pressed, emit a signal with this tile's
    // value and category so that the game pulls the proper question.
    emit tilePressed(value, category);
}
