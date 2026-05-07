#pragma once
#include <QString>
#include <QStringList>

// Модель данных анкеты
class FormData {
public:
    // Обязательные поля
    QString     firstName;
    QString     lastName;
    QString     patronymic;
    int         age;
    double      eventRate;
    QStringList products;

    // Необязательные поля
    QString     costume;
    QString     eveningPlan;
    double      budget;
    bool        hasBudget;

    FormData();
};
