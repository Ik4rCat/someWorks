# Лабораторная работа III — Коллекции, интерфейсы и класс Object

ArrayList и LinkedList **не являются шаблонами**. Работа с разными типами (int, double, std::string) обеспечивается через базовый класс **Object** и шаблон-обёртку **ObjectT\<T\>**. Коллекции хранят **Object\*** и реализуют интерфейсы **ICollection** и **IIterable** (без параметра типа). Шаблонный **List\<T\>** — отдельная типизированная коллекция без интерфейсов.

---

## Object.h

Базовый полиморфный тип: любой элемент коллекции представлен указателем на **Object**. Конкретные значения оборачиваются в **ObjectT\<T\>**.

**Блок 1 — базовый класс Object**

Абстрактный класс с виртуальными методами: вывод в поток, клонирование, виртуальный деструктор для корректного удаления наследников через указатель на базовый класс.

```cpp
#pragma once

#include <iostream>

class Object {
public:
    virtual void print(std::ostream& out) const = 0;
    virtual Object* clone() const = 0;
    virtual ~Object() {}
};
```

**Блок 2 — обёртка ObjectT\<T\>**

Шаблонный наследник: хранит значение типа `T`, реализует `print` (вывод в поток), `clone()` (новая копия в куче), `getValue()` для доступа к значению. Элементы в коллекции создаются как `new ObjectT<int>(10)`, `new ObjectT<std::string>("hello")` и т.д.

```cpp
template<typename T>
class ObjectT : public Object {
private:
    T value;

public:
    explicit ObjectT(const T& v) : value(v) {}

    void print(std::ostream& out) const override {
        out << value;
    }

    Object* clone() const override {
        return new ObjectT<T>(value);
    }

    T getValue() const {
        return value;
    }
};
```

---

## Iterator.h

Интерфейс обхода коллекции: проверка наличия следующего элемента, переход к следующему, возврат **Object\*** (без передачи владения), сброс к началу.

**Блок 1**

```cpp
#pragma once

class Object;

class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual Object* next() = 0;
    virtual void reset() = 0;
    virtual ~Iterator() {}
};
```

Итератор возвращает указатели на элементы; вызывающий код не владеет ими и не удаляет. Сам итератор создаётся через `getIterator()` и после использования удаляется вызывающим кодом через `delete`.

---

## ICollection.h

Интерфейс коллекции: добавление по указателю (коллекция забирает владение), удаление по индексу, размер, очистка, проверка на пустоту.

**Блок 1**

```cpp
#pragma once

class Object;

class ICollection {
public:
    virtual void add(Object* value) = 0;
    virtual void removeAt(int index) = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~ICollection() {}
};
```

При `add(Object*)` коллекция принимает владение и удаляет объект в `removeAt`, `clear` или в своём деструкторе.

---

## IIterable.h

Интерфейс «по объекту можно пройтись»: единственный метод возвращает итератор. Итератор нужно удалить через `delete` после использования.

**Блок 1**

```cpp
#pragma once

class Iterator;

class IIterable {
public:
    virtual Iterator* getIterator() = 0;
    virtual ~IIterable() {}
};
```

---

## ArrayList.h

Нешаблонный класс: динамический массив указателей **Object\***, реализует **ICollection** и **IIterable**.

**Блок 1 — поля и внутренний итератор**

Массив `Object** data`, ёмкость и количество. Внутренний класс **ArrayListIterator** реализует **Iterator**: обходит массив по индексу, `next()` возвращает `getAt(current++)`.

```cpp
#pragma once

#include "ICollection.h"
#include "IIterable.h"
#include "Iterator.h"
#include "Object.h"

class ArrayList : public ICollection, public IIterable {
private:
    Object** data;
    int capacity;
    int count;

    class ArrayListIterator : public Iterator {
    private:
        ArrayList* list;
        int current;

    public:
        ArrayListIterator(ArrayList* l) : list(l), current(0) {}
        bool hasNext() const override { return current < list->size(); }
        Object* next() override { return list->getAt(current++); }
        void reset() override { current = 0; }
    };
```

**Блок 2 — конструкторы, деструктор, add, removeAt**

