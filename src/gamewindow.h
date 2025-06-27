#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "startwidget.h"
#include "boardwidget.h"
#include "cluewidget.h"
#include "cluefile.h"

class GameWindow : public QWidget {
    Q_OBJECT
    QStackedLayout *layout;
    StartWidget *start;
    BoardWidget *board;
    ClueWidget *clueDisplay;
    ClueFile *file;
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
public slots:
    void onGameStart(QString, QString, QString, std::string);
    void onTileSelect(int, int);
    void onTileReturn();

signals:

};

#endif // GAMEWINDOW_H
