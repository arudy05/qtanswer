#include "cluewidget.h"


ClueWidget::ClueWidget(QWidget *parent) : QWidget{parent}, layout{new QGridLayout(this)}, category{new QLabel},
    clue{new QLabel}, val{0}, countdown{3}, countdownTimer{new QTimer(this)}, countdownText{new QLabel},
    countdownBarL{new QProgressBar}, countdownBarR{new QProgressBar}, answerBoxText{new QLabel}, answerBox{new QLineEdit} {

    // Initialize buzzer objects
    for (int i=0; i<3; ++i) {
        buzzers.push_back(new Buzzer(i));
        layout->addWidget(buzzers[i]->button, 4, i);
        connect(buzzers[i], SIGNAL (buzzIn(int)), this, SLOT (playerBuzzIn(int)));
    }

    // Initialize answer box stuff
    layout->addWidget(answerBoxText, 3, 0);
    layout->addWidget(answerBox, 3, 1, 1, 2);
    answerBoxText->setVisible(false);
    answerBox->setVisible(false);
    answerBox->setPlaceholderText("Type answer, then press ENTER/RETURN key");
    connect(answerBox, SIGNAL (returnPressed()), this, SLOT (playerAnswer()));

    // Initialize category/clue labels
    layout->addWidget(category, 0, 0, 1, 3, Qt::AlignCenter);
    layout->addWidget(clue, 1, 0, 1, 3, Qt::AlignCenter);

    // Initialize countdown objects
    layout->addWidget(countdownText, 2, 1, Qt::AlignCenter);
    connect(countdownTimer, SIGNAL (timeout()), this, SLOT(tickDown()));
    countdownBarL->setTextVisible(false);
    countdownBarL->setMaximum(3);
    countdownBarR->setTextVisible(false);
    countdownBarR->setMaximum(3);
    countdownBarL->setInvertedAppearance(true);
    layout->addWidget(countdownBarL, 2, 0, Qt::AlignRight);
    layout->addWidget(countdownBarR, 2, 2, Qt::AlignLeft);
    setFocusPolicy(Qt::StrongFocus);
}

ClueWidget::~ClueWidget() {
    // no leaks here (i hope)
    delete layout;
    delete category;
    delete clue;
    delete countdownTimer;
    delete countdownText;
    delete countdownBarL;
    delete countdownBarR;
    delete answerBoxText;
    delete answerBox;
    for (int i=0; i<3; ++i) delete buzzers[i];
}

void ClueWidget::initGame(QString p1, QString p2, QString p3) {
    // sets player names (these should honestly be pulled from corresponding Player objects)
    buzzers[0]->button->setText(p1);
    buzzers[1]->button->setText(p2);
    buzzers[2]->button->setText(p3);
}

void ClueWidget::selectClue(int value, std::string catText, std::string clueText, std::vector<std::string> clueAns) {
    // Set category, clue text and possible answers from file
    category->setText(QString::fromStdString(catText));
    clue->setText(QString::fromStdString(clueText));
    answers = clueAns;
    // Set point value of this clue, to be awarded to successful players.
    val = value;
    // Reset playerWrong flags
    playerWrong.clear();
    for (int i = 0; i<3; ++i) playerWrong.push_back(false);
    // Disable buzzer buttons
    for (int i=0; i<3; ++i) buzzers[i]->button->setDisabled(true);
    // Start countdown stuff
    startCountdown();
}

void ClueWidget::playerBuzzIn(int p) {
    currentPlayer = p;
    // Set up and show answer box stuff
    answerBoxText->setText(buzzers[p]->button->text() + ":");
    answerBoxText->setVisible(true);
    answerBox->setVisible(true);
    answerBox->grabKeyboard();
    // Hide and disable buzzers
    for (int i=0; i<3; ++i) buzzers[i]->button->hide();
    for (int i=0; i<3; ++i) buzzers[i]->button->setDisabled(true);
    // Hide countdown stuff
    countdownText->hide();
    countdownBarL->hide();
    countdownBarR->hide();
}

void ClueWidget::playerAnswer() {
    // Show buzzers and countdown stuff
    for (int i=0; i<3; ++i) buzzers[i]->button->show();
    countdownText->show();
    countdownBarL->show();
    countdownBarR->show();

    // Hide answer box stuff
    answerBoxText->hide();
    answerBox->hide();
    answerBox->releaseKeyboard();

    // Grab answer from answer box and clear it
    std::string response = answerBox->text().toStdString();
    answerBox->clear();

    // Check if answer is correct:
    int answerSize = answers.size();
    for (int i = 0; i < answerSize; ++i) {
        if (response == answers[i]) {
            // Answer is correct, return to board
            emit clueReturn(currentPlayer, val);
            return;
        }
    }
    //Answer is incorrect, deduct points and disable player's buzzer for the rest of this clue
    emit incorrectAns(currentPlayer, -val);
    playerWrong[currentPlayer] = true;

    // Check to make sure at least one player buzzer is enabled before restarting countdown
    for (int i = 0; i<3; ++i) {
        if (!playerWrong[i]) {
            startCountdown();
            return;
        }
    }
    // At this point all player buzzers should be disabled, in which case we return to the board
    emit(clueReturn(0,0));
}

void ClueWidget::startCountdown() {
     // Get countdown stuff ready
    countdown = 3;
    countdownTimer->start(1000);
    countdownText->setText(QString::number(countdown));
    countdownBarL->setValue(3);
    countdownBarR->setValue(3);

}

void ClueWidget::tickDown() {
    // Decrement countdown integer and update text accordingly
    countdownText->setText(QString::number(--countdown));
    countdownBarL->setValue(countdown);
    countdownBarR->setValue(countdown);
    // When we hit 0, enable player buzzers and stop the timer
    if (countdown <= 0) {
        for (int i=0; i<3; ++i) if (!playerWrong[i]) buzzers[i]->button->setDisabled(false);
        countdownTimer->stop();
    }
}

void ClueWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        buzzers[0]->button->animateClick();
        break;
    case Qt::Key_B:
        buzzers[1]->button->animateClick();
        break;
    case Qt::Key_L:
        buzzers[2]->button->animateClick();
        break;
    case Qt::Key_Escape:
        emit(clueReturn(0,0));
    default:
        break;
    }
}

