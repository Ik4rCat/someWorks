#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onTimer();

private:
    QTimer  m_timer;
    double  m_angle = 0.0;  // текущий угол орбиты (градусы)
};

#endif // MAINWINDOW_H
