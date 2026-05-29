#pragma once
#include <QString>

// Проверка обязательных полей анкеты
class FormValidator {
public:
    static bool isValid(
        const QString& firstName,
        const QString& lastName,
        const QString& patronymic,
        int            age,
        double         eventRate,
        const QString& products
    );
};
