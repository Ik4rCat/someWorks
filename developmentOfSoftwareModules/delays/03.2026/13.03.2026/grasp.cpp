#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
using namespace std;

// ══════════════════════════════════════════════════════
//  1. INFORMATION EXPERT + 2. CREATOR
//  Система продаж: Sale → SaleItem → ProductSpec
//  Каждый класс — эксперт по своей части данных.
//  Sale (агрегирует SaleItem) → она и создаёт SaleItem.
// ══════════════════════════════════════════════════════

// ProductSpec — эксперт по цене товара
class ProductSpec {
    string name;
    double price;
public:
    ProductSpec(const string& n, double p) : name(n), price(p) {}
    string getName()  const { return name; }
    double getPrice() const { return price; } // Information Expert
};

// SaleItem — эксперт по подытогу одной позиции
class SaleItem {
    const ProductSpec& spec;
    int quantity;
public:
    SaleItem(const ProductSpec& s, int q) : spec(s), quantity(q) {}
    double getSubtotal() const { return spec.getPrice() * quantity; } // Information Expert
    void print() const {
        cout << "  " << spec.getName()
             << " x" << quantity
             << " = " << getSubtotal() << "\n";
    }
};

// Sale — эксперт по итогу; Creator для SaleItem
class Sale {
    vector<SaleItem*> items;
public:
    // Creator: Sale агрегирует SaleItem → она их создаёт
    void addItem(const ProductSpec& spec, int qty) {
        items.push_back(new SaleItem(spec, qty));
    }
    // Information Expert: Sale знает все позиции → считает итог
    double getTotal() const {
        double total = 0;
        for (auto* item : items) total += item->getSubtotal();
        return total;
    }
    void print() const {
        cout << "Позиции:\n";
        for (auto* item : items) item->print();
        cout << "Итого: " << getTotal() << "\n";
    }
    ~Sale() { for (auto* i : items) delete i; }
};

// ══════════════════════════════════════════════════════
//  3. CONTROLLER
//  SaleController обрабатывает системные события,
//  не относится к UI.
// ══════════════════════════════════════════════════════

class SaleController {
    Sale* currentSale = nullptr;
    map<string, ProductSpec*> catalog;
public:
    void addProduct(const string& name, double price) {
        catalog[name] = new ProductSpec(name, price);
    }
    void startSale() {
        delete currentSale;
        currentSale = new Sale();
        cout << "[Controller] Продажа начата\n";
    }
    void enterItem(const string& name, int qty) {
        if (!currentSale) { cout << "[Controller] Ошибка: продажа не начата\n"; return; }
        if (!catalog.count(name)) { cout << "[Controller] Товар не найден\n"; return; }
        currentSale->addItem(*catalog[name], qty);
        cout << "[Controller] Добавлен: " << name << " x" << qty << "\n";
    }
    void endSale() {
        if (!currentSale) return;
        cout << "[Controller] Итоги продажи:\n";
        currentSale->print();
    }
    ~SaleController() {
        delete currentSale;
        for (auto& p : catalog) delete p.second;
    }
};

// ══════════════════════════════════════════════════════
//  4. LOW COUPLING + 5. HIGH COHESION
//  EventBus разрывает прямую связь между компонентами.
//  Logger не знает о Sale, Sale не знает о Logger.
// ══════════════════════════════════════════════════════

class Logger {
public:
    void log(const string& msg) { cout << "[LOG] " << msg << "\n"; }
};

class EventBus {
    map<string, vector<function<void(const string&)>>> listeners;
public:
    void subscribe(const string& event, function<void(const string&)> fn) {
        listeners[event].push_back(fn);
    }
    void publish(const string& event, const string& data = "") {
        for (auto& fn : listeners[event]) fn(data);
    }
};

// ══════════════════════════════════════════════════════
//  6. POLYMORPHISM
//  Разные способы оплаты без if/switch.
// ══════════════════════════════════════════════════════

class IPayment {
public:
    virtual void pay(double amount) = 0;
    virtual ~IPayment() {}
};

class CashPayment : public IPayment {
public:
    void pay(double amount) override {
        cout << "[Cash] Оплачено наличными: " << amount << "\n";
    }
};

