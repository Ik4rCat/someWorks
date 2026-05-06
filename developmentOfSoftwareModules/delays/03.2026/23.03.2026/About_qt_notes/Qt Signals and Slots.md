# Qt — Сигналы и слоты

## Механизм сигналов и слотов

Основной способ коммуникации между объектами в Qt. Заменяет callback-функции.

- **Сигнал** — событие, которое генерирует объект (нажатие кнопки, изменение текста)
- **Слот** — метод, который вызывается в ответ на сигнал
- **connect()** — связывает сигнал со слотом

```cpp
QObject::connect(sender,   SIGNAL(сигнал()),
                 receiver, SLOT(слот()));
```

Один сигнал можно подключить к нескольким слотам, и наоборот.

---

## Объявление слотов

Для использования сигналов/слотов в своём классе нужно:
1. Унаследовать от `QObject` (или его потомка — `QWidget` и др.)
2. Добавить макрос `Q_OBJECT` в начало класса
3. Объявить методы в секции `public slots:`

```cpp
class Win : public QWidget {
    Q_OBJECT  // обязательный макрос!

public:
    Win(QWidget *parent = nullptr);

public slots:
    void begin();  // инициализация интерфейса
    void calc();   // вычисления
};
```

---

## Пример: возведение числа в квадрат

```cpp
// Подключение сигналов к слотам
connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin()));
connect(inputEdit,  SIGNAL(returnPressed()),  this, SLOT(calc()));

// Слот begin() — сброс интерфейса
void Win::begin() {
    inputEdit->clear();
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    nextButton->setEnabled(false);
    inputEdit->setFocus();
}

// Слот calc() — вычисление
void Win::calc() {
    bool ok;
    QString str = inputEdit->text();
    float a = str.toDouble(&ok);
    if (ok) {
        float r = a * a;
        outputEdit->setText(QString::number(r));
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        inputEdit->setEnabled(false);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    } else if (!str.isEmpty()) {
        QMessageBox::information(this, "Ошибка", "Введено неверное значение.");
    }
}
```

---

## Валидатор ввода

`QValidator` — объект проверки введённой строки. Привязывается к `QLineEdit`.

```cpp
class StrValidator : public QValidator {
public:
    StrValidator(QObject *parent) : QValidator(parent) {}
    State validate(QString &str, int &pos) const override {
        return Acceptable; // всегда принимаем
    }
};

// Использование:
StrValidator *v = new StrValidator(inputEdit);
inputEdit->setValidator(v);
// Теперь inputEdit генерирует returnPressed() и editingFinished()
```

Стандартные валидаторы Qt: `QIntValidator`, `QDoubleValidator`, `QRegExpValidator`.

---

## Часто используемые сигналы

| Виджет | Сигнал | Когда |
|---|---|---|
| `QPushButton` | `clicked(bool)` | нажатие кнопки |
| `QLineEdit` | `returnPressed()` | нажатие Enter |
| `QLineEdit` | `editingFinished()` | завершение редактирования |
| `QLineEdit` | `textChanged(QString)` | изменение текста |
| `QCheckBox` | `stateChanged(int)` | смена состояния |
| `QSlider` | `valueChanged(int)` | изменение значения |
