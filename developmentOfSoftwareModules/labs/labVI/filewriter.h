#pragma once
#include "formdata.h"
#include <QString>

// Запись данных анкеты в текстовый файл
class FileWriter {
public:
    explicit FileWriter(const QString& filePath);

    bool    write(const FormData& data);
    QString lastError() const;

private:
    QString m_filePath;
    QString m_lastError;
};
