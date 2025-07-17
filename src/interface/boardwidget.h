#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>
#include <vector>
#include <tile.h>
#include <player.h>

// The main game board, plus player scores.
class BoardWidget : public QWidget
{
    Q_OBJECT
    QGridLayout *layout;
    std::vector<QLabel*> catHeaders;    // Category headers
    std::vector<Tile*> tiles;           // Clue tiles
    std::vector<Player*> players;       // Players and scores
    int scoreBase;

public:
    explicit BoardWidget(int scoreBase, QWidget *parent = nullptr);
    ~BoardWidget();
    void keyPressEvent(QKeyEvent *event);
    void setCategoryHeader(int cat, std::string text);

public slots:
    void onTileSelect(int val, int cat);
    void onTileReturn(int player, int score);
    void initGame(QString, QString, QString);

signals:
    void tileSelect(int, int);
    void gameOver(std::vector<Player*>);
};

#endif // BOARDWIDGET_H
