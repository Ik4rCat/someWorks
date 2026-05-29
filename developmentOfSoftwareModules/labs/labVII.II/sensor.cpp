#include "sensor.h"
#include <QRandomGenerator>

Sensor::Sensor(const QString &name, int baseValue, QObject *parent)
    : QObject(parent)
    , m_name(name)
    , m_value(baseValue)
{
    connect(&m_timer, &QTimer::timeout, this, &Sensor::onTimer);
    m_timer.start(1000); // emit every 1 second
}

QString Sensor::name() const
{
    return m_name;
}

void Sensor::onTimer()
{
    // небольшое случайное отклонение, чтобы значение менялось
    m_value += QRandomGenerator::global()->bounded(-5, 6);
    emit valueChanged(m_value);
}
