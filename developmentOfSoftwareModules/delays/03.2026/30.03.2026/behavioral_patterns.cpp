#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// ══════════════════════════════════════════════════
//  1. INTERPRETER — калькулятор выражений
// ══════════════════════════════════════════════════
namespace Interpreter {
    class Expr { public: virtual int eval() = 0; virtual ~Expr(){} };
    class Num : public Expr {
        int val;
    public:
        Num(int v) : val(v) {}
        int eval() override { return val; }
    };
    class Add : public Expr {
        Expr *l, *r;
    public:
        Add(Expr* l, Expr* r) : l(l), r(r) {}
        int eval() override { return l->eval() + r->eval(); }
        ~Add() { delete l; delete r; }
    };
    class Mul : public Expr {
        Expr *l, *r;
    public:
        Mul(Expr* l, Expr* r) : l(l), r(r) {}
        int eval() override { return l->eval() * r->eval(); }
        ~Mul() { delete l; delete r; }
    };
    void demo() {
        cout << "\n=== Interpreter ===\n";
        Expr* e = new Mul(new Add(new Num(2), new Num(3)), new Num(4));
        cout << "(2+3)*4 = " << e->eval() << "\n";
        delete e;
    }
}

// ══════════════════════════════════════════════════
//  2. ITERATOR — перебор коллекции
// ══════════════════════════════════════════════════
namespace IteratorPattern {
    class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual int  next()    = 0;
        virtual ~Iterator() {}
    };
    class VecIter : public Iterator {
        vector<int>& data;
        size_t idx = 0;
    public:
        VecIter(vector<int>& d) : data(d) {}
        bool hasNext() override { return idx < data.size(); }
        int  next()    override { return data[idx++]; }
    };
    void demo() {
        cout << "\n=== Iterator ===\n";
        vector<int> v = {10, 20, 30, 40};
        VecIter it(v);
        cout << "Элементы: ";
        while (it.hasNext()) cout << it.next() << " ";
        cout << "\n";
    }
}

// ══════════════════════════════════════════════════
//  3. COMMAND — управление умным домом + undo
// ══════════════════════════════════════════════════
namespace CommandPattern {
    class Command {
    public:
        virtual void execute() = 0;
        virtual void undo()    = 0;
        virtual ~Command() {}
    };
    class Light {
        bool on = false;
    public:
        void turnOn()  { on = true;  cout << "  Свет включён\n"; }
        void turnOff() { on = false; cout << "  Свет выключен\n"; }
    };
    class LightOnCmd : public Command {
        Light& light;
    public:
        LightOnCmd(Light& l) : light(l) {}
        void execute() override { light.turnOn(); }
        void undo()    override { light.turnOff(); }
    };
    class Remote {
        stack<Command*> history;
    public:
        void press(Command* cmd) { cmd->execute(); history.push(cmd); }
        void undoLast() {
            if (!history.empty()) {
                history.top()->undo();
                history.pop();
            }
        }
    };
    void demo() {
        cout << "\n=== Command ===\n";
        Light light;
        LightOnCmd cmd(light);
        Remote remote;
        remote.press(&cmd);
        remote.undoLast();
    }
}

// ══════════════════════════════════════════════════
//  4. OBSERVER — новостная лента
// ══════════════════════════════════════════════════
namespace ObserverPattern {
    class Observer {
    public:
        virtual void update(const string& msg) = 0;
        virtual ~Observer() {}
    };
    class Subject {
        vector<Observer*> subs;
    public:
        void attach(Observer* o) { subs.push_back(o); }
        void detach(Observer* o) {
            auto it = std::find(subs.begin(), subs.end(), o);
            if (it != subs.end()) subs.erase(it);
        }
        void notify(const string& msg) {
            for (auto* o : subs) o->update(msg);
        }
    };
    class User : public Observer {
        string name;
    public:
        User(const string& n) : name(n) {}
        void update(const string& msg) override {
            cout << "  [" << name << "] получил: " << msg << "\n";
        }
    };
    void demo() {
        cout << "\n=== Observer ===\n";
        Subject news;
        User alice("Alice"), bob("Bob");
        news.attach(&alice);
        news.attach(&bob);
        news.notify("Вышла новая версия Qt!");
        news.detach(&bob);
        news.notify("Ещё одна новость");
    }
}