Конструкторы выделяют массив указателей. Деструктор вызывает `clear()` (удаляет каждый Object\*), затем освобождает массив. При переполнении массив расширяется (удвоение). В `removeAt` удаляется объект по индексу и элементы сдвигаются.

```cpp
public:
    ArrayList() : data(nullptr), capacity(10), count(0) {
        data = new Object*[capacity];
    }

    explicit ArrayList(int initialCapacity) : data(nullptr), capacity(initialCapacity), count(0) {
        data = new Object*[capacity];
    }

    ~ArrayList() {
        clear();
        delete[] data;
    }

    void add(Object* value) override {
        if (count >= capacity) {
            int newCapacity = capacity * 2;
            Object** newData = new Object*[newCapacity];
            for (int i = 0; i < count; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[count++] = value;
    }

    void removeAt(int index) override {
        if (index < 0 || index >= count) return;
        delete data[index];
        for (int i = index; i < count - 1; i++) data[i] = data[i + 1];
        count--;
    }
```

**Блок 3 — size, clear, isEmpty, getIterator, getAt**

`clear()` удаляет каждый хранимый Object\*. `getIterator()` создаёт новый итератор в куче — вызывающий код должен выполнить `delete` после использования.

```cpp
    int size() const override { return count; }
    void clear() override {
        for (int i = 0; i < count; i++) delete data[i];
        count = 0;
    }
    bool isEmpty() const override { return count == 0; }

    Iterator* getIterator() override {
        return new ArrayListIterator(this);
    }

    Object* getAt(int index) const {
        if (index < 0 || index >= count) return nullptr;
        return data[index];
    }
};
```

---

## LinkedList.h

Нешаблонный класс: односвязный список узлов, каждый узел хранит **Object\***. Реализует **ICollection** и **IIterable**.

**Блок 1 — узел и итератор**

Структура **Node**: указатель на Object и на следующий узел. **LinkedListIteratorImpl** обходит список по ссылкам `next`, в `reset()` возвращает текущий указатель к голове списка.

```cpp
#pragma once

#include "ICollection.h"
#include "IIterable.h"
#include "Iterator.h"
#include "Object.h"

struct Node {
    Object* value;
    Node* next;
    Node(Object* v, Node* n = nullptr) : value(v), next(n) {}
};

class LinkedList : public ICollection, public IIterable {
private:
    Node* head;
    int count;

    class LinkedListIteratorImpl : public Iterator {
    private:
        Node* head;
        Node* current;

    public:
        explicit LinkedListIteratorImpl(Node* h) : head(h), current(h) {}
        bool hasNext() const override { return current != nullptr; }
        Object* next() override {
            Object* val = current->value;
            current = current->next;
            return val;
        }
        void reset() override { current = head; }
    };
```

**Блок 2 — конструктор, деструктор, add, removeAt**

Деструктор вызывает `clear()`. `add` добавляет новый узел в конец. В `removeAt` при удалении узла вызывается `delete` для хранимого Object\* и для самого узла.

```cpp
public:
    LinkedList() : head(nullptr), count(0) {}

    ~LinkedList() {
        clear();
    }

    void add(Object* value) override {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    void removeAt(int index) override {
        if (index < 0 || index >= count) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp->value;
            delete temp;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) temp = temp->next;
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete->value;
            delete toDelete;
        }
        count--;
    }
```

**Блок 3 — clear, size, isEmpty, getIterator**

`clear()` в цикле удаляет каждый узел и хранимый в нём Object\*.

```cpp
    int size() const override { return count; }

    void clear() override {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp->value;
            delete temp;
        }
        count = 0;
    }

    bool isEmpty() const override { return count == 0; }

    Iterator* getIterator() override {
        return new LinkedListIteratorImpl(head);
    }
};
```

---

## List.h

Шаблонный класс: динамический массив элементов типа **T**. Не реализует ICollection и IIterable; типы задаются на этапе компиляции, без Object.

**Блок 1 — поля, конструктор, деструктор**

```cpp
#pragma once

template<typename T>
class List {
private:
    T* data;
    int capacity;
    int count;

public:
    List() : data(nullptr), capacity(8), count(0) {
        data = new T[capacity];
    }

    ~List() {
        delete[] data;
    }
```

