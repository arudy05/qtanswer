#include "player.h"

Player::Player() : score{0}, QScore{new QLabel(QString::number(0))}, QName{new QLabel("default")} {}

Player::Player(std::string text) : score{0}, QScore{new QLabel(QString::number(0))}, QName{new QLabel(QString::fromStdString(text))} {}

Player::~Player() {
    delete QScore;
    delete QName;
}

QLabel *Player::getName() {
    return QName;
}

void Player::setName(std::string str) {
    QName->setText(QString::fromStdString(str));
}

QLabel *Player::getScore() {
    return QScore;
}

void Player::setScore(int val) {
    score = val;
    QScore->setText(QString::number(score));
}

void Player::addScore(int val) {
    score += val;
    QScore->setText(QString::number(score));
}
