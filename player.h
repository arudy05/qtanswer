#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>
#include <string>

class Player {
    int score;
    QLabel *QScore;
    QLabel *QName;
public:
    Player();
    ~Player();
    Player(std::string);
    QLabel *getName();
    void setName(std::string);
    QLabel *getScore();
    void setScore(int);
    void addScore(int);
};

#endif // PLAYER_H
