# Behavioral Patterns — Deep Dive

Поведенческие паттерны — проверенные решения для организации взаимодействия между объектами. 11 паттернов GoF делятся на три группы:

| Группа | Паттерны |
|---|---|
| **Управление алгоритмами** | Strategy, Template Method, Interpreter |
| **Взаимодействие объектов** | Observer, Mediator, Command, Chain of Responsibility |
| **Управление состоянием** | State, Memento, Iterator, Visitor |

---

## Interpreter (Интерпретатор)

Задаёт представление грамматики языка и определяет интерпретатор предложений этого языка.

**Когда применять:** грамматика проста, производительность не критична, нужна лёгкая расширяемость новыми правилами.  
**Осторожно:** при сложной грамматике лучше использовать генераторы парсеров (ANTLR, yacc).

**Структура:**
- `AbstractExpression` — объявляет `interpret(context)`
- `TerminalExpression` — терминальные символы (числа, переменные)
- `NonTerminalExpression` — рекурсивно вызывает интерпретацию дочерних узлов

```cpp
class Expr { public: virtual int eval() = 0; virtual ~Expr(){} };

class Num : public Expr {         // Терминал
    int val;
public:
    Num(int v) : val(v) {}
    int eval() override { return val; }
};

class Add : public Expr {         // Нетерминал
    Expr *l, *r;
public:
    Add(Expr *left, Expr *right) : l(left), r(right) {}
    int eval() override { return l->eval() + r->eval(); }
};

// new Add(new Num(5), new Num(10))->eval(); // → 15
```

---

## Iterator (Итератор)

Предоставляет последовательный доступ к элементам коллекции, не раскрывая её внутреннего представления.

**Структура:**
- `Aggregate` — создаёт итератор
- `Iterator` — интерфейс: `hasNext()`, `next()`, `reset()`
- `ConcreteIterator` — реализует обход конкретной структуры

```cpp
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
```

В C++ STL реализован через `begin()`/`end()`, в Python — через `__iter__`/`__next__`.

---

## Command (Команда)

Инкапсулирует запрос как объект. Позволяет ставить запросы в очередь, логировать и поддерживать undo/redo.

**Структура:**
- `Client` — создаёт `ConcreteCommand` и связывает с `Receiver`
- `Invoker` — хранит и вызывает `execute()`
- `Receiver` — выполняет реальную работу

**Сценарии:** undo/redo, очереди задач, макросы, транзакции.

```cpp
class Command {
public:
    virtual void execute() = 0;
    virtual void undo()    = 0;
    virtual ~Command() {}
};

class LightOn : public Command {
    bool& state;
public:
    LightOn(bool& s) : state(s) {}
    void execute() override { state = true;  cout << "Свет ON\n"; }
    void undo()    override { state = false; cout << "Свет OFF (Undo)\n"; }
};
```

---

## Observer (Наблюдатель / Publish-Subscribe)

Определяет зависимость «один ко многим»: при изменении издателя все подписчики автоматически уведомляются.

**Структура:**
- `Subject/Publisher` — хранит список наблюдателей, методы `subscribe()`, `unsubscribe()`, `notify()`
- `Observer/Subscriber` — интерфейс `update(event)`

```cpp
class Observer {
public:
    virtual void update(string msg) = 0;
    virtual ~Observer() {}
};

class Subject {
    vector<Observer*> subs;
public:
    void attach(Observer* o) { subs.push_back(o); }
    void notify(string msg)  {
        for (auto o : subs) o->update(msg);
    }
};

class User : public Observer {
public:
    void update(string msg) override {
        cout << "Получено: " << msg << "\n";
    }
};
```

**Delegation Event Model** — вариант в Java AWT/Swing: события делегируются через строго типизированные интерфейсы.

---

## Visitor (Посетитель)

Определяет новую операцию над элементами, не изменяя их классы. Реализует технику **double dispatch**.

**Применение:** обходы AST-деревьев компиляторов, сериализация, статический анализ кода.  
**Компромисс:** добавить новый тип элемента — нужно менять все Visitor-классы. Зато добавить новую операцию — только новый Visitor.

```cpp
class Visitor;

class Shape {
public:
    virtual void accept(Visitor& v) = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void accept(Visitor& v) override; // v.visit(*this)
};

class Visitor {
public:
    virtual void visit(Circle& c) = 0;
    virtual ~Visitor() {}
};

// Реализация double dispatch:
void Circle::accept(Visitor& v) { v.visit(*this); }
```

---

## Mediator (Посредник)

Инкапсулирует способ взаимодействия множества объектов. Исключает прямые ссылки между компонентами.

**Без посредника:** N компонентов → N×(N-1) связей («спагетти»-архитектура).  
**С посредником:** N компонентов → N связей.

**Примеры:** авиадиспетчер, контроллер GUI-форм, брокер сообщений (Kafka, RabbitMQ).