// ══════════════════════════════════════════════════
//  5. VISITOR — обход фигур
// ══════════════════════════════════════════════════
namespace VisitorPattern {
    class Circle; class Rect;
    class Visitor {
    public:
        virtual void visit(Circle& c) = 0;
        virtual void visit(Rect& r)   = 0;
        virtual ~Visitor() {}
    };
    class Shape {
    public:
        virtual void accept(Visitor& v) = 0;
        virtual ~Shape() {}
    };
    class Circle : public Shape {
    public:
        double radius;
        Circle(double r) : radius(r) {}
        void accept(Visitor& v) override { v.visit(*this); }
    };
    class Rect : public Shape {
    public:
        double w, h;
        Rect(double w, double h) : w(w), h(h) {}
        void accept(Visitor& v) override { v.visit(*this); }
    };
    class AreaVisitor : public Visitor {
    public:
        void visit(Circle& c) override {
            cout << "  Площадь круга: " << 3.14159 * c.radius * c.radius << "\n";
        }
        void visit(Rect& r) override {
            cout << "  Площадь прямоугольника: " << r.w * r.h << "\n";
        }
    };
    void demo() {
        cout << "\n=== Visitor ===\n";
        vector<Shape*> shapes = { new Circle(5), new Rect(4, 6) };
        AreaVisitor av;
        for (auto* s : shapes) s->accept(av);
        for (auto* s : shapes) delete s;
    }
}

// ══════════════════════════════════════════════════
//  6. MEDIATOR — чат
// ══════════════════════════════════════════════════
namespace MediatorPattern {
    class Mediator;
    class Colleague {
    protected:
        Mediator* med;
        string name;
    public:
        Colleague(const string& n) : name(n), med(nullptr) {}
        void setMediator(Mediator* m) { med = m; }
        const string& getName() const { return name; }
        virtual void send(const string& msg);
        virtual void receive(const string& from, const string& msg) {
            cout << "  [" << name << "] от " << from << ": " << msg << "\n";
        }
    };
    class Mediator {
        vector<Colleague*> cols;
    public:
        void add(Colleague* c) { c->setMediator(this); cols.push_back(c); }
        void relay(Colleague* sender, const string& msg) {
            for (auto* c : cols)
                if (c != sender) c->receive(sender->getName(), msg);
        }
    };
    void Colleague::send(const string& msg) {
        cout << "  [" << name << "] отправляет: " << msg << "\n";
        if (med) med->relay(this, msg);
    }
    void demo() {
        cout << "\n=== Mediator ===\n";
        Mediator chat;
        Colleague alice("Alice"), bob("Bob"), charlie("Charlie");
        chat.add(&alice); chat.add(&bob); chat.add(&charlie);
        alice.send("Привет всем!");
    }
}

// ══════════════════════════════════════════════════
//  7. STATE — светофор
// ══════════════════════════════════════════════════
namespace StatePattern {
    class Context;
    class State {
    public:
        virtual void handle(Context& ctx) = 0;
        virtual string name() = 0;
        virtual ~State() {}
    };
    class Context {
        State* state;
    public:
        Context(State* s) : state(s) {}
        void setState(State* s) { delete state; state = s; }
        void request() {
            cout << "  Состояние: " << state->name() << " → ";
            state->handle(*this);
        }
        ~Context() { delete state; }
    };
    class GreenState; class YellowState; class RedState;
    class GreenState : public State {
    public:
        void handle(Context& ctx) override;
        string name() override { return "GREEN"; }
    };
    class YellowState : public State {
    public:
        void handle(Context& ctx) override;
        string name() override { return "YELLOW"; }
    };
    class RedState : public State {
    public:
        void handle(Context& ctx) override;
        string name() override { return "RED"; }
    };
    void GreenState::handle(Context& ctx)  { cout << "Едем!\n";     ctx.setState(new YellowState()); }
    void YellowState::handle(Context& ctx) { cout << "Внимание!\n"; ctx.setState(new RedState()); }
    void RedState::handle(Context& ctx)    { cout << "Стоп!\n";     ctx.setState(new GreenState()); }
    void demo() {
        cout << "\n=== State ===\n";
        Context light(new GreenState());
        light.request();
        light.request();
        light.request();
        light.request();
    }
}

