# Лаба II — Страна (`Country`)

В этой лабораторной работе реализуется класс `Country`, описывающий страну, с ручным управлением динамической памятью для строковых полей (имя страны и имя президента). Также демонстрируется работа с указателями на объект, указателями на методы-члены и динамическими объектами.

## Блок 1: Объявление класса (`Country.h`)

Класс хранит три поля:
- **`char* name`** — название страны;
- **`int citizens`** — количество граждан;
- **`char* president`** — фамилия/имя президента.

Реализованы конструкторы, деструктор, метод `show` и набор геттеров/сеттеров.

```cpp
#pragma once

class Country {
private:
    char* name;
    int citizens;
    char* president;

public:
    Country();
    Country(char* n, int c, char* p);
    Country(const Country& other);
    ~Country();

    void show() const;
    void setName(const char* n);
    void setCitizens(int c);
    void setPresident(const char* p);
    char* getName() const;
    int getCitizens() const;
    char* getPresident() const;
};
```

## Блок 2: Конструкторы и деструктор (`Country.cpp`)

Класс использует **сырые указатели `char*` и `new[]/delete[]`**, поэтому в конструкторах и деструкторе важно корректно управлять памятью.

- Конструктор по умолчанию инициализирует указатели `name` и `president` значением `nullptr`, а `citizens` — нулём, и выводит сообщение о вызове конструктора.
- Конструктор с параметрами принимает указатели на C‑строки, вручную считает длину каждой строки, выделяет динамический массив `char` нужного размера и копирует символы поэлементно.
- Конструктор копирования выполняет **глубокое копирование**: по тем же правилам копирует строки из другого объекта.
- Деструктор освобождает память, выделенную под `name` и `president`, с помощью `delete[]` и выводит сообщение о своём вызове.

```cpp
Country::Country() : name(nullptr), citizens(0), president(nullptr) {
    std::cout << "Default constructor called for object at " << this << std::endl;
}

Country::Country(char* n, int c, char* p)
    : name(nullptr), citizens(c), president(nullptr) {

    if (n) {
        int len = 0;
        while (n[len] != '\0') {
            ++len;
        }

        name = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            name[i] = n[i];
        }
    }

    if (p) {
        int len = 0;
        while (p[len] != '\0') {
            ++len;
        }

        president = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            president[i] = p[i];
        }
    }

    std::cout << "Parameterized constructor called for object at " << this << std::endl;
}

Country::Country(const Country& other)
    : name(nullptr), citizens(other.citizens), president(nullptr) {

    if (other.name) {
        int len = 0;
        while (other.name[len] != '\0') {
            ++len;
        }

        name = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            name[i] = other.name[i];
        }
    }

    if (other.president) {
        int len = 0;
        while (other.president[len] != '\0') {
            ++len;
        }

        president = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            president[i] = other.president[i];
        }
    }

    std::cout << "Copy constructor called for object at " << this << std::endl;
}

Country::~Country() {
    delete[] name;
    delete[] president;
    std::cout << "Destructor called for object at " << this << std::endl;
}
```

## Блок 3: Методы-компоненты (`Country.cpp`)

Метод `show` выводит текущие значения полей. Если указатель равен `nullptr`, на экран выводится строка `"null"`.  
Сеттеры для строк сначала освобождают старую память (`delete[]`), затем, если новый указатель не `nullptr`, заново выделяют буфер и копируют C‑строку. Сеттер для числа просто присваивает значение. Геттеры возвращают текущие значения полей.

```cpp
void Country::show() const {
    std::cout << "Country: name=" << (name ? name : "null")
              << ", citizens=" << citizens
              << ", president=" << (president ? president : "null")
              << std::endl;
}

void Country::setName(const char* n) {
    delete[] name;
    name = nullptr;

    if (n) {
        int len = 0;
        while (n[len] != '\0') {
            ++len;
        }

        name = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            name[i] = n[i];
        }
    }
}

void Country::setCitizens(int c) {
    citizens = c;
}

void Country::setPresident(const char* p) {
    delete[] president;
    president = nullptr;

    if (p) {
        int len = 0;
        while (p[len] != '\0') {
            ++len;
        }

        president = new char[len + 1];
        for (int i = 0; i <= len; ++i) {
            president[i] = p[i];
        }
    }
}
```

## Блок 4: Демо — объекты и указатель на объект (`LabII.cpp`)

В `main` создаются три объекта:
- `r1` — при помощи конструктора по умолчанию;
- `r2` — при помощи конструктора с параметрами (`char*` для имени и президента, `int` для количества граждан);
- `r3` — копия `r2`, создаётся конструктором копирования.

Затем создаётся указатель на объект `r2`, через который вызываются методы и изменяется число граждан.

```cpp
std::cout << "Creating object r1 with default constructor:" << std::endl;
Country r1;
r1.show();

std::cout << "\nCreating object r2 with parameterized constructor:" << std::endl;
Country r2((char*)"CountryA", 1000000, (char*)"President A");
r2.show();

std::cout << "\nCreating object r3 with copy constructor (copy of r2):" << std::endl;
Country r3(r2);
r3.show();

std::cout << "\nUsing pointer to object:" << std::endl;
Country* ptr = &r2;
ptr->show();
ptr->setCitizens(1500000);
std::cout << "After modification via pointer: ";
ptr->show();
```

## Блок 5: Указатель на метод-член (`LabII.cpp`)

Демонстрируется объявление указателя на метод-член `void Country::show() const` и вызов этого метода:
- через обычный объект (`r1.*showFunc`),
- через указатель на объект (`ptr->*showFunc`).

```cpp
std::cout << "\nUsing pointer to member function:" << std::endl;
void (Country::*showFunc)() const = &Country::show;
(r1.*showFunc)();
(ptr->*showFunc)();
```

## Блок 6: Динамический объект (`LabII.cpp`)

Создаётся динамический объект `Country` в куче с помощью `new`, вызывается метод `show`, после чего объект освобождается через `delete`.  
По сообщениям в консоль видно, что:
- сначала вызывается конструктор с параметрами,
- затем при `delete` — деструктор, который освобождает память под строки.

```cpp
std::cout << "\nCreating dynamic object:" << std::endl;
Country* dynPtr = new Country((char*)"CountryB", 500000, (char*)"President B");
dynPtr->show();
delete dynPtr;
```

## Вывод по работе

В работе реализован класс `Country` с ручным управлением динамической памятью для строковых полей с помощью `char*` и `new[]/delete[]`.  
Реализованы три конструктора (по умолчанию, с параметрами, копирования) и деструктор, обеспечивающие **корректное глубокое копирование** и освобождение памяти.  
Продемонстрирована работа:
- с указателем на объект (`Country*` и синтаксис `ptr->метод`),
- с указателем на метод-член (`void (Country::*)() const` и вызовы `(obj.*ptr)()` / `(ptr->*ptr)()`),
- с динамическими объектами (`new`/`delete`).

В процессе выполнения лабораторной усвоены основы ООП в C++, работа с динамической памятью на уровне сырых указателей и особенности жизненного цикла объектов (порядок вызова конструкторов и деструкторов).
