#pragma once
#include <QObject>
#include <QTimer>
#include <QString>

// Класс-датчик: периодически излучает сигнал valueChanged(int)
class Sensor : public QObject
{
    Q_OBJECT

public:
    explicit Sensor(const QString &name, int baseValue, QObject *parent = nullptr);

    QString name() const;

signals:
    void valueChanged(int value);

private slots:
    void onTimer();

private:
    QString m_name;
    int     m_value;
    QTimer  m_timer;
};
