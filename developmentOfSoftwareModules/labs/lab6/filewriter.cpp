#include "filewriter.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

FileWriter::FileWriter(const QString& filePath)
    : m_filePath(filePath)
{}

bool FileWriter::write(const FormData& data)
{
    QFile file(m_filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        m_lastError = "Не удалось открыть файл: " + m_filePath;
        return false;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    out << "=== " << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") << " ===\n";
    out << "Имя: "       << data.firstName  << "\n";
    out << "Фамилия: "   << data.lastName   << "\n";
    out << "Отчество: "  << data.patronymic << "\n";
    out << "Возраст: "   << data.age        << "\n";
    out << "Ставка на мероприятии: " << data.eventRate << "\n";
    out << "Список продуктов: " << data.products.join(", ") << "\n";

    if (!data.costume.isEmpty())
        out << "Костюм: " << data.costume << "\n";
    if (!data.eveningPlan.isEmpty())
        out << "Как провести вечер: " << data.eveningPlan << "\n";
    if (data.hasBudget)
        out << "Готов потратить: " << data.budget << "\n";

    out << "\n";
    file.close();
    return true;
}

QString FileWriter::lastError() const
{
    return m_lastError;
}
