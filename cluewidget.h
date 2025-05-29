#ifndef CLUEWIDGET_H
#define CLUEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <vector>
#include "buzzer.h"

class ClueWidget : public QWidget {
    Q_OBJECT
    QGridLayout *layout;
    QLabel *category;
    QLabel *clue;
    int val;
    std::vector<Buzzer*> buzzers;
public:
    explicit ClueWidget(QWidget *parent = nullptr);

public slots:
    void selectClue(int val, int cat);
    void playerBuzzIn(int p);

signals:
    void clueReturn (int player, int val);
};

#endif // CLUEWIDGET_H