// ══════════════════════════════════════════════════
//  8. STRATEGY — сортировка данных
// ══════════════════════════════════════════════════
namespace StrategyPattern {
    class SortStrategy {
    public:
        virtual void sort(vector<int>& data) = 0;
        virtual ~SortStrategy() {}
    };
    class BubbleSort : public SortStrategy {
    public:
        void sort(vector<int>& d) override {
            for (size_t i = 0; i < d.size(); i++)
                for (size_t j = 0; j < d.size()-i-1; j++)
                    if (d[j] > d[j+1]) swap(d[j], d[j+1]);
            cout << "  Пузырьком: ";
        }
    };
    class QuickSort : public SortStrategy {
    public:
        void sort(vector<int>& d) override {
            std::sort(d.begin(), d.end());
            cout << "  Быстрая:   ";
        }
    };
    class Sorter {
        SortStrategy* strat;
    public:
        Sorter(SortStrategy* s) : strat(s) {}
        void setStrategy(SortStrategy* s) { strat = s; }
        void sort(vector<int> data) {
            strat->sort(data);
            for (int x : data) cout << x << " ";
            cout << "\n";
        }
    };
    void demo() {
        cout << "\n=== Strategy ===\n";
        vector<int> data = {5, 2, 8, 1, 9};
        BubbleSort bs; QuickSort qs;
        Sorter sorter(&bs);
        sorter.sort(data);
        sorter.setStrategy(&qs);
        sorter.sort(data);
    }
}

// ══════════════════════════════════════════════════
//  9. MEMENTO — текстовый редактор с undo
// ══════════════════════════════════════════════════
namespace MementoPattern {
    class Memento {
        string state;
        friend class Editor;
        Memento(const string& s) : state(s) {}
    };
    class Editor {
        string text;
    public:
        void write(const string& s) { text += s; }
        Memento* save()             { return new Memento(text); }
        void restore(Memento* m)    { text = m->state; }
        void show() { cout << "  Текст: \"" << text << "\"\n"; }
    };
    class History {
        stack<Memento*> history;
    public:
        void push(Memento* m) { history.push(m); }
        void undo(Editor& e) {
            if (!history.empty()) {
                e.restore(history.top());
                delete history.top();
                history.pop();
            }
        }
    };
    void demo() {
        cout << "\n=== Memento ===\n";
        Editor ed; History hist;
        ed.write("Hello"); hist.push(ed.save());
        ed.write(" World"); hist.push(ed.save());
        ed.write("!!!"); ed.show();
        hist.undo(ed); ed.show();
        hist.undo(ed); ed.show();
    }
}

// ══════════════════════════════════════════════════
//  10. CHAIN OF RESPONSIBILITY — обработка запросов
// ══════════════════════════════════════════════════
namespace ChainPattern {
    class Handler {
        Handler* next = nullptr;
    public:
        Handler* setNext(Handler* h) { next = h; return h; }
        virtual void handle(int level) {
            if (next) next->handle(level);
            else cout << "  Запрос " << level << " не обработан\n";
        }
        virtual ~Handler() {}
    };
    class LowHandler : public Handler {
    public:
        void handle(int level) override {
            if (level <= 1) cout << "  [Low] обработал уровень " << level << "\n";
            else            Handler::handle(level);
        }
    };
    class MidHandler : public Handler {
    public:
        void handle(int level) override {
            if (level <= 3) cout << "  [Mid] обработал уровень " << level << "\n";
            else            Handler::handle(level);
        }
    };
    class HighHandler : public Handler {
    public:
        void handle(int level) override {
            cout << "  [High] обработал уровень " << level << "\n";
        }
    };
    void demo() {
        cout << "\n=== Chain of Responsibility ===\n";
        LowHandler low; MidHandler mid; HighHandler high;
        low.setNext(&mid)->setNext(&high);
        for (int lvl : {1, 2, 5}) low.handle(lvl);
    }
}

// ══════════════════════════════════════════════════
//  11. TEMPLATE METHOD — обработка данных
// ══════════════════════════════════════════════════
namespace TemplateMethodPattern {
    class DataProcessor {
    public:
        void process() {
            readData();
            processData();
            writeData();
        }
    protected:
        virtual void readData()    = 0;
        virtual void processData() = 0;
        virtual void writeData() { cout << "  → Результат записан\n"; }
    };
    class CSVProcessor : public DataProcessor {
    protected:
        void readData()    override { cout << "  Читаем CSV\n"; }
        void processData() override { cout << "  Обрабатываем CSV\n"; }
    };
    class JSONProcessor : public DataProcessor {
    protected:
        void readData()    override { cout << "  Читаем JSON\n"; }
        void processData() override { cout << "  Обрабатываем JSON\n"; }
    };
    void demo() {
        cout << "\n=== Template Method ===\n";
        CSVProcessor  csv;
        JSONProcessor json;
        cout << "CSV:\n";  csv.process();
        cout << "JSON:\n"; json.process();
    }
}

int main() {
    Interpreter::demo();
    IteratorPattern::demo();
    CommandPattern::demo();
    ObserverPattern::demo();
    VisitorPattern::demo();
    MediatorPattern::demo();
    StatePattern::demo();
    StrategyPattern::demo();
    MementoPattern::demo();
    ChainPattern::demo();
    TemplateMethodPattern::demo();
    return 0;
}
