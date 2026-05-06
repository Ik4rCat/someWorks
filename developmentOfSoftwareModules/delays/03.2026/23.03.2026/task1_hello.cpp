// task1_hello.cpp — простейшее окно
#include "task1_hello.h"
#include <QHBoxLayout>

HelloWindow::HelloWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Hello Qt");

    label    = new QLabel("Hello, Qt!", this);
    closeBtn = new QPushButton("Close", this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(closeBtn);

    connect(closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}
