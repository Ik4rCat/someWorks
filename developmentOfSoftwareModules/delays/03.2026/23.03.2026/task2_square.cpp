// task2_square.cpp — возведение числа в квадрат
#include "task2_square.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

SquareWindow::SquareWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Возведение в квадрат");

    inputLabel  = new QLabel("Введите число:", this);
    inputEdit   = new QLineEdit(this);
    outputLabel = new QLabel("Результат:", this);
    outputEdit  = new QLineEdit(this);
    outputEdit->setReadOnly(true);
    calcBtn     = new QPushButton("Вычислить", this);
    resetBtn    = new QPushButton("Сброс", this);
    exitBtn     = new QPushButton("Выход", this);

    // Валидатор
    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    // Компоновка
    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(inputLabel);
    leftLayout->addWidget(inputEdit);
    leftLayout->addWidget(outputLabel);
    leftLayout->addWidget(outputEdit);

    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->addWidget(calcBtn);
    rightLayout->addWidget(resetBtn);
    rightLayout->addWidget(exitBtn);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    // Сигналы
    connect(exitBtn,  SIGNAL(clicked(bool)),   this, SLOT(close()));
    connect(resetBtn, SIGNAL(clicked(bool)),   this, SLOT(reset()));
    connect(calcBtn,  SIGNAL(clicked(bool)),   this, SLOT(calc()));
    connect(inputEdit,SIGNAL(returnPressed()), this, SLOT(calc()));

    reset();
}

void SquareWindow::reset() {
    inputEdit->clear();
    outputEdit->clear();
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    inputEdit->setEnabled(true);
    inputEdit->setFocus();
    calcBtn->setEnabled(true);
}

void SquareWindow::calc() {
    bool ok;
    double a = inputEdit->text().toDouble(&ok);
    if (ok) {
        outputEdit->setText(QString::number(a * a));
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        inputEdit->setEnabled(false);
        calcBtn->setEnabled(false);
        resetBtn->setFocus();
    } else if (!inputEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введено неверное значение!");
    }
}
