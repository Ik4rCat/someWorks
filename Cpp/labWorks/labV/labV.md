# Лабораторная работа V — поведенческие паттерны (вариант 3: Command + Strategy)

---

## PricingStrategy.h

**Блок 1**

```cpp
struct LineItem {
    string name;
    double unitPrice;
    int quantity;
};
```

Структура одной позиции в корзине: название, цена за единицу и количество — данные, которые передаются во все стратегии расчёта.

**Блок 2**

```cpp
class IPricingStrategy {
public:
    virtual ~IPricingStrategy() = default;
    virtual double computeTotal(const vector<LineItem>& items) const = 0;
};

class RegularPricingStrategy : public IPricingStrategy {
public:
    double computeTotal(const vector<LineItem>& items) const override {
        double total = 0;
        for (const auto& i : items)
            total += i.unitPrice * i.quantity;
        return total;
    }
};

class StudentDiscountStrategy : public IPricingStrategy {
    double discountFraction;
public:
    explicit StudentDiscountStrategy(double fraction = 0.15) : discountFraction(fraction) {}
    double computeTotal(const vector<LineItem>& items) const override {
        double total = 0;
        for (const auto& i : items)
            total += i.unitPrice * i.quantity;
        return total * (1.0 - discountFraction);
    }
};
```

Интерфейс **Strategy**: единый контракт `computeTotal`. `RegularPricingStrategy` считает сумму без скидки; `StudentDiscountStrategy` — ту же сумму, умноженную на `(1 − доля скидки)`.

**Блок 3**

```cpp
class ShoppingCart {
    vector<LineItem> items;
    IPricingStrategy* strategy;
public:
    explicit ShoppingCart(IPricingStrategy* s) : strategy(s) {}
    void setStrategy(IPricingStrategy* s) { strategy = s; }
    void addItem(const LineItem& item) { items.push_back(item); }
    double checkoutTotal() const { return strategy->computeTotal(items); }
    const vector<LineItem>& getItems() const { return items; }
};
```

Контекст паттерна Strategy: хранит товары и **указатель на текущую стратегию**; итог при `checkoutTotal()` делегируется выбранной стратегии без дублирования логики корзины.

---

## ICommand.h

**Блок 1**

```cpp
class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual string describe() const = 0;
};
```

Базовый интерфейс **Command**: любая операция выполняется через `execute`, откатывается через `undo`, при необходимости можно получить текстовое описание.

---

## EditorCommands.h

**Блок 1**

```cpp
class TextBuffer {
    string data;
public:
    const string& text() const { return data; }
    void append(const string& s) { data += s; }
    void removeSuffix(size_t n) {
        if (n > data.size())
            n = data.size();
        data.resize(data.size() - n);
    }
};
```

**Получатель (receiver)** команд: строковый буфер с добавлением текста и удалением последних `n` символов — нужен для реализации отмены вставки.

**Блок 2**

```cpp
class AppendCommand : public ICommand {
    TextBuffer& buffer;
    string chunk;
public:
    AppendCommand(TextBuffer& buf, string s) : buffer(buf), chunk(std::move(s)) {}
    void execute() override { buffer.append(chunk); }
    void undo() override { buffer.removeSuffix(chunk.size()); }
    string describe() const override { return "append \"" + chunk + "\""; }
};
```

Конкретная **команда**: запоминает ссылку на буфер и вставляемый фрагмент; `execute` дописывает строку, `undo` убирает ровно столько символов, сколько было добавлено.

---

## CommandHistory.h

**Блок 1**

```cpp
class CommandHistory {
    vector<unique_ptr<ICommand>> done;
public:
    void executeCommand(unique_ptr<ICommand> cmd) {
        cmd->execute();
        done.push_back(std::move(cmd));
    }
    bool undoLast() {
        if (done.empty())
            return false;
        done.back()->undo();
        done.pop_back();
        return true;
    }
    size_t depth() const { return done.size(); }
};
```

**Invoker**: выполняет команду, кладёт её в стек `done`; `undoLast` отменяет последнюю выполненную команду и удаляет её из истории; `depth` показывает, сколько команд ещё можно откатить по порядку.

---

## Program.cpp

**Блок 1**

```cpp
#include <iostream>
#include <memory>
#include "PricingStrategy.h"
#include "EditorCommands.h"
#include "CommandHistory.h"

using namespace std;
```

Подключение стандартных заголовков и модулей лабораторной: стратегии ценообразования, команды редактора и история команд.

**Блок 2**

```cpp
void demoStrategy() {
    cout << "\n========== STRATEGY: ценообразование корзины ==========" << endl;

    RegularPricingStrategy regular;
    StudentDiscountStrategy student(0.15);

    ShoppingCart cart(&regular);
    cart.addItem({"Тетрадь", 50.0, 2});
    cart.addItem({"Ручка", 30.0, 1});

    cout << "Обычная цена: " << cart.checkoutTotal() << endl;

    cart.setStrategy(&student);
    cout << "Со студенческой скидкой 15%: " << cart.checkoutTotal() << endl;
}
```

Демонстрация **Strategy**: одна и та же корзина сначала считается обычной стратегией, затем переключается на студенческую скидку через `setStrategy` — меняется только алгоритм расчёта, не код добавления товаров.

**Блок 3**

```cpp
void demoCommand() {
    cout << "\n========== COMMAND: текстовый буфер + undo ==========" << endl;

    TextBuffer buf;
    CommandHistory history;

    history.executeCommand(make_unique<AppendCommand>(buf, "Hello "));
    history.executeCommand(make_unique<AppendCommand>(buf, "world"));
    cout << "После двух вставок: \"" << buf.text() << "\"" << endl;
    cout << "Глубина истории: " << history.depth() << endl;

    history.undoLast();
    cout << "После одного undo: \"" << buf.text() << "\"" << endl;

    history.undoLast();
    cout << "После второго undo: \"" << buf.text() << "\"" << endl;
}
```

Демонстрация **Command**: две вставки оформлены как отдельные объекты-команды, затем дважды вызывается отмена — буфер возвращается к состоянию до операций в обратном порядку.

**Блок 4**

```cpp
int main() {
    cout << "===== LABORATORY WORK 5 =====" << endl;
    cout << "Behavioral patterns: Command + Strategy" << endl;

    demoStrategy();
    demoCommand();

    return 0;
}
```

Точка входа: заголовок работы и последовательный запуск обеих демонстраций паттернов.

---

## Вывод по работе

Паттерн **Strategy** отделяет правила расчёта суммы от логики корзины и позволяет подменять их во время работы программы. Паттерн **Command** представляет действия над буфером как объекты с отменой и собирает их в историю у **Invoker** — так реализуется сценарий «выполнить / откатить последнее».

---

## Сборка

```bash
g++ -std=c++17 -Wall -Wextra -o labV Program.cpp
./labV
```
