#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "startwidget.h"
#include "boardwidget.h"
#include "cluewidget.h"
#include "resultswidget.h"
#include "cluefile.h"

class GameWindow : public QWidget {
    Q_OBJECT
    QStackedLayout *layout;
    StartWidget *start;
    BoardWidget *board;
    ClueWidget *clueDisplay;
    ResultsWidget *results;
    ClueFile *file;
    int scoreBase;
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
public slots:
    void onGameStart(QString, QString, QString, std::string, int);
    void onTileSelect(int, int);
    void onTileReturn();
    void gameEndScreen(std::vector<Player*>);
    void resetGame();

signals:

};

#endif // GAMEWINDOW_H
