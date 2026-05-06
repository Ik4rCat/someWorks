# Qt — Основы

## Что такое Qt

Qt — кроссплатформенная библиотека C++ для разработки GUI-приложений. Каждый элемент интерфейса — **виджет** (объект интерфейсного класса).

---

## Структура приложения

```
QApplication       — объект-приложение, цикл обработки сообщений
QWidget (win)      — главный виджет, управляет окном
  ├── QLabel       — метка
  ├── QPushButton  — кнопка
  └── QLayout      — компоновщик (управляет размерами)
```

### Минимальное приложение

```cpp
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // объект приложения

    QWidget win;                        // главный виджет
    win.setWindowTitle("Hello");

    QLabel *label = new QLabel("Hello!", &win);
    QPushButton *btn = new QPushButton("Close", &win);

    QHBoxLayout *layout = new QHBoxLayout(&win); // горизонтальный компоновщик
    layout->addWidget(label);
    layout->addWidget(btn);

    QObject::connect(btn, SIGNAL(clicked(bool)), &win, SLOT(close()));

    win.show();
    return app.exec();  // запуск цикла сообщений
}
```

**Контейнерные свойства:** `QWidget` как родитель автоматически удаляет дочерние виджеты — не нужно вручную вызывать `delete`.

---

## Класс окна (выделение в отдельный класс)

```cpp
// win.h
class Win : public QWidget {
    QLabel *helloLabel;
    QPushButton *exitButton;
public:
    Win(QWidget *parent = nullptr);
};

// win.cpp
Win::Win(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Приветствие");
    helloLabel  = new QLabel("Привет!", this);
    exitButton  = new QPushButton("Выход", this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(helloLabel);
    layout->addWidget(exitButton);

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

// main.cpp
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Win win;
    win.show();
    return app.exec();
}
```

---

## Компоновщики (Layouts)

| Класс | Описание |
|---|---|
| `QHBoxLayout` | Горизонтальное расположение |
| `QVBoxLayout` | Вертикальное расположение |
| `QGridLayout` | Сеточное расположение |
| `QFormLayout` | Форма (метка + поле) |

```cpp
QVBoxLayout *vLayout = new QVBoxLayout(this);
vLayout->addWidget(label);
vLayout->addWidget(lineEdit);
vLayout->addStretch(); // пружина — заполняет пустое пространство
```

Вложенные компоновщики:
```cpp
QHBoxLayout *hLayout = new QHBoxLayout(this);
hLayout->addWidget(frame);
hLayout->addLayout(vLayout2); // вложить вертикальный в горизонтальный
```
