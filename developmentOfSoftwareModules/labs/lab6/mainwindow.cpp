#include "mainwindow.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , m_fileWriter(new FileWriter("anketa.txt"))
{
    setupUi();
}

void MainWindow::setupUi()
{
    setWindowTitle("Анкета участника мероприятия");
    setMinimumWidth(480);

    QWidget*     central    = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);
    setCentralWidget(central);

    // === Обязательные поля ===
    QGroupBox*   reqGroup = new QGroupBox("Обязательные поля", central);
    QFormLayout* reqForm  = new QFormLayout(reqGroup);

    m_lastName   = new QLineEdit(reqGroup);
    m_firstName  = new QLineEdit(reqGroup);
    m_patronymic = new QLineEdit(reqGroup);

    m_age = new QSpinBox(reqGroup);
    m_age->setRange(0, 120);
    m_age->setValue(0);
    m_age->setSpecialValueText(" ");

    m_eventRate = new QDoubleSpinBox(reqGroup);
    m_eventRate->setRange(0.0, 1000000.0);
    m_eventRate->setDecimals(2);
    m_eventRate->setSingleStep(100.0);
    m_eventRate->setSpecialValueText(" ");

    m_products = new QTextEdit(reqGroup);
    m_products->setPlaceholderText("Каждый продукт с новой строки");
    m_products->setMaximumHeight(80);

    reqForm->addRow("Фамилия *:",          m_lastName);
    reqForm->addRow("Имя *:",              m_firstName);
    reqForm->addRow("Отчество *:",         m_patronymic);
    reqForm->addRow("Возраст *:",          m_age);
    reqForm->addRow("Ставка (руб.) *:",    m_eventRate);
    reqForm->addRow("Список продуктов *:", m_products);

    // === Необязательные поля ===
    QGroupBox*   optGroup = new QGroupBox("Необязательные поля", central);
    QFormLayout* optForm  = new QFormLayout(optGroup);

    m_costume     = new QLineEdit(optGroup);
    m_eveningPlan = new QLineEdit(optGroup);

    m_budget = new QDoubleSpinBox(optGroup);
    m_budget->setRange(0.0, 1000000.0);
    m_budget->setDecimals(2);
    m_budget->setSingleStep(100.0);
    m_budget->setSpecialValueText("не указано");

    optForm->addRow("Ваш костюм:",             m_costume);
    optForm->addRow("Как провести вечер:",     m_eveningPlan);
    optForm->addRow("Готов потратить (руб.):", m_budget);

    // === Кнопки ===
    QHBoxLayout* btnLayout = new QHBoxLayout;
    m_submitBtn = new QPushButton("Отправить", central);
    m_submitBtn->setEnabled(false);
    m_exitBtn = new QPushButton("Выход", central);
    btnLayout->addWidget(m_submitBtn);
    btnLayout->addWidget(m_exitBtn);

    mainLayout->addWidget(reqGroup);
    mainLayout->addWidget(optGroup);
    mainLayout->addLayout(btnLayout);

    // === Сигналы ===
    connect(m_lastName,   &QLineEdit::textChanged,
            this, &MainWindow::validateForm);
    connect(m_firstName,  &QLineEdit::textChanged,
            this, &MainWindow::validateForm);
    connect(m_patronymic, &QLineEdit::textChanged,
            this, &MainWindow::validateForm);
    connect(m_age,        QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::validateForm);
    connect(m_eventRate,  QOverload<double>::of(&QDoubleSpinBox::valueChanged),
            this, &MainWindow::validateForm);
    connect(m_products,   &QTextEdit::textChanged,
            this, &MainWindow::validateForm);
    connect(m_submitBtn,  &QPushButton::clicked,
            this, &MainWindow::onSubmit);
    connect(m_exitBtn,    &QPushButton::clicked,
            this, &MainWindow::onExit);
}

void MainWindow::validateForm()
{
    bool valid = FormValidator::isValid(
        m_firstName->text(),
        m_lastName->text(),
        m_patronymic->text(),
        m_age->value(),
        m_eventRate->value(),
        m_products->toPlainText()
    );
    m_submitBtn->setEnabled(valid);
}

void MainWindow::onSubmit()
{
    FormData data = collectData();
    if (!m_fileWriter->write(data)) {
        QMessageBox::warning(this, "Ошибка", m_fileWriter->lastError());
        return;
    }
    QMessageBox::information(this, "Успешно", "Данные сохранены в файл anketa.txt");
    clearForm();
}

void MainWindow::onExit()
{
    close();
}

FormData MainWindow::collectData() const
{
    FormData data;
    data.firstName  = m_firstName->text().trimmed();
    data.lastName   = m_lastName->text().trimmed();
    data.patronymic = m_patronymic->text().trimmed();
    data.age        = m_age->value();
    data.eventRate  = m_eventRate->value();

    const QStringList lines =
        m_products->toPlainText().split('\n', Qt::SkipEmptyParts);
    for (const QString& line : lines)
        data.products << line.trimmed();

    data.costume     = m_costume->text().trimmed();
    data.eveningPlan = m_eveningPlan->text().trimmed();
    data.budget      = m_budget->value();
    data.hasBudget   = (m_budget->value() > 0.0);
    return data;
}

void MainWindow::clearForm()
{
    m_firstName->clear();
    m_lastName->clear();
    m_patronymic->clear();
    m_age->setValue(0);
    m_eventRate->setValue(0.0);
    m_products->clear();
    m_costume->clear();
    m_eveningPlan->clear();
    m_budget->setValue(0.0);
    m_submitBtn->setEnabled(false);
}
