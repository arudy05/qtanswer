#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <vector>
#include "player.h"

class QPushButton;

class GameWindow : public QWidget
{
    Q_OBJECT
    QGridLayout *layout;
    std::vector<QPushButton*> tiles;    // Clue tiles
    std::vector<Player*> players;       // Player objects

public:
    explicit GameWindow(QWidget *parent = nullptr); // Constructor
    ~GameWindow();                                  // Destructor

signals:

};

#endif // GAMEWINDOW_H
