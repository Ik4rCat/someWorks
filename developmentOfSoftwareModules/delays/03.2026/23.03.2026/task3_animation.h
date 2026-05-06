// task3_animation.h — движущиеся фигуры с таймером
#ifndef TASK3_ANIMATION_H
#define TASK3_ANIMATION_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <cmath>

// ── Абстрактная фигура ───────────────────────────────
class Figura {
protected:
    int x, y, halflen, dx = 0, dy = 0;
    virtual void draw(QPainter *p) = 0;
public:
    Figura(int x, int y, int hl) : x(x), y(y), halflen(hl) {}
    virtual ~Figura() {}
    void move(float alpha, QPainter *p) {
        dx = static_cast<int>(halflen * std::cos(alpha));
        dy = static_cast<int>(halflen * std::sin(alpha));
        draw(p);
    }
};

class MyLine : public Figura {
public:
    MyLine(int x, int y, int hl) : Figura(x, y, hl) {}
    void draw(QPainter *p) override {
        p->drawLine(x+dx, y+dy, x-dx, y-dy);
    }
};

class MyRect : public Figura {
public:
    MyRect(int x, int y, int hl) : Figura(x, y, hl) {}
    void draw(QPainter *p) override {
        p->drawLine(x+dx, y+dy, x+dy, y-dx);
        p->drawLine(x+dy, y-dx, x-dx, y-dy);
        p->drawLine(x-dx, y-dy, x-dy, y+dx);
        p->drawLine(x-dy, y+dx, x+dx, y+dy);
    }
};

// ── Холст ────────────────────────────────────────────
class Area : public QWidget {
    int    myTimer = 0;
    float  alpha   = 0.0f;
    MyLine *myline;
    MyRect *myrect;

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setPen(QPen(Qt::red, 2));
        myline->move(alpha,         &painter);
        painter.setPen(QPen(Qt::blue, 2));
        myrect->move(alpha * -0.5f, &painter);
    }
    void timerEvent(QTimerEvent *e) override;
    void showEvent(QShowEvent *)  override { myTimer = startTimer(50); }
    void hideEvent(QHideEvent *)  override { killTimer(myTimer); }

public:
    Area(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(300, 200);
        setStyleSheet("background-color: white;");
        myline = new MyLine(80,  100, 50);
        myrect = new MyRect(220, 100, 50);
    }
    ~Area() { delete myline; delete myrect; }
};

// ── Главное окно ─────────────────────────────────────
class AnimationWindow : public QWidget {
public:
    AnimationWindow(QWidget *parent = nullptr);
};

#endif
