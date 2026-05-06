# Structural Patterns (C++)

Структурные паттерны описывают способы **компоновки классов и объектов** для получения новых структур и функциональности.

---

## Adapter (Адаптер)

**Задача:** несовместимые интерфейсы — нужно соединить два класса, не меняя их.  
**Аналогия:** переходник розетки.

```cpp
// Существующий класс с несовместимым интерфейсом
class OldLogger {
public:
    void writeLog(const char* msg) {
        cout << "[OLD] " << msg << "\n";
    }
};

// Целевой интерфейс
class ILogger {
public:
    virtual void log(const string& msg) = 0;
    virtual ~ILogger() {}
};

// Адаптер оборачивает старый класс под новый интерфейс
class LoggerAdapter : public ILogger {
    OldLogger old;
public:
    void log(const string& msg) override {
        old.writeLog(msg.c_str());
    }
};

// Клиент работает только с ILogger
void clientCode(ILogger& logger) {
    logger.log("Привет из клиента");
}
```

**Плюсы:** разделяет интерфейс и реализацию, принцип единственной ответственности.  
**Минусы:** увеличивает общую сложность кода.

---

## Decorator (Декоратор)

**Задача:** динамически добавлять объекту новое поведение, не меняя его класс.  
**Аналогия:** кофе + молоко + сахар — каждый добавляет к базовому объекту что-то своё.

```cpp
class IText {
public:
    virtual string render() = 0;
    virtual ~IText() {}
};

class PlainText : public IText {
    string text;
public:
    PlainText(const string& t) : text(t) {}
    string render() override { return text; }
};

// Базовый декоратор
class TextDecorator : public IText {
protected:
    IText* wrapped;
public:
    TextDecorator(IText* t) : wrapped(t) {}
};

// Конкретные декораторы
class BoldDecorator : public TextDecorator {
public:
    BoldDecorator(IText* t) : TextDecorator(t) {}
    string render() override { return "<b>" + wrapped->render() + "</b>"; }
};

class ItalicDecorator : public TextDecorator {
public:
    ItalicDecorator(IText* t) : TextDecorator(t) {}
    string render() override { return "<i>" + wrapped->render() + "</i>"; }
};

// Использование — цепочка декораторов
IText* text = new ItalicDecorator(new BoldDecorator(new PlainText("Hello")));
cout << text->render(); // <i><b>Hello</b></i>
```

**Плюсы:** гибкое расширение без наследования; комбинируются в любом порядке.  
**Минусы:** много мелких объектов; сложно удалить конкретный декоратор.

---

## Facade (Фасад)

**Задача:** скрыть сложность подсистемы за единым простым интерфейсом.  
**Аналогия:** пульт телевизора — не нужно знать как работают внутренние платы.

```cpp
class CPU    { public: void start()  { cout << "CPU запущен\n";  } };
class Memory { public: void load()   { cout << "RAM загружена\n"; } };
class HDD    { public: void read()   { cout << "HDD читает\n";   } };

// Фасад — единая точка входа
class ComputerFacade {
    CPU    cpu;
    Memory memory;
    HDD    hdd;
public:
    void powerOn() {
        cpu.start();
        memory.load();
        hdd.read();
        cout << "Компьютер готов!\n";
    }
};

// Клиент не знает о CPU, Memory, HDD
ComputerFacade pc;
pc.powerOn();
```

**Плюсы:** изолирует клиентов от компонентов подсистемы.  
**Минусы:** фасад рискует стать «классом-богом».

---

## Proxy (Заместитель)

**Задача:** контролировать доступ к объекту — логирование, кэш, ленивая инициализация, защита.

