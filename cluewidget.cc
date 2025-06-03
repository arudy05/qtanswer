#include "cluewidget.h"


ClueWidget::ClueWidget(QWidget *parent) : QWidget{parent}, layout{new QGridLayout(this)}, category{new QLabel},
    clue{new QLabel}, val{0}, countdown{3}, countdownTimer{new QTimer(this)}, countdownText{new QLabel} {

    // Initialize buzzer objects
    for (int i=0; i<3; ++i) {
        buzzers.push_back(new Buzzer(i));
        layout->addWidget(buzzers[i]->button, 3, i);
        connect(buzzers[i], SIGNAL (buzzIn(int)), this, SLOT (playerBuzzIn(int)));
    }

    // Initialize category/clue labels
    layout->addWidget(category, 0, 0, 1, 3, Qt::AlignCenter);
    layout->addWidget(clue, 1, 0, 1, 3, Qt::AlignCenter);

    // Initialize countdown objects
    layout->addWidget(countdownText, 2, 1, Qt::AlignCenter);
    connect(countdownTimer, SIGNAL (timeout()), this, SLOT(tickDown()));
}

ClueWidget::~ClueWidget() {
    // no leaks here (i hope)
    delete layout;
    delete category;
    delete clue;
    delete countdownTimer;
    delete countdownText;
    for (int i=0; i<3; ++i) delete buzzers[i];
}

void ClueWidget::selectClue(int value, int cat) {
    // Set category and clue text (currently temporary text)
    category->setText("Category " + QString::number(cat));
    clue->setText("Value of " + QString::number(value));
    // Set point value of this clue, to be awarded to successful players.
    val = value;
    // Get countdown stuff ready - this includes disabling buzzer buttons!
    countdown = 3;
    countdownTimer->start(1000);
    countdownText->setText(QString::number(countdown));
    for (int i=0; i<3; ++i) buzzers[i]->button->setDisabled(true);
}

void ClueWidget::playerBuzzIn(int p) {
    // For now we just assume the player has the correct answer
    emit clueReturn(p, val);
}

void ClueWidget::tickDown() {
    // Decrement countdown integer and update text accordingly
    countdownText->setText(QString::number(--countdown));
    // When we hit 0, enable player buzzers and stop the timer
    if (countdown <= 0) {
        for (int i=0; i<3; ++i) {
            buzzers[i]->button->setDisabled(false);
            countdownTimer->stop();
        }
    }
}
