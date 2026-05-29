#include <iostream>
#include <memory>
#include "PricingStrategy.h"
#include "EditorCommands.h"
#include "CommandHistory.h"

using namespace std;

// Лаб. №5, вариант 3: Command + Strategy

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

int main() {
    cout << "===== LABORATORY WORK 5 =====" << endl;
    cout << "Behavioral patterns: Command + Strategy" << endl;

    demoStrategy();
    demoCommand();

    return 0;
}
