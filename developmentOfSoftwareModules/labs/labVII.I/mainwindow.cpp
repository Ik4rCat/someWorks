#include "mainwindow.h"

#include <QPainter>
#include <QPaintEvent>
#include <cmath>

static constexpr double PI    = M_PI;
static constexpr int    ORBIT = 140;  // радиус орбиты
static constexpr int    SPEED = 2;    // градусов за тик
static constexpr int    TICK  = 16;   // ~60 fps

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Лб7 — Анимация фигур");
    setFixedSize(500, 500);

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::onTimer);
    m_timer.start(TICK);
}

void MainWindow::onTimer()
{
    m_angle += SPEED;
    if (m_angle >= 360.0) m_angle -= 360.0;
    update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    // Фон
    p.fillRect(rect(), QColor(30, 30, 46));

    const int cx = width()  / 2;
    const int cy = height() / 2;

    // Направляющая окружность (пунктир)
    p.setPen(QPen(QColor(88, 91, 112), 1, Qt::DashLine));
    p.setBrush(Qt::NoBrush);
    p.drawEllipse(QPoint(cx, cy), ORBIT, ORBIT);

    // Три фигуры — равномерно по 120° друг от друга
    struct Shape { double offset; QColor color; };
    const Shape shapes[3] = {
        {   0.0, QColor(137, 180, 250) },  // синий   — круг
        { 120.0, QColor(166, 227, 161) },  // зелёный — квадрат
        { 240.0, QColor(243, 139, 168) },  // красный — линия
    };

    for (int i = 0; i < 3; i++) {
        double rad = (m_angle + shapes[i].offset) * PI / 180.0;
        int x = cx + static_cast<int>(ORBIT * std::cos(rad));
        int y = cy + static_cast<int>(ORBIT * std::sin(rad));

        p.save();
        p.translate(x, y);
        p.rotate(m_angle + shapes[i].offset);

        p.setPen(QPen(shapes[i].color, 2));
        p.setBrush(shapes[i].color.darker(180));

        if (i == 0) {
            // Круг
            p.drawEllipse(QPoint(0, 0), 20, 20);
        } else if (i == 1) {
            // Квадрат
            p.drawRect(-16, -16, 32, 32);
        } else {
            // Линия (крест — виден под любым углом вращения)
            p.setPen(QPen(shapes[i].color, 3));
            p.drawLine(-22, 0, 22, 0);
            p.drawLine(0, -22, 0, 22);
        }

        p.restore();
    }

    // Центральная точка
    p.setPen(Qt::NoPen);
    p.setBrush(QColor(205, 214, 244));
    p.drawEllipse(QPoint(cx, cy), 5, 5);
}