**Блок 2 — add, removeAt, size, clear, isEmpty, getAt**

При переполнении ёмкость увеличивается (capacity + capacity/2). Элементы хранятся по значению, не через указатели на Object.

```cpp
    void add(T value) {
        if (count >= capacity) {
            capacity = capacity + capacity / 2;
            T* newData = new T[capacity];
            for (int i = 0; i < count; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[count++] = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= count) return;
        for (int i = index; i < count - 1; i++) data[i] = data[i + 1];
        count--;
    }

    int size() const { return count; }
    void clear() { count = 0; }
    bool isEmpty() const { return count == 0; }

    T getAt(int index) const {
        if (index < 0 || index >= count) return T();
        return data[index];
    }
};
```

---

## Print.h

Вывод коллекций в консоль. Для коллекций на Object используется полиморфный вызов `obj->print(std::cout)`.

**Блок 1 — ArrayList и LinkedList**

Для ArrayList — обход по индексу, для каждого элемента вызов `getAt(i)->print(std::cout)`. Для LinkedList — получение итератора, цикл по `hasNext()/next()`, вывод через `next()->print(std::cout)`, затем `delete it`.

```cpp
#pragma once

#include "ArrayList.h"
#include "LinkedList.h"
#include "List.h"
#include "Iterator.h"
#include "IIterable.h"
#include "Object.h"
#include <iostream>

class Print {
public:
    static void print(ArrayList& list) {
        std::cout << "ArrayList [";
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) std::cout << ", ";
            list.getAt(i)->print(std::cout);
        }
        std::cout << "]" << std::endl;
    }

    static void print(LinkedList& list) {
        std::cout << "LinkedList [";
        Iterator* it = list.getIterator();
        bool first = true;
        while (it->hasNext()) {
            if (!first) std::cout << ", ";
            it->next()->print(std::cout);
            first = false;
        }
        std::cout << "]" << std::endl;
        delete it;
    }
```

**Блок 2 — List\<T\> и IIterable\***

Шаблонная перегрузка для **List\<T\>** — вывод по индексу через `getAt(i)`. Перегрузка для **IIterable\*** — полиморфный вывод любой коллекции, реализующей интерфейс: получаем итератор, обходим, выводим через `Object::print`, удаляем итератор.

```cpp
    template<typename T>
    static void print(List<T>& list) {
        std::cout << "List [";
        for (int i = 0; i < list.size(); i++) {
            if (i > 0) std::cout << ", ";
            std::cout << list.getAt(i);
        }
        std::cout << "]" << std::endl;
    }

    static void print(IIterable* iterable) {
        std::cout << "IIterable [";
        Iterator* it = iterable->getIterator();
        bool first = true;
        while (it->hasNext()) {
            if (!first) std::cout << ", ";
            it->next()->print(std::cout);
            first = false;
        }
        std::cout << "]" << std::endl;
        delete it;
    }
};
```

---

## LabIII.cpp

Демонстрация: заполнение коллекций через **ObjectT**, вывод, работа через интерфейсы.

**Блок 1 — ArrayList**

Создание ArrayList, добавление элементов как `new ObjectT<int>(...)`, вывод через `Print::print`, размер, ручной обход итератором с вызовом `next()->print(std::cout)`, удаление итератора.

```cpp
#include <iostream>
#include <string>
#include "Object.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "List.h"
#include "Print.h"

int main() {
    std::cout << "=== ArrayList (Object*) ===" << std::endl;
    ArrayList arrList;
    arrList.add(new ObjectT<int>(10));
    arrList.add(new ObjectT<int>(20));
    arrList.add(new ObjectT<int>(30));
    Print::print(arrList);
    std::cout << "Size: " << arrList.size() << std::endl;
    std::cout << "Iterator: ";
    Iterator* it1 = arrList.getIterator();
    while (it1->hasNext()) {
        it1->next()->print(std::cout);
        std::cout << " ";
    }
    std::cout << std::endl;
    delete it1;
```

**Блок 2 — LinkedList**

Аналогично: создание LinkedList, добавление через **ObjectT\<int\>**, вывод, размер, обход итератором, `delete it2`.

