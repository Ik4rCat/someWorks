# Behavioral Patterns (C++)

Поведенческие паттерны описывают **взаимодействие и распределение ответственности** между объектами.

---

## Strategy (Стратегия)

**Задача:** инкапсулировать семейство алгоритмов и делать их взаимозаменяемыми во время выполнения.  
**Аналогия:** навигатор — можно выбрать маршрут пешком, на машине или велосипеде.

```cpp
class ISortStrategy {
public:
    virtual void sort(vector<int>& data) = 0;
    virtual ~ISortStrategy() {}
};

class BubbleSort : public ISortStrategy {
public:
    void sort(vector<int>& data) override {
        // пузырьковая сортировка
        for (int i = 0; i < data.size(); i++)
            for (int j = 0; j < data.size() - i - 1; j++)
                if (data[j] > data[j+1]) swap(data[j], data[j+1]);
        cout << "BubbleSort выполнен\n";
    }
};

class QuickSort : public ISortStrategy {
public:
    void sort(vector<int>& data) override {
        std::sort(data.begin(), data.end());
        cout << "QuickSort выполнен\n";
    }
};

class Sorter {
    ISortStrategy* strategy;
public:
    Sorter(ISortStrategy* s) : strategy(s) {}
    void setStrategy(ISortStrategy* s) { strategy = s; }
    void sort(vector<int>& data) { strategy->sort(data); }
};

vector<int> data = {5, 2, 8, 1};
Sorter sorter(new BubbleSort());
sorter.sort(data);
sorter.setStrategy(new QuickSort()); // меняем алгоритм на лету
sorter.sort(data);
```

**Плюсы:** замена алгоритмов без изменения контекста; устраняет условные операторы.  
**Минусы:** клиент должен знать о существующих стратегиях.

---

## Observer (Наблюдатель)

**Задача:** при изменении объекта автоматически уведомлять всех зависимых.  
**Аналогия:** подписка на новости — редакция публикует, все подписчики получают.

```cpp
class IObserver {
public:
    virtual void update(const string& event) = 0;
    virtual ~IObserver() {}
};

class EventManager {
    map<string, vector<IObserver*>> listeners;
public:
    void subscribe(const string& event, IObserver* obs) {
        listeners[event].push_back(obs);
    }
    void unsubscribe(const string& event, IObserver* obs) {
        auto& v = listeners[event];
        v.erase(remove(v.begin(), v.end(), obs), v.end());
    }
    void notify(const string& event) {
        for (auto* obs : listeners[event]) obs->update(event);
    }
};

class Logger : public IObserver {
public:
    void update(const string& event) override {
        cout << "[Logger] Событие: " << event << "\n";
    }
};

class EmailAlert : public IObserver {
public:
    void update(const string& event) override {
        cout << "[Email] Отправлено уведомление о: " << event << "\n";
    }
};

EventManager mgr;
Logger logger;
EmailAlert email;
mgr.subscribe("open", &logger);
mgr.subscribe("open", &email);
mgr.notify("open"); // оба получат уведомление
```

**Плюсы:** слабая связанность; динамическая подписка/отписка.  
**Минусы:** непредсказуемый порядок уведомлений; возможны утечки памяти.

---

## Command (Команда)

**Задача:** инкапсулировать запрос как объект — поддержка undo/redo, очереди, логирования.

```cpp
class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~ICommand() {}
};

class TextEditor {
    string text;
public:
    void write(const string& s) { text += s; }
    void erase(int n)           { if (n <= text.size()) text.erase(text.size() - n); }
    void show()                 { cout << "Текст: \"" << text << "\"\n"; }
};

class WriteCommand : public ICommand {
    TextEditor& editor;
    string text;
public:
    WriteCommand(TextEditor& e, const string& t) : editor(e), text(t) {}
    void execute() override { editor.write(text); }
    void undo()    override { editor.erase(text.size()); }
};

// История команд для undo
class CommandHistory {
    stack<ICommand*> history;
public:
    void execute(ICommand* cmd) { cmd->execute(); history.push(cmd); }
    void undo() {
        if (!history.empty()) {
            history.top()->undo();
            history.pop();
        }
    }
};

TextEditor editor;
CommandHistory history;
history.execute(new WriteCommand(editor, "Hello"));
history.execute(new WriteCommand(editor, " World"));
editor.show(); // "Hello World"
history.undo();
editor.show(); // "Hello"
```

