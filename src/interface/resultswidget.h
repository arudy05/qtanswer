#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <player.h>

class ResultsWidget : public QWidget {
    Q_OBJECT
    QLabel *congrats;
    QLabel *winner;
    QPushButton *toMenu;
    QPushButton *exit;
    QGridLayout *layout;

public:
    explicit ResultsWidget(std::vector<Player*> players, QWidget *parent = nullptr);
    ~ResultsWidget();

private slots:
    void resetGameClicked();
    void quitGameClicked();

signals:
    void resetGame();
    void quitGame();

};

#endif // RESULTSWIDGET_H
