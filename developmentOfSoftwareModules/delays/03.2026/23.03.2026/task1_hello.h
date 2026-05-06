// task1_hello.h — простейшее окно с меткой и кнопкой
#ifndef TASK1_HELLO_H
#define TASK1_HELLO_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class HelloWindow : public QWidget {
    QLabel       *label;
    QPushButton  *closeBtn;
public:
    HelloWindow(QWidget *parent = nullptr);
};

#endif
