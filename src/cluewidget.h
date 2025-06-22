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
#include "cluefile.h"

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
    ClueFile *file;                  // clues and stuff

public:
    explicit ClueWidget(QWidget *parent = nullptr);
    ~ClueWidget();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void setPlayerNames(QString, QString, QString);
    void selectClue(int val, int cat);
    void playerBuzzIn(int p);
    void tickDown();

signals:
    void clueReturn (int player, int val);
};

#endif // CLUEWIDGET_H
