#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>
#include <string>

// Each Player object represents one of the players in the game.
class Player {
    int score;
    QLabel *QScore;
    QLabel *QName;
public:
    Player();                   // constructor
    ~Player();                  // destructor
    Player(std::string);        // constructor with player name
    QLabel *getName();          // accessor/mutator functions
    void setName(std::string);  // |
    void setName(QString);      // |
    QLabel *getScore();         // |
    void setScore(int);         // |
    void addScore(int);         // v
};

#endif // PLAYER_H
