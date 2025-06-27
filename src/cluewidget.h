#ifndef CLUEWIDGET_H
#define CLUEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QProgressBar>
#include <QKeyEvent>
#include <QLineEdit>
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
    int currentPlayer;              // last player to buzz in
    std::vector<std::string> answers; // all possible answers for a given clue
    std::vector<bool> playerWrong;  // flags for if players are wrong
    QLabel *answerBoxText;          // text containing player name
    QLineEdit *answerBox;           // space to enter player answer

public:
    explicit ClueWidget(QWidget *parent = nullptr);
    ~ClueWidget();
    void keyPressEvent(QKeyEvent *event);
    void setClueFile(std::string path);
    void startCountdown();

public slots:
    void initGame(QString, QString, QString);
    void selectClue(int val, std::string, std::string, std::vector<std::string>);
    void playerBuzzIn(int p);
    void playerAnswer();
    void tickDown();

signals:
    void clueReturn (int player, int val);
    void incorrectAns (int player, int val);
};

#endif // CLUEWIDGET_H
