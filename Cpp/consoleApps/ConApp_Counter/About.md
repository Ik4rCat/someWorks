Разбор кода:

## Задание 1:
Примеры:

```cpp 
operator typename() {}
operator typename() const {}
explicit operator typename() const {}           
```

```cpp
operator bool() const{}   
operator Point3d() const{}
```

создать классы "Point" & "Point3D"
сделать преобразование из одного класса в другой

## Задание 2:
Примеры:

```cpp 
operator typename() {}
operator typename() const {}
explicit operator typename() const {}           
```

```cpp
operator bool() const{}   
operator Point3d() const{}
```

создать классы "Point" & "Point3D"
сделать преобразование из одного класса в другой

## Блок I
```cpp
#include <iostream>

// task 1

class Counter
{
private:
    int count;
public:
    Counter() : count(5) {}
    int operator++(int) { int old = count; count++; return old; }
    int GetCount() const { return count; }
};
```

Первое задание, создается `class Counter` внутри него у нас есть приватное ( `private:` ), целочисленое ( `int` ) переменная `count;`
и публичные:
 - Конструктор `Counter() : count(5) {}`
 - целочисленый оператор который увиличивает переменную `count` на единицу & записывает и возврощает прошлое значение в `old` переменной ( int operator++(int) { int old = count; count++; return old; } )
 - целочисленая функция `GetCount` чтобы получить переменную Count вне класса ( `int GetCount() const { return count; }` )


---

p.s для себя, дописать эту штуку