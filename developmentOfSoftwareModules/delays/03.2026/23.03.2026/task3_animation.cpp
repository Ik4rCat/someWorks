// task3_animation.cpp
#include "task3_animation.h"
#include <QVBoxLayout>
#include <QTimerEvent>

void Area::timerEvent(QTimerEvent *e) {
    if (e->timerId() == myTimer) {
        alpha += 0.05f;
        update();
    } else {
        QWidget::timerEvent(e);
    }
}

AnimationWindow::AnimationWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Движущиеся фигуры");

    Area        *area = new Area(this);
    QPushButton *btn  = new QPushButton("Завершить", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(close()));
}
