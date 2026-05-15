#pragma once
#include <QMainWindow>
#include "sensor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    // вызывается при смене выбора в комбо-боксе
    void onSensorChanged(int index);

    // единственный слот, который отображает значение текущего датчика
    void displayValue(int value);

private:
    Ui::MainWindow *ui;

    Sensor *m_sensors[3];   // три объекта-датчика
    int     m_currentIndex; // индекс активного датчика
};
