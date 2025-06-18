#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <vector>

class StartWidget : public QWidget {
    Q_OBJECT
    QGridLayout *layout;
    QLabel *title;
    QLabel *playerNameText;
    std::vector<QLineEdit*> playerNames;
    QPushButton *startButton;
public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();

signals:
    void gameStart(QString p1, QString p2, QString p3);

public slots:
    void gameStartPressed();

};

#endif // STARTWIDGET_H
