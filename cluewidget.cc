#include "cluewidget.h"


ClueWidget::ClueWidget(QWidget *parent) : QWidget{parent}, layout{new QGridLayout(this)}, category{new QLabel}, clue{new QLabel}, val{0} {
    for (int i=0; i<3; ++i) {
        buzzers.push_back(new Buzzer(i));
        layout->addWidget(buzzers[i]->button, 2, i);
        connect(buzzers[i], SIGNAL (buzzIn(int)), this, SLOT (playerBuzzIn(int)));
    }
    layout->addWidget(category, 0, 0, 1, 3, Qt::AlignCenter);
    layout->addWidget(clue, 1, 0, 1, 3, Qt::AlignCenter);
}

void ClueWidget::selectClue(int value, int cat) {
    category->setText("Category " + QString::number(cat));
    clue->setText("Value of " + QString::number(value));
    val = value;
}

void ClueWidget::playerBuzzIn(int p) {
    emit clueReturn(p, val);
}
