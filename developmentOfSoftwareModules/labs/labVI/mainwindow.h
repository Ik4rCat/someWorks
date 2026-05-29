#pragma once
#include <QMainWindow>
#include "formdata.h"
#include "formvalidator.h"
#include "filewriter.h"

class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QPushButton;
class QTextEdit;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void onSubmit();
    void onExit();
    void validateForm();

private:
    void     setupUi();
    void     clearForm();
    FormData collectData() const;

    // Обязательные поля
    QLineEdit*      m_lastName;
    QLineEdit*      m_firstName;
    QLineEdit*      m_patronymic;
    QSpinBox*       m_age;
    QDoubleSpinBox* m_eventRate;
    QTextEdit*      m_products;

    // Необязательные поля
    QLineEdit*      m_costume;
    QLineEdit*      m_eveningPlan;
    QDoubleSpinBox* m_budget;

    // Кнопки
    QPushButton*    m_submitBtn;
    QPushButton*    m_exitBtn;

    FileWriter*     m_fileWriter;
};
