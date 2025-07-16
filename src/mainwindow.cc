#include "mainwindow.h"
#include "version.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow{parent}, game{new GameWindow} {

    setCentralWidget(game);
    connect(game, SIGNAL (quit()), this, SLOT (close()));

    QMenu *helpMenu = menuBar()->addMenu("Help");
    QAction *about   = helpMenu->addAction(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout),
                        "About this program");
    QAction *aboutQt = helpMenu->addAction(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq),
                        "About Qt");
    connect(about,   SIGNAL (triggered()), this, SLOT (displayAboutInfo()));
    connect(aboutQt, SIGNAL (triggered()), this, SLOT (displayAboutQtInfo()));

    connect(game, SIGNAL (displayMenuBar(bool)), this, SLOT (toggleMenuBar(bool)));
}

void MainWindow::displayAboutInfo() {
    QString text ("QtAnswer version ");
    text.append(QTANS_VERSION);
    text.append(" by Adam Rudy.<br>Licensed under the terms of the ");
    text.append("<a href=\"https://raw.githubusercontent.com/arudy05/qtanswer/refs/heads/master/LICENSE\">MIT License</a>.<br>");
    text.append("The source code can be found at <a href=\"https://github.com/arudy05/qtanswer\"> https://github.com/arudy05/qtanswer </a>");

    QMessageBox about(QMessageBox::Information, "About QtAnswer", text);
    about.setTextFormat(Qt::RichText);
    about.exec();
}

void MainWindow::displayAboutQtInfo() {
    QMessageBox::aboutQt(this);
}

void MainWindow::toggleMenuBar(bool state) {
    menuBar()->setVisible(state);
}
