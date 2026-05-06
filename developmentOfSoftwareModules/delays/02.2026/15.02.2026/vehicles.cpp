#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────
//  Абстрактный базовый класс
// ─────────────────────────────────────────
class Vehicle {
protected:
    string make;
    string model;
    int    year;
public:
    Vehicle(const string &make, const string &model, int year)
        : make(make), model(model), year(year) {}
    virtual ~Vehicle() {}

    virtual void Move() = 0; // чисто виртуальный

    void info() const {
        cout << year << " " << make << " " << model;
    }
};

// ─────────────────────────────────────────
//  "Интерфейсы" (абстрактные классы)
// ─────────────────────────────────────────
class IFlyable {
public:
    virtual void Fly(int meters) = 0;
    virtual ~IFlyable() {}
};

class ISwimmable {
public:
    virtual void Swim(int meters) = 0;
    virtual ~ISwimmable() {}
};

// ═════════════════════════════════════════
//  Наследует только Vehicle (1 родитель)
// ═════════════════════════════════════════

// Машина — только едет
class Car : public Vehicle {
public:
    Car(const string &make, const string &model, int year)
        : Vehicle(make, model, year) {}

    void Move() override {
        info(); cout << " едет по дороге." << endl;
    }
};

// Велосипед — только едет
class Bicycle : public Vehicle {
public:
    Bicycle(const string &make, const string &model, int year)
        : Vehicle(make, model, year) {}

    void Move() override {
        info(); cout << " едет на велосипеде." << endl;
    }
};

// ═════════════════════════════════════════
//  Наследует Vehicle + 1 интерфейс (2 родителя)
// ═════════════════════════════════════════

// Лодка — едет и плывёт
class Boat : public Vehicle, public ISwimmable {
public:
    Boat(const string &make, const string &model, int year)
        : Vehicle(make, model, year) {}

    void Move() override {
        info(); cout << " движется по воде." << endl;
    }
    void Swim(int meters) override {
        info(); cout << " проплыла " << meters << " м." << endl;
    }
};

// Самолёт — едет и летит
class Airplane : public Vehicle, public IFlyable {
public:
    Airplane(const string &make, const string &model, int year)
        : Vehicle(make, model, year) {}

    void Move() override {
        info(); cout << " движется по взлётной полосе." << endl;
    }
    void Fly(int meters) override {
        info(); cout << " пролетел " << meters << " м." << endl;
    }
};

// ═════════════════════════════════════════
//  Наследует Vehicle + оба интерфейса (3 родителя)
// ═════════════════════════════════════════

// Летающая лодка — едет, летит и плывёт
class FlyingBoat : public Vehicle, public IFlyable, public ISwimmable {
public:
    FlyingBoat(const string &make, const string &model, int year)
        : Vehicle(make, model, year) {}

    void Move() override {
        info(); cout << " переключается между режимами." << endl;
    }
    void Fly(int meters) override {
        info(); cout << " пролетела " << meters << " м над водой." << endl;
    }
    void Swim(int meters) override {
        info(); cout << " проплыла " << meters << " м по воде." << endl;
    }
};

// Амфибия — едет, летит и плывёт
class Amphibian : public Vehicle, public IFlyable, public ISwimmable {
public:
    Amphibian(const string &make, const string &model, int year)
        : Vehicle(make, model, year) {}

    void Move() override {
        info(); cout << " едет по суше." << endl;
    }
    void Fly(int meters) override {
        info(); cout << " взлетела на " << meters << " м." << endl;
    }
    void Swim(int meters) override {
        info(); cout << " проплыла " << meters << " м." << endl;
    }
};

// ─────────────────────────────────────────
//  main
// ─────────────────────────────────────────
int main() {
    cout << "=== 1 родитель (только Vehicle) ===" << endl;
    Car     car("Toyota", "Camry", 2020);
    Bicycle bike("Trek", "FX3", 2022);
    car.Move();
    bike.Move();

    cout << "\n=== 2 родителя (Vehicle + интерфейс) ===" << endl;
    Boat     boat("Yamaha", "242X", 2021);
    Airplane plane("Boeing", "737", 2019);
    boat.Move();
    boat.Swim(500);
    plane.Move();
    plane.Fly(10000);

    cout << "\n=== 3 родителя (Vehicle + IFlyable + ISwimmable) ===" << endl;
    FlyingBoat fb("Beriev", "Be-200", 2018);
    Amphibian  am("ICON", "A5", 2023);
    fb.Move();
    fb.Fly(2000);
    fb.Swim(300);
    am.Move();
    am.Fly(1500);
    am.Swim(200);

    cout << "\n=== Полиморфизм через Vehicle* ===" << endl;
    Vehicle *vehicles[] = { &car, &bike, &boat, &plane, &fb, &am };
    for (Vehicle *v : vehicles) v->Move();

    cout << "\n=== Полиморфизм через IFlyable* ===" << endl;
    IFlyable *flyers[] = { &plane, &fb, &am };
    for (IFlyable *f : flyers) f->Fly(1000);

    cout << "\n=== Полиморфизм через ISwimmable* ===" << endl;
    ISwimmable *swimmers[] = { &boat, &fb, &am };
    for (ISwimmable *s : swimmers) s->Swim(100);

    return 0;
}
