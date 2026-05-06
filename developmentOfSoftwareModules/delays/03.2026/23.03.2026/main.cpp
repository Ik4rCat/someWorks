// main.cpp — точка входа, запускает AnimationWindow
// Для запуска другого задания замени include и класс окна

#include "task3_animation.h"
// #include "task1_hello.h"
// #include "task2_square.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    AnimationWindow win;
    // HelloWindow win;
    // SquareWindow win;
    win.show();
    return app.exec();
}