**Плюсы:** undo/redo; очереди команд; логирование операций.  
**Минусы:** много мелких классов.

---

## State (Состояние)

**Задача:** объект меняет поведение при смене внутреннего состояния — как будто меняет класс.  
**Аналогия:** торговый автомат — разное поведение в зависимости от состояния (есть монеты / нет).

```cpp
class TrafficLight;

class IState {
public:
    virtual void handle(TrafficLight& light) = 0;
    virtual string name() = 0;
    virtual ~IState() {}
};

class TrafficLight {
    IState* state;
public:
    TrafficLight(IState* s) : state(s) {}
    void setState(IState* s) { state = s; }
    void request() { state->handle(*this); }
    string getState() { return state->name(); }
};

class GreenState;
class YellowState;
class RedState;

class GreenState : public IState {
public:
    void handle(TrafficLight& light) override;
    string name() override { return "GREEN"; }
};

class YellowState : public IState {
public:
    void handle(TrafficLight& light) override;
    string name() override { return "YELLOW"; }
};

class RedState : public IState {
public:
    void handle(TrafficLight& light) override {
        cout << "СТОП!\n";
        light.setState(new GreenState());
    }
    string name() override { return "RED"; }
};

void GreenState::handle(TrafficLight& light) {
    cout << "Едем!\n";
    light.setState(new YellowState());
}
void YellowState::handle(TrafficLight& light) {
    cout << "Внимание!\n";
    light.setState(new RedState());
}
```

**Плюсы:** устраняет громоздкие if/switch; каждое состояние в отдельном классе.  
**Минусы:** много классов при большом количестве состояний.

---

## Template Method (Шаблонный метод)

**Задача:** определить скелет алгоритма в базовом классе, делегируя отдельные шаги подклассам.

```cpp
class DataProcessor {
public:
    // Шаблонный метод — фиксирует порядок шагов
    void process() {
        readData();
        processData();
        writeData();
    }
protected:
    virtual void readData()    = 0;
    virtual void processData() = 0;
    virtual void writeData()   = 0;
};

class CSVProcessor : public DataProcessor {
protected:
    void readData()    override { cout << "Читаем CSV\n";       }
    void processData() override { cout << "Обрабатываем CSV\n"; }
    void writeData()   override { cout << "Пишем результат\n";  }
};

class JSONProcessor : public DataProcessor {
protected:
    void readData()    override { cout << "Читаем JSON\n";       }
    void processData() override { cout << "Обрабатываем JSON\n"; }
    void writeData()   override { cout << "Пишем результат\n";   }
};

CSVProcessor csv;
csv.process(); // порядок шагов всегда одинаков
```

**Плюсы:** устраняет дублирование; фиксирует структуру алгоритма.  
**Минусы:** жёсткий скелет алгоритма сложно менять.

---

## Iterator (Итератор)

**Задача:** последовательный перебор элементов коллекции без раскрытия её внутренней структуры.

```cpp
template <typename T>
class IIterator {
public:
    virtual bool hasNext() = 0;
    virtual T    next()    = 0;
    virtual ~IIterator() {}
};

template <typename T>
class NumberCollection {
    vector<T> items;
public:
    void add(T item) { items.push_back(item); }

    class Iterator : public IIterator<T> {
        const vector<T>& items;
        int index = 0;
    public:
        Iterator(const vector<T>& v) : items(v) {}
        bool hasNext() override { return index < items.size(); }
        T    next()    override { return items[index++]; }
    };

    Iterator* createIterator() { return new Iterator(items); }
};

NumberCollection<int> col;
col.add(1); col.add(2); col.add(3);
auto* it = col.createIterator();
while (it->hasNext()) cout << it->next() << " ";
```

