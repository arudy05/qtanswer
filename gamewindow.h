#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include "player.h"

class QPushButton;

class GameWindow : public QWidget
{
    Q_OBJECT
    QGridLayout *layout;
    std::vector<QPushButton*> tiles;
    std::vector<Player*> players;

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

signals:

};

#endif // GAMEWINDOW_H
