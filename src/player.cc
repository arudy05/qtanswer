#include "player.h"

Player::Player() : score{0}, QScore{new QLabel(QString::number(0))}, QName{new QLabel("default")} {}

Player::Player(std::string text) : score{0}, QScore{new QLabel(QString::number(0))}, QName{new QLabel(QString::fromStdString(text))} {}

Player::~Player() {
    // QScore and QName are manually allocated, thus they must be deallocated here.
    delete QScore;
    delete QName;
}

QLabel *Player::getName() {
    // Accessor method for QName
    return QName;
}

void Player::setName(std::string str) {
    // Sets player's name
    QName->setText(QString::fromStdString(str));
}

QLabel *Player::getScore() {
    // Accessor methor for QScore
    return QScore;
}

// Note that score is stored as an integer. This integer is operated on
// to avoid pulling the value from QScore's text (yuck).

void Player::setScore(int val) {
    // Manually sets player's score
    score = val;
    QScore->setText(QString::number(score));
}

void Player::addScore(int val) {
    // Adds to player's score
    score += val;
    QScore->setText(QString::number(score));
}
