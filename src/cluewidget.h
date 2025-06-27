#ifndef CLUEWIDGET_H
#define CLUEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QProgressBar>
#include <QKeyEvent>
#include <vector>
#include "buzzer.h"

class ClueWidget : public QWidget {
    Q_OBJECT
    QGridLayout *layout;            // layout
    QLabel *category;               // category name display
    QLabel *clue;                   // clue body display
    int val;                        // how much this clue is worth
    int countdown;                  // countdown stuff
    QTimer *countdownTimer;         // |
    QLabel *countdownText;          // |
    QProgressBar *countdownBarL;    // |
    QProgressBar *countdownBarR;    // v
    std::vector<Buzzer*> buzzers;   // player buzzers

public:
    explicit ClueWidget(QWidget *parent = nullptr);
    ~ClueWidget();
    void keyPressEvent(QKeyEvent *event);
    void setClueFile(std::string path);

public slots:
    void initGame(QString, QString, QString);
    void selectClue(int val, std::string, std::string);
    void playerBuzzIn(int p);
    void tickDown();

signals:
    void clueReturn (int player, int val);
};

#endif // CLUEWIDGET_H