**Плюсы:** единый интерфейс перебора разных коллекций.  
**Минусы:** избыточен если коллекция уже предоставляет доступ по индексу.

---

## Chain of Responsibility (Цепочка обязанностей)

**Задача:** передать запрос по цепочке обработчиков — каждый решает, обработать или передать дальше.  
**Аналогия:** служба поддержки: оператор → старший оператор → менеджер.

```cpp
class IHandler {
protected:
    IHandler* next = nullptr;
public:
    IHandler* setNext(IHandler* h) { next = h; return h; }
    virtual void handle(int level) {
        if (next) next->handle(level);
    }
    virtual ~IHandler() {}
};

class LowHandler : public IHandler {
public:
    void handle(int level) override {
        if (level <= 1) cout << "LowHandler обработал уровень " << level << "\n";
        else            IHandler::handle(level);
    }
};

class MidHandler : public IHandler {
public:
    void handle(int level) override {
        if (level <= 3) cout << "MidHandler обработал уровень " << level << "\n";
        else            IHandler::handle(level);
    }
};

class HighHandler : public IHandler {
public:
    void handle(int level) override {
        cout << "HighHandler обработал уровень " << level << "\n";
    }
};

LowHandler  low;
MidHandler  mid;
HighHandler high;
low.setNext(&mid)->setNext(&high);

low.handle(1); // LowHandler
low.handle(2); // MidHandler
low.handle(5); // HighHandler
```

**Плюсы:** слабая связанность; гибкое изменение цепочки.  
**Минусы:** запрос может остаться необработанным.

---

## Mediator (Посредник)

**Задача:** централизовать взаимодействие объектов — вместо прямых связей все общаются через посредника.  
**Аналогия:** авиадиспетчер — самолёты не общаются напрямую, только через диспетчера.

```cpp
class IMediator;

class Component {
protected:
    IMediator* mediator;
    string name;
public:
    Component(const string& n) : name(n), mediator(nullptr) {}
    void setMediator(IMediator* m) { mediator = m; }
    virtual void send(const string& msg);
    virtual void receive(const string& msg) {
        cout << name << " получил: " << msg << "\n";
    }
};

class IMediator {
public:
    virtual void notify(Component* sender, const string& msg) = 0;
    virtual ~IMediator() {}
};

class ChatMediator : public IMediator {
    vector<Component*> components;
public:
    void addComponent(Component* c) {
        c->setMediator(this);
        components.push_back(c);
    }
    void notify(Component* sender, const string& msg) override {
        for (auto* c : components)
            if (c != sender) c->receive(msg);
    }
};

void Component::send(const string& msg) {
    cout << name << " отправил: " << msg << "\n";
    if (mediator) mediator->notify(this, msg);
}
```

**Плюсы:** устраняет прямые связи; централизованное управление взаимодействием.  
**Минусы:** посредник может разрастись в «класс-бог».

---

## Memento (Хранитель)

**Задача:** сохранять и восстанавливать внутреннее состояние объекта не нарушая инкапсуляцию (undo).

```cpp
// Снимок состояния
class Memento {
    string state;
public:
    Memento(const string& s) : state(s) {}
    string getState() const { return state; }
};

// Объект, состояние которого сохраняем
class Editor {
    string text;
public:
    void write(const string& t) { text += t; }
    Memento save()              { return Memento(text); }
    void restore(const Memento& m) { text = m.getState(); }
    void show() { cout << "Текст: " << text << "\n"; }
};

// Хранилище снимков
class History {
    stack<Memento> history;
public:
    void push(const Memento& m) { history.push(m); }
    Memento pop() { auto m = history.top(); history.pop(); return m; }
};

Editor editor;
History history;

editor.write("Hello");
history.push(editor.save());
editor.write(" World");
history.push(editor.save());
editor.write("!!!");
editor.show(); // Hello World!!!
editor.restore(history.pop());
editor.show(); // Hello World
editor.restore(history.pop());
editor.show(); // Hello
```

**Плюсы:** undo без нарушения инкапсуляции.  
**Минусы:** много памяти при частом сохранении.
