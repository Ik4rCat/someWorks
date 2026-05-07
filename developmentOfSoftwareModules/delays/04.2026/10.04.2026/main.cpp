// main.cpp
#include <QApplication>
#include <QTimer>
#include "MainWindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    return app.exec();
}
