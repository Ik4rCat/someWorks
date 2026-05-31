#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>

// Конструктор только координирует инициализацию (SRP)
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupWidgets();
    setupLayout();
    setupConnections();
    setWindowTitle("Конвертер USD -> EUR");
    resize(Config::WINDOW_W, Config::WINDOW_H);
}

void MainWindow::setupWidgets()
{
    dollarsEdit = new QLineEdit(this);
    dollarsEdit->setMinimumWidth(Config::INPUT_MIN_WIDTH);
    dollarsEdit->setMaximumWidth(Config::INPUT_MAX_WIDTH);
    dollarsEdit->setPlaceholderText("Введите сумму в USD");

    convertBtn = new QPushButton("Конвертировать", this);
    convertBtn->setFixedSize(Config::BTN_WIDTH, Config::BTN_HEIGHT);

    resultLabel = new QLabel("Результат: 0.00 €", this);
    resultLabel->setMinimumHeight(Config::RESULT_MIN_HEIGHT);
    resultLabel->setAlignment(Qt::AlignCenter);
    resultLabel->setStyleSheet("background-color: #f0f0f0; border: 1px solid gray;");
}

void MainWindow::setupLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(dollarsEdit);
    mainLayout->addWidget(convertBtn);
    mainLayout->addWidget(resultLabel);

    QWidget *central = new QWidget(this);
    central->setLayout(mainLayout);
    setCentralWidget(central);
}

void MainWindow::setupConnections()
{
    connect(convertBtn, &QPushButton::clicked, this, &MainWindow::onConvertClicked);
}

void MainWindow::showError(const QString &msg)
{
    resultLabel->setText(msg);
}

void MainWindow::onConvertClicked()
{
    // 1. Чтение ввода
    QString text = dollarsEdit->text();
    if (text.isEmpty()) {
        showError("Ошибка: введите число");
        return;
    }

    // 2. Валидация
    bool ok;
    double dollars = text.toDouble(&ok);
    if (!ok) {
        showError("Ошибка: неверное число");
        return;
    }

    // 3. Конвертация с именованной константой
    double euros = dollars * Config::USD_TO_EUR;

    // 4. Обновление UI
    resultLabel->setText(QString("Результат: %1 €").arg(euros, 0, 'f', 2));
}
