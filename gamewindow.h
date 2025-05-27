#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include "tile.h"
#include "player.h"

// The main game board, plus player scores.
class GameWindow : public QWidget
{
    Q_OBJECT
    QGridLayout *layout;
    std::vector<QLabel*> catHeaders;    // Category headers
    std::vector<Tile*> tiles;           // Clue tiles
    std::vector<Player*> players;       // Players and scores

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

public slots:
    void onTileSelect(int val, int cat);

};

#endif // GAMEWINDOW_H
