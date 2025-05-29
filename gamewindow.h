#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "boardwidget.h"

class GameWindow : public QWidget {
    Q_OBJECT
    QStackedLayout *layout;
    BoardWidget *board;
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
signals:

};

#endif // GAMEWINDOW_H
