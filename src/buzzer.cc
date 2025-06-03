#include "buzzer.h"


Buzzer::Buzzer(int p): player{p}, button{new QPushButton("Player " + QString::number(p))} {
    connect(button, SIGNAL (clicked(bool)), this, SLOT (onButtonPress()));
    //button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Buzzer::~Buzzer() {
    // you get the point
    delete button;
}

void Buzzer::onButtonPress() {
    // When the button is pressed, emit a signal with the player's index.
    emit buzzIn(player);
}
