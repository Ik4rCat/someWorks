#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_currentIndex(-1)
{
    ui->setupUi(this);
    setWindowTitle("Динамическое переподключение датчиков");

    // Создаём три датчика с разными именами и начальными значениями
    m_sensors[0] = new Sensor("Температура", 20,  this);
    m_sensors[1] = new Sensor("Влажность",   60,  this);
    m_sensors[2] = new Sensor("Давление",    760, this);

    // Заполняем комбо-бокс
    ui->comboBox->addItem("Температура");
    ui->comboBox->addItem("Влажность");
    ui->comboBox->addItem("Давление");

    // При смене выбора — переключаемся на новый датчик
    connect(ui->comboBox, &QComboBox::currentIndexChanged,
            this, &MainWindow::onSensorChanged);

    // Активируем первый датчик сразу
    onSensorChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSensorChanged(int index)
{
    // Отключаемся от старого датчика (если он был)
    if (m_currentIndex >= 0)
        disconnect(m_sensors[m_currentIndex], &Sensor::valueChanged,
                   this,                      &MainWindow::displayValue);

    // Переключаемся на новый
    m_currentIndex = index;
    connect(m_sensors[index], &Sensor::valueChanged,
            this,             &MainWindow::displayValue);

    // Обновляем подпись активного датчика
    ui->labelSensor->setText("Датчик: " + m_sensors[index]->name());
    ui->labelValue->setText("Значение: —");
}

void MainWindow::displayValue(int value)
{
    ui->labelValue->setText(QString("Значение: %1").arg(value));
}
