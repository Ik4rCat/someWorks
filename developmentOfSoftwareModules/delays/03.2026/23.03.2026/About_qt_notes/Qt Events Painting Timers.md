# Qt — События, рисование, таймеры

## Обработка событий

Qt доставляет события через виртуальные методы класса. Переопределяешь нужный — обрабатываешь событие.

| Метод | Событие |
|---|---|
| `paintEvent(QPaintEvent*)` | запрос на перерисовку виджета |
| `timerEvent(QTimerEvent*)` | срабатывание таймера |
| `showEvent(QShowEvent*)` | виджет становится видимым |
| `hideEvent(QHideEvent*)` | виджет скрывается |
| `mousePressEvent(QMouseEvent*)` | нажатие кнопки мыши |
| `keyPressEvent(QKeyEvent*)` | нажатие клавиши |
| `resizeEvent(QResizeEvent*)` | изменение размера |

---

## Таймер

```cpp
int timerId = startTimer(50);  // интервал в мс → возвращает ID

void Area::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timerId) {
        alpha += 0.2;
        update();  // запрашивает перерисовку → вызовет paintEvent()
    } else {
        QWidget::timerEvent(event); // передать необработанное дальше
    }
}

void Area::hideEvent(QHideEvent *) {
    killTimer(timerId);  // остановить таймер
}
```

`update()` — не рисует сразу, а ставит запрос в очередь → Qt сам вызовет `paintEvent()`.

---

## Рисование (QPainter)

Рисование происходит **только внутри `paintEvent()`**:

```cpp
void Area::paintEvent(QPaintEvent *) {
    QPainter painter(this);       // контекст рисования на виджете
    painter.setPen(Qt::red);      // цвет пера
    painter.setBrush(Qt::blue);   // цвет заливки

    painter.drawLine(x1, y1, x2, y2);           // линия
    painter.drawRect(x, y, width, height);       // прямоугольник
    painter.drawEllipse(x, y, width, height);    // эллипс
    painter.drawText(x, y, "текст");             // текст
}
```

---

## Пример: движущиеся фигуры

### Иерархия классов

```
Figura (абстрактный)
  ├── MyLine   — рисует линию
  └── MyRect   — рисует квадрат

Area : QWidget  — холст с таймером
Window : QWidget — окно с холстом и кнопкой
```

### Figura — абстрактный класс фигуры

```cpp
class Figura {
protected:
    int x, y, halflen, dx, dy;
    virtual void draw(QPainter *painter) = 0;  // чисто виртуальный
public:
    Figura(int x, int y, int halflen) : x(x), y(y), halflen(halflen) {}
    virtual ~Figura() {}

    void move(float alpha, QPainter *painter) {
        dx = static_cast<int>(halflen * cos(alpha));
        dy = static_cast<int>(halflen * sin(alpha));
        draw(painter);  // полиморфный вызов
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
```

### Area — холст

```cpp
class Area : public QWidget {
    int myTimer;
    float alpha = 0;
    MyLine *myline;
    MyRect *myrect;

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setPen(Qt::red);
        myline->move(alpha,        &painter);
        myrect->move(alpha * -0.5, &painter);
    }
    void timerEvent(QTimerEvent *e) override {
        if (e->timerId() == myTimer) { alpha += 0.2; update(); }
        else QWidget::timerEvent(e);
    }
    void showEvent(QShowEvent *)  override { myTimer = startTimer(50); }
    void hideEvent(QHideEvent *)  override { killTimer(myTimer); }

public:
    Area(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(300, 200);
        myline = new MyLine(80,  100, 50);
        myrect = new MyRect(220, 100, 50);
    }
    ~Area() { delete myline; delete myrect; }
};
```

### Window — главное окно

```cpp
class Window : public QWidget {
public:
    Window() {
        setWindowTitle("Обработка событий");
        Area *area = new Area(this);
        QPushButton *btn = new QPushButton("Завершить", this);
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(area);
        layout->addWidget(btn);
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(close()));
    }
};
```