```cpp
class Mediator;

class Colleague {
protected:
    Mediator* med;
public:
    Colleague(Mediator* m) : med(m) {}
    virtual void send()                   = 0;
    virtual void receive(string msg)      = 0;
};

class Mediator {
public:
    virtual void sendMessage(string msg, Colleague* sender) = 0;
};
// Коллеги шлют сообщения только медиатору — он пересылает адресату.
```

---

## State (Состояние)

Позволяет объекту менять поведение при изменении внутреннего состояния — объект кажется изменившим класс.

**Ключевые отличия от Strategy:**
- State управляет жизненным циклом объекта, сами переходы между состояниями происходят изнутри
- Strategy — выбор алгоритма делает клиент снаружи

**Пример:** TCP-соединение (Listen → Established → Closed).

```cpp
class State;

class Context {
    State* state;
public:
    void setState(State* s) { state = s; }
    void request() { state->handle(this); }
};

class State {
public:
    virtual void handle(Context* c) = 0;
    virtual ~State() {}
};

class ConcreteState : public State {
public:
    void handle(Context* c) override {
        cout << "Обработка в состоянии Concrete\n";
        // c->setState(new AnotherState()); // переход
    }
};
```

---

## Strategy (Стратегия)

Определяет семейство алгоритмов, инкапсулирует каждый и делает их взаимозаменяемыми.

**Выбор алгоритма определяет клиент** (в отличие от State, где состояния сами управляют переходами).  
**Применение:** сортировка, валидация, платёжные шлюзы.

```cpp
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};

class FastSort : public Strategy {
public:
    void execute() override { cout << "Сортировка: Быстрая\n"; }
};

class SlowSort : public Strategy {
public:
    void execute() override { cout << "Сортировка: Пузырьком\n"; }
};

class Sorter {
    Strategy* strat;
public:
    Sorter(Strategy* s) : strat(s) {}
    void sort() { strat->execute(); }
};
```

---

## Memento (Хранитель)

Фиксирует внутреннее состояние объекта вне его, чтобы позднее можно было восстановить объект.

**Структура:**
- `Originator` — создаёт снимок (`save()`) и восстанавливается (`restore()`)
- `Memento` — хранит состояние, доступ только Originator через `friend`
- `Caretaker` — хранит историю снимков

**Применение:** undo в редакторах, чекпоинты в играх.

```cpp
class Memento {
    int state;
    friend class Originator;
    Memento(int s) : state(s) {}
};

class Originator {
    int state;
public:
    void set(int s) { state = s; }
    Memento* save()              { return new Memento(state); }
    void restore(Memento* m)     { state = m->state; }
};
```

---

## Chain of Responsibility (Цепочка обязанностей)

Передаёт запрос по цепочке обработчиков. Каждый решает — обработать или передать дальше.

**Плюсы:** слабая связанность, динамическая конфигурация цепочки.  
**Минус:** запрос может остаться необработанным.  
**Применение:** HTTP-middleware, фильтры событий, логирование.

```cpp
class Handler {
    Handler* next = nullptr;
public:
    void setNext(Handler* h) { next = h; }
    virtual void handle(int req) {
        if (next) next->handle(req);
    }
};

class ConcreteHandler : public Handler {
public:
    void handle(int req) override {
        if (req == 1) cout << "Обработано первым\n";
        else          Handler::handle(req); // передать дальше
    }
};
```

---

## Template Method (Шаблонный метод)

Определяет скелет алгоритма в базовом классе. Подклассы переопределяют отдельные шаги, не меняя структуру.

**Структура:**
- `AbstractClass` — объявляет `templateMethod()` и абстрактные шаги
- `Primitive Operations` — обязательные к реализации шаги
- `Hook Operations` — необязательные точки расширения с реализацией по умолчанию
- `ConcreteClass` — реализует шаги

```cpp
class Game {
public:
    void play() {      // шаблонный метод — скелет алгоритма
        init();
        startPlay();
        endPlay();
    }
protected:
    virtual void init()      = 0;  // обязательный шаг
    virtual void startPlay() = 0;  // обязательный шаг
    virtual void endPlay() {       // хук — реализация по умолчанию
        cout << "Игра окончена\n";
    }
};

class Chess : public Game {
    void init()      override { cout << "Расстановка фигур\n"; }
    void startPlay() override { cout << "Ход белых\n"; }
};
```

---

## Сравнение всех 11 паттернов

| Паттерн | Ключевая идея | Применение |
|---|---|---|
| Interpreter | Грамматика как объектная модель | DSL, регулярки, SQL |
| Iterator | Обход без раскрытия структуры | Коллекции, деревья |
| Command | Запрос как объект | Undo/redo, очереди |
| Observer | Уведомление подписчиков | Events, pub/sub |
| Visitor | Операции без изменения классов | AST, сериализация |
| Mediator | Централизованная координация | Чат, диспетчер |
| State | Поведение по состоянию | FSM, TCP, заказы |
| Strategy | Взаимозаменяемые алгоритмы | Сортировка, оплата |
| Memento | Снимок состояния | Undo, save/load |
| Chain of Resp. | Цепочка обработчиков | Middleware, фильтры |
| Template Method | Скелет алгоритма | Фреймворки, жизненные циклы |
