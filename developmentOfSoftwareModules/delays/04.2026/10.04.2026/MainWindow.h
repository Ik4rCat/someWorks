// MainWindow.h
#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Counter.h"

class MainWindow : public QWidget {
    Q_OBJECT

    QLabel*      valueLabel;
    QLabel*      statusLabel;
    QPushButton* incBtn;
    QPushButton* decBtn;
    QPushButton* resetBtn;
    Counter*     counter;

public:
    MainWindow(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowTitle("Counter — сигналы и слоты");
        setMinimumWidth(300);

        counter = new Counter(5, this);

        valueLabel  = new QLabel("0",         this);
        statusLabel = new QLabel("Нажмите +", this);
        incBtn      = new QPushButton("+1",    this);
        decBtn      = new QPushButton("-1",    this);
        resetBtn    = new QPushButton("Reset", this);

        // Стиль метки значения
        valueLabel->setAlignment(Qt::AlignCenter);
        QFont f = valueLabel->font();
        f.setPointSize(48);
        f.setBold(true);
        valueLabel->setFont(f);

        // Компоновка кнопок
        QHBoxLayout* btnLayout = new QHBoxLayout();
        btnLayout->addWidget(decBtn);
        btnLayout->addWidget(resetBtn);
        btnLayout->addWidget(incBtn);

        // Главная компоновка
        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(valueLabel);
        mainLayout->addWidget(statusLabel);
        mainLayout->addLayout(btnLayout);

        // Соединения — новый стиль (ошибки на этапе компиляции)
        connect(incBtn,   &QPushButton::clicked, counter, &Counter::slotInc);
        connect(decBtn,   &QPushButton::clicked, counter, &Counter::slotDec);
        connect(resetBtn, &QPushButton::clicked, counter, &Counter::slotReset);

        // Обновление метки при изменении счётчика
        connect(counter, &Counter::counterChanged,
                this,    &MainWindow::onCounterChanged);

        // Завершение при достижении лимита
        connect(counter, &Counter::goodbye,
                this,    &MainWindow::onGoodbye);
    }

public slots:
    void onCounterChanged(int val) {
        valueLabel->setText(QString::number(val));
        statusLabel->setText(QString("Значение: %1").arg(val));
    }

    void onGoodbye() {
        statusLabel->setText("Лимит достигнут! Сброс...");
        incBtn->setEnabled(false);
        // Автосброс через 1.5 секунды
        QTimer::singleShot(1500, this, [this]() {
            counter->slotReset();
            incBtn->setEnabled(true);
            statusLabel->setText("Сброшено. Нажмите +");
        });
    }
};
