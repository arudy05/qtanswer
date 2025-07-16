#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include "gamewindow.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
    GameWindow *game;
public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void displayAboutInfo();
    void displayAboutQtInfo();
    void toggleMenuBar(bool state);
signals:

};

#endif // MAINWINDOW_H
