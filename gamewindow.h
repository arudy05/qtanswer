#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "boardwidget.h"
#include "cluewidget.h"

class GameWindow : public QWidget {
    Q_OBJECT
    QStackedLayout *layout;
    BoardWidget *board;
    ClueWidget *clueDisplay;
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
public slots:
    void onTileSelect();
    void onTileReturn();

signals:

};

#endif // GAMEWINDOW_H
