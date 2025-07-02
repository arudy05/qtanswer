#include "resultswidget.h"


ResultsWidget::ResultsWidget(std::vector<Player*> players, QWidget *parent) :
    QWidget{parent}, congrats{new QLabel("Game Over!")}, winner{new QLabel}, toMenu{new QPushButton("Back to menu")},
    exit{new QPushButton("Quit")}, layout{new QGridLayout} {

    // Get winner scores
    // We also account for if there are multiple winners (a tie occurs)
    std::vector<int> winnerIDs;
    int highestScore = players[0]->getIntScore();
    winnerIDs.push_back(0);

    for (int i = 1; i < players.size(); ++i) {
        if (players[i]->getIntScore() == highestScore) winnerIDs.push_back(i);
        else if (players[i]->getIntScore() > highestScore) {
            highestScore = players[i]->getIntScore();
            winnerIDs.clear();
            winnerIDs.push_back(i);
        }
    }

    // Set up labels
    QString winnerText;

    if (winnerIDs.size() > 1) winnerText.append("Winners: ");
    else winnerText.append("Winner: ");

    for (int i = 0; i < winnerIDs.size(); ++i) {
        winnerText.append(players[winnerIDs[i]]->getName()->text());
        if (i < winnerIDs.size()-1) winnerText.append(", ");
    }
    winnerText.append(" (" + QString::number(highestScore) + ")");
    winner->setText(winnerText);

    layout->addWidget(congrats, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(winner, 1, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(toMenu, 2, 0);
    layout->addWidget(exit, 2, 1);
    setLayout(layout);

    // Connections for buttons
    connect(toMenu, &QPushButton::clicked, this, &ResultsWidget::resetGameClicked);
    connect(exit,   &QPushButton::clicked, this, &ResultsWidget::quitGameClicked);
}

ResultsWidget::~ResultsWidget() {
    delete congrats;
    delete winner;
    delete toMenu;
    delete exit;
    delete layout;
}

void ResultsWidget::resetGameClicked() {
    emit resetGame();
}

void ResultsWidget::quitGameClicked() {
    emit quitGame();
}
