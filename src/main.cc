#include <QApplication>

#include "mainwindow.h"
#include "version.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    MainWindow window;
    window.setWindowTitle(WINDOW_HEADER);

    window.show();
    return app.exec();
}
