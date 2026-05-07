// Counter.h
#pragma once
#include <QObject>

class Counter : public QObject {
    Q_OBJECT
private:
    int m_value;
    int m_limit;

public:
    Counter(int limit = 5) : QObject(), m_value(0), m_limit(limit) {}

    int value() const { return m_value; }

public slots:
    void slotInc() {
        emit counterChanged(++m_value);
        if (m_value >= m_limit)
            emit goodbye();
    }

    void slotDec() {
        if (m_value > 0)
            emit counterChanged(--m_value);
    }

    void slotReset() {
        m_value = 0;
        emit counterChanged(m_value);
    }

signals:
    void counterChanged(int newValue);
    void goodbye();
};