```cpp
class IImage {
public:
    virtual void display() = 0;
    virtual ~IImage() {}
};

class RealImage : public IImage {
    string filename;
public:
    RealImage(const string& f) : filename(f) {
        cout << "Загрузка: " << filename << "\n"; // дорогая операция
    }
    void display() override { cout << "Показ: " << filename << "\n"; }
};

// Прокси — загружает реальный объект только когда нужно
class ImageProxy : public IImage {
    string filename;
    RealImage* real = nullptr;
public:
    ImageProxy(const string& f) : filename(f) {}
    void display() override {
        if (!real) real = new RealImage(filename); // ленивая инициализация
        real->display();
    }
    ~ImageProxy() { delete real; }
};

ImageProxy img("photo.jpg");
img.display(); // здесь произойдёт загрузка
img.display(); // повторно — загрузки нет
```

**Плюсы:** контроль доступа; ленивая инициализация; логирование.  
**Минусы:** усложняет код; возможна задержка первого ответа.

---

## Composite (Компоновщик)

**Задача:** обращаться с группой объектов так же, как с одиночным объектом. Дерево файлов/папок.

```cpp
class IComponent {
public:
    virtual void show(int depth = 0) = 0;
    virtual ~IComponent() {}
};

class File : public IComponent {
    string name;
public:
    File(const string& n) : name(n) {}
    void show(int depth = 0) override {
        cout << string(depth * 2, ' ') << "📄 " << name << "\n";
    }
};

class Directory : public IComponent {
    string name;
    vector<IComponent*> children;
public:
    Directory(const string& n) : name(n) {}
    void add(IComponent* c) { children.push_back(c); }
    void show(int depth = 0) override {
        cout << string(depth * 2, ' ') << "📁 " << name << "\n";
        for (auto* c : children) c->show(depth + 1);
    }
};

Directory root("root");
root.add(new File("README.md"));
Directory* src = new Directory("src");
src->add(new File("main.cpp"));
src->add(new File("util.cpp"));
root.add(src);
root.show();
```

**Плюсы:** единообразная работа с деревьями объектов.  
**Минусы:** сложно ограничить компоненты дерева по типу.

---

## Bridge (Мост)

**Задача:** отделить абстракцию от реализации — оба могут изменяться независимо.

```cpp
// Реализация
class IRenderer {
public:
    virtual void render(const string& shape) = 0;
    virtual ~IRenderer() {}
};

class VectorRenderer : public IRenderer {
public:
    void render(const string& shape) override {
        cout << "Векторный рендер: " << shape << "\n";
    }
};

class RasterRenderer : public IRenderer {
public:
    void render(const string& shape) override {
        cout << "Растровый рендер: " << shape << "\n";
    }
};

// Абстракция
class Shape {
protected:
    IRenderer* renderer;
public:
    Shape(IRenderer* r) : renderer(r) {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Circle(IRenderer* r) : Shape(r) {}
    void draw() override { renderer->render("Circle"); }
};

class Square : public Shape {
public:
    Square(IRenderer* r) : Shape(r) {}
    void draw() override { renderer->render("Square"); }
};

VectorRenderer vr;
Circle c(&vr);
c.draw(); // Векторный рендер: Circle
```

**Плюсы:** абстракция и реализация меняются независимо.  
**Минусы:** усложняет код при простых иерархиях.

---

## Flyweight (Приспособленец)

**Задача:** экономия памяти при огромном количестве похожих объектов. Делит объекты на **внутреннее состояние** (общее, неизменяемое) и **внешнее** (уникальное).

```cpp
// Внутреннее состояние — разделяется
struct TreeType {
    string name, color, texture;
    void draw(int x, int y) {
        cout << name << " [" << color << "] на (" << x << "," << y << ")\n";
    }
};

// Фабрика приспособленцев
class TreeFactory {
    map<string, TreeType*> types;
public:
    TreeType* get(const string& name, const string& color, const string& texture) {
        string key = name + color + texture;
        if (!types.count(key))
            types[key] = new TreeType{name, color, texture};
        return types[key];
    }
};

// Внешнее состояние — уникально для каждого объекта
struct Tree {
    int x, y;
    TreeType* type;
    void draw() { type->draw(x, y); }
};
```

**Плюсы:** резко снижает потребление памяти при массовом создании объектов.  
**Минусы:** сложнее читать код; нельзя хранить внешнее состояние внутри.
