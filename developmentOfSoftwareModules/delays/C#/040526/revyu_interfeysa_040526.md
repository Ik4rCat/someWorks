# Ревью интерфейса (Qt) — 04.05.26

Сравниваем две версии Qt-калькулятора: **с ошибками** (MainWindow) и **исправленную** (CalculatorWindow).

---

## Версия с ошибками — MainWindow

```cpp
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void onButton1Clicked();
    void onButton2Clicked();
private:
    QLineEdit *edit1;
    QLineEdit *edit2;
    QPushButton *btn1;
    QPushButton *btn2;
    QLabel *resultLabel;
    QVBoxLayout *layout;  // ❌ layout — публичный член класса
    QWidget *central;
};
```

### Проблемы в MainWindow

| # | Проблема | Описание |
|---|----------|----------|
| 1 | **layout публичный** | `QVBoxLayout *layout` объявлен в `public` — внутренние виджеты доступны извне |
| 2 | **Старый синтаксис SIGNAL/SLOT** | `connect(btn1, SIGNAL(clicked()), this, SLOT(...))` — не проверяется на этапе компиляции |
| 3 | **Нет валидации ввода** | Пользователь может ввести буквы — `toInt()` вернёт 0 без предупреждения |
| 4 | **Нет сообщений об ошибке** | При пустых полях просто выводит "Result: 0" без объяснений |
| 5 | **setFixedSize(800, 600)** | Жёстко зафиксированный размер — не адаптируется под контент |
| 6 | **Сырые указатели** | `QLineEdit *edit1` — нет умных указателей, потенциальные утечки при исключениях |
| 7 | **Нет разделения ответственности** | Логика подсчёта и UI смешаны в одном методе |

---

## Исправленная версия — CalculatorWindow

```cpp
class CalculatorWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit CalculatorWindow(QWidget *parent = nullptr);
private slots:
    void calculateSum();
    void clearInputs();
    void onInputChanged();
private:
    void setupUi();
    void setupConnections();
    void setupValidators();
    bool validateInputs() const;

    std::unique_ptr<QLineEdit> firstNumberEdit;
    std::unique_ptr<QLineEdit> secondNumberEdit;
    std::unique_ptr<QPushButton> calculateButton;
    std::unique_ptr<QPushButton> clearButton;
    std::unique_ptr<QLabel> resultLabel;
    std::unique_ptr<QLabel> errorLabel;
    std::unique_ptr<QGridLayout> mainLayout;

    static constexpr int WINDOW_MIN_WIDTH = 400;
    static constexpr int WINDOW_MIN_HEIGHT = 250;
    static constexpr int SPACING = 10;
};
```

### Улучшения в CalculatorWindow

| # | Улучшение | Как исправлено |
|---|-----------|----------------|
| 1 | **unique_ptr** | Все виджеты через `std::unique_ptr` — автоматическое управление памятью |
| 2 | **Новый синтаксис connect** | `connect(btn, &QPushButton::clicked, this, &CalculatorWindow::calculateSum)` — проверка на этапе компиляции |
| 3 | **QIntValidator** | Поля принимают только целые числа — ввод буквы физически невозможен |
| 4 | **errorLabel** | Отдельный label для ошибок, скрывается при правильном вводе |
| 5 | **setMinimumSize** | Окно гибкое, только минимальный размер зафиксирован |
| 6 | **Разделение методов** | `setupUi()`, `setupConnections()`, `setupValidators()`, `validateInputs()` — каждый делает одно |
| 7 | **constexpr константы** | Магические числа заменены именованными константами |
| 8 | **explicit конструктор** | Запрет неявного преобразования типов |
| 9 | **Real-time валидация** | `onInputChanged` — кнопка Calculate дизейблится пока поля пустые |

---

## Итог

Исправленная версия следует принципам: **SRP** (каждый метод — одна задача), **RAII** (умные указатели), **defensive programming** (валидация до вычислений). Старая версия работает, но хрупка и трудно расширяема.
