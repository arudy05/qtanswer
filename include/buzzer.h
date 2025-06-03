#ifndef BUZZER_H
#define BUZZER_H

#include <QPushButton>

// A Buzzer object is essentially just a wrapper for a QPushButton
// with some extra stuff specific to this application (similar to Tile)
class Buzzer : public QObject {
    Q_OBJECT
    int player;

public:
    QPushButton *button;
    Buzzer(int p);
    ~Buzzer();

public slots:
    void onButtonPress();

signals:
    void buzzIn(int p);

};

#endif // BUZZER_H
