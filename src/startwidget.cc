#include "startwidget.h"


StartWidget::StartWidget(QWidget *parent) : QWidget{parent}, layout{new QGridLayout(this)}, title{new QLabel("QtAnswer")},
playerNameText{new QLabel("Enter player names:")}, startButton{new QPushButton("Start game")} {
    layout->addWidget(title, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(playerNameText, 1, 0);

    for (int i = 0; i<3; ++i) {
        playerNames.push_back(new QLineEdit("Player " + QString::number(i+1)));
        layout->addWidget(playerNames[i], i+1, 1);
    }

    layout->addWidget(startButton, 4, 1);
    connect(startButton, SIGNAL (clicked(bool)), this, SLOT (gameStartPressed()));
}

StartWidget::~StartWidget() {
    delete layout;
    delete title;
    delete playerNameText;
    delete startButton;
    for (int i = 0; i<3; ++i) delete playerNames[i];
}

void StartWidget::gameStartPressed() {
    emit gameStart(playerNames[0]->displayText(), playerNames[1]->displayText(), playerNames[2]->displayText());
}
