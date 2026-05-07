#include "formvalidator.h"

bool FormValidator::isValid(
    const QString& firstName,
    const QString& lastName,
    const QString& patronymic,
    int            age,
    double         eventRate,
    const QString& products)
{
    return !firstName.trimmed().isEmpty()
        && !lastName.trimmed().isEmpty()
        && !patronymic.trimmed().isEmpty()
        && age > 0
        && eventRate > 0.0
        && !products.trimmed().isEmpty();
}
