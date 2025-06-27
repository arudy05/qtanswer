#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include "tile.h"
#include "player.h"

// The main game board, plus player scores.
class BoardWidget : public QWidget
{
    Q_OBJECT
    QGridLayout *layout;
    std::vector<QLabel*> catHeaders;    // Category headers
    std::vector<Tile*> tiles;           // Clue tiles
    std::vector<Player*> players;       // Players and scores

public:
    explicit BoardWidget(QWidget *parent = nullptr);
    ~BoardWidget();
    void setCategoryHeader(int cat, std::string text);

public slots:
    void onTileSelect(int val, int cat);
    void onTileReturn(int player, int score);
    void initGame(QString, QString, QString);

signals:
    void tileSelect(int, int);
};

#endif // BOARDWIDGET_H
