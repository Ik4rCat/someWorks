#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>       // Исправлено: добавлен символ #
#include <QPushButton>

// Именованные константы вместо магических чисел
namespace Config {
    constexpr int    INPUT_MIN_WIDTH   = 150;
    constexpr int    INPUT_MAX_WIDTH   = 200;
    constexpr int    BTN_WIDTH         = 120;
    constexpr int    BTN_HEIGHT        = 30;
    constexpr int    RESULT_MIN_HEIGHT = 40;
    constexpr int    WINDOW_W          = 300;
    constexpr int    WINDOW_H          = 200;
    constexpr double USD_TO_EUR        = 0.92;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onConvertClicked();

private:
    // Вынесенные вспомогательные методы (SRP)
    void setupWidgets();
    void setupLayout();
    void setupConnections();
    void showError(const QString &msg);

    QLineEdit  *dollarsEdit;
    QLabel     *resultLabel;
    QPushButton *convertBtn;
};

#endif // MAINWINDOW_H
