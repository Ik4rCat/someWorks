// task2_square.h — возведение числа в квадрат
#ifndef TASK2_SQUARE_H
#define TASK2_SQUARE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QValidator>

class StrValidator : public QValidator {
public:
    StrValidator(QObject *parent) : QValidator(parent) {}
    State validate(QString &str, int &pos) const override {
        Q_UNUSED(str); Q_UNUSED(pos);
        return Acceptable;
    }
};

class SquareWindow : public QWidget {
    Q_OBJECT

    QLabel       *inputLabel;
    QLineEdit    *inputEdit;
    QLabel       *outputLabel;
    QLineEdit    *outputEdit;
    QPushButton  *calcBtn;
    QPushButton  *resetBtn;
    QPushButton  *exitBtn;

public:
    SquareWindow(QWidget *parent = nullptr);

public slots:
    void reset();
    void calc();
};

#endif
