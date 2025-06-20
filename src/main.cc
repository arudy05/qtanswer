#include <QApplication>

#include "gamewindow.h"
#include "version.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    GameWindow window;
    window.setWindowTitle(WINDOW_HEADER);

    window.show();
    return app.exec();
}
