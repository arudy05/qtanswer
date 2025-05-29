#ifndef TILE_H
#define TILE_H

#include <QPushButton>

// A Tile object is essentially just a wrapper for a QPushButton
// with some extra stuff specific to this application
class Tile : public QObject {
    Q_OBJECT
    int value;
    int category;

public:
    QPushButton *button;
    Tile(int val, int cat);
    ~Tile();
    void disable();

public slots:
    void onButtonPress();

signals:
    void tilePressed(int val, int cat);

};

#endif // TILE_H