class CardPayment : public IPayment {
public:
    void pay(double amount) override {
        cout << "[Card] Оплачено картой: " << amount << "\n";
    }
};

class CryptoPayment : public IPayment {
public:
    void pay(double amount) override {
        cout << "[Crypto] Оплачено криптой: " << amount << "\n";
    }
};

// ══════════════════════════════════════════════════════
//  7. PURE FABRICATION + 8. INDIRECTION
//  PersistenceStorage — искусственный класс вне
//  предметной области. Sale → Storage → Database.
// ══════════════════════════════════════════════════════

class Database {
    map<int, string> records;
    int nextId = 1;
public:
    int insert(const string& data) {
        records[nextId] = data;
        cout << "[DB] Сохранена запись #" << nextId << ": " << data << "\n";
        return nextId++;
    }
    string find(int id) {
        return records.count(id) ? records[id] : "не найдено";
    }
};

// Pure Fabrication: не из предметной области
// Indirection: посредник между Sale и Database
class PersistenceStorage {
    Database& db;
public:
    PersistenceStorage(Database& d) : db(d) {}
    int saveSale(double total) {
        return db.insert("Sale total=" + to_string(total));
    }
    string loadSale(int id) { return db.find(id); }
};

// ══════════════════════════════════════════════════════
//  9. PROTECTED VARIATIONS
//  ITaxCalculator скрывает логику налогов.
//  Смена налоговой системы не затрагивает SaleWithTax.
// ══════════════════════════════════════════════════════

class ITaxCalculator {
public:
    virtual double calculate(double amount) = 0;
    virtual ~ITaxCalculator() {}
};

class RusTax : public ITaxCalculator {
public:
    double calculate(double amount) override {
        cout << "[Tax] НДС 20%\n";
        return amount * 0.20;
    }
};

class EUTax : public ITaxCalculator {
public:
    double calculate(double amount) override {
        cout << "[Tax] VAT 21%\n";
        return amount * 0.21;
    }
};

class SaleWithTax {
    double total;
    ITaxCalculator* tax;
public:
    SaleWithTax(double t, ITaxCalculator* tax) : total(t), tax(tax) {}
    double getFinalAmount() {
        double taxAmount = tax->calculate(total);
        cout << "  Налог: " << taxAmount << "\n";
        return total + taxAmount;
    }
};

// ══════════════════════════════════════════════════════
//  main
// ══════════════════════════════════════════════════════
int main() {
    cout << "=== 1+2. Information Expert + Creator ===\n";
    ProductSpec apple("Яблоко", 50.0);
    ProductSpec milk("Молоко", 80.0);
    Sale sale;
    sale.addItem(apple, 3);
    sale.addItem(milk, 2);
    sale.print();

    cout << "\n=== 3. Controller ===\n";
    SaleController ctrl;
    ctrl.addProduct("Хлеб", 40.0);
    ctrl.addProduct("Масло", 120.0);
    ctrl.startSale();
    ctrl.enterItem("Хлеб", 2);
    ctrl.enterItem("Масло", 1);
    ctrl.endSale();

    cout << "\n=== 4+5. Low Coupling + High Cohesion ===\n";
    Logger logger;
    EventBus bus;
    bus.subscribe("sale_complete", [&](const string& data) {
        logger.log("Продажа завершена: " + data);
    });
    bus.publish("sale_complete", "total=200");

    cout << "\n=== 6. Polymorphism ===\n";
    vector<IPayment*> payments = {
        new CashPayment(), new CardPayment(), new CryptoPayment()
    };
    for (auto* p : payments) p->pay(500.0);
    for (auto* p : payments) delete p;

    cout << "\n=== 7+8. Pure Fabrication + Indirection ===\n";
    Database db;
    PersistenceStorage storage(db);
    int id = storage.saveSale(200.0);
    cout << "[Storage] Загружено: " << storage.loadSale(id) << "\n";

    cout << "\n=== 9. Protected Variations ===\n";
    RusTax rusTax;
    EUTax  euTax;
    SaleWithTax s1(1000.0, &rusTax);
    cout << "Итого с НДС: " << s1.getFinalAmount() << "\n";
    SaleWithTax s2(1000.0, &euTax);
    cout << "Итого с VAT: " << s2.getFinalAmount() << "\n";

    return 0;
}