```cpp
    std::cout << "\n=== LinkedList (Object*) ===" << std::endl;
    LinkedList linkedList;
    linkedList.add(new ObjectT<int>(5));
    linkedList.add(new ObjectT<int>(15));
    linkedList.add(new ObjectT<int>(25));
    linkedList.add(new ObjectT<int>(35));
    Print::print(linkedList);
    std::cout << "Size: " << linkedList.size() << std::endl;
    std::cout << "Iterator: ";
    Iterator* it2 = linkedList.getIterator();
    while (it2->hasNext()) {
        it2->next()->print(std::cout);
        std::cout << " ";
    }
    std::cout << std::endl;
    delete it2;
```

**Блок 3 — List\<int\> и List\<double\>**

Шаблонный List без Object: элементы передаются по значению (`add(100)`, `add(1.5)`), вывод через шаблонную перегрузку `Print::print(List<T>&)`.

```cpp
    std::cout << "\n=== List<int> (template) ===" << std::endl;
    List<int> listInt;
    listInt.add(100);
    listInt.add(200);
    listInt.add(300);
    Print::print(listInt);
    std::cout << "Size: " << listInt.size() << std::endl;

    std::cout << "\n=== List<double> (template) ===" << std::endl;
    List<double> listDouble;
    listDouble.add(1.5);
    listDouble.add(2.5);
    listDouble.add(3.5);
    Print::print(listDouble);
```

**Блок 4 — смешанные типы в ArrayList и LinkedList**

В один ArrayList добавляются элементы разных типов: **ObjectT\<int\>**, **ObjectT\<double\>**, **ObjectT\<std::string\>**. Вывод идёт через полиморфный `print`. Аналогично LinkedList со строками.

```cpp
    std::cout << "\n=== ArrayList with different types (Object*) ===" << std::endl;
    ArrayList arrMixed;
    arrMixed.add(new ObjectT<int>(42));
    arrMixed.add(new ObjectT<double>(3.14));
    arrMixed.add(new ObjectT<std::string>("hello"));
    Print::print(arrMixed);

    std::cout << "\n=== LinkedList with std::string (Object*) ===" << std::endl;
    LinkedList linkedStr;
    linkedStr.add(new ObjectT<std::string>("world"));
    linkedStr.add(new ObjectT<std::string>("!"));
    Print::print(linkedStr);
```

**Блок 5 — полиморфизм через ICollection\* и IIterable\***

Указатель **ICollection\*** указывает на arrList; через него вызываются `isEmpty()`, `add`, `size()`, `removeAt`, `clear` — без знания конкретного класса. Затем указатель **IIterable\*** на тот же arrList передаётся в `Print::print(iterable)` для полиморфного вывода через итератор.

```cpp
    std::cout << "\n=== Interface demo (ICollection*, IIterable*) ===" << std::endl;
    ICollection* col = &arrList;
    std::cout << "ArrayList isEmpty: " << (col->isEmpty() ? "yes" : "no") << std::endl;
    col->add(new ObjectT<int>(40));
    std::cout << "After add, size: " << col->size() << std::endl;
    col->removeAt(0);
    std::cout << "After removeAt(0): ";
    Print::print(arrList);
    col->clear();
    std::cout << "After clear, isEmpty: " << (col->isEmpty() ? "yes" : "no") << std::endl;

    std::cout << "\n=== IIterable interface demo ===" << std::endl;
    arrList.add(new ObjectT<int>(10));
    arrList.add(new ObjectT<int>(20));
    IIterable* iterable = &arrList;
    Print::print(iterable);

    return 0;
}
```

---

## Вывод по работе

ArrayList и LinkedList **не шаблоны**; они хранят **Object\*** и реализуют **ICollection** и **IIterable**. Разные типы элементов обеспечиваются базовым классом **Object** и обёрткой **ObjectT\<T\>**: добавление в виде `new ObjectT<T>(value)`, при обходе и выводе — полиморфный вызов **Object::print**. Интерфейсы работают с любыми такими типами через единый тип Object\*. Шаблонный **List\<T\>** — альтернативная типизированная коллекция без Object.
