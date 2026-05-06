#include <iostream>
#include <string>
#include <map>
using namespace std;

// ══════════════════════════════════════════════════
//  1. FACTORY METHOD — создание воинов
// ══════════════════════════════════════════════════
namespace FactoryMethod {

class Warrior {
public:
    virtual void attack() = 0;
    virtual string type() = 0;
    virtual ~Warrior() {}
};

class Infantryman : public Warrior {
public:
    void attack() override { cout << "  Пехотинец атакует мечом!\n"; }
    string type() override { return "Infantryman"; }
};

class Archer : public Warrior {
public:
    void attack() override { cout << "  Лучник стреляет!\n"; }
    string type() override { return "Archer"; }
};

class Horseman : public Warrior {
public:
    void attack() override { cout << "  Конник атакует на скаку!\n"; }
    string type() override { return "Horseman"; }
};

// Абстрактная фабрика
class WarriorFactory {
public:
    virtual Warrior* createWarrior() = 0;
    virtual ~WarriorFactory() {}
};

class InfantryFactory : public WarriorFactory {
public:
    Warrior* createWarrior() override { return new Infantryman(); }
};

class ArcherFactory : public WarriorFactory {
public:
    Warrior* createWarrior() override { return new Archer(); }
};

class HorsemanFactory : public WarriorFactory {
public:
    Warrior* createWarrior() override { return new Horseman(); }
};

void demo() {
    cout << "\n=== Factory Method ===\n";
    WarriorFactory* factories[] = {
        new InfantryFactory(),
        new ArcherFactory(),
        new HorsemanFactory()
    };
    for (auto* f : factories) {
        Warrior* w = f->createWarrior();
        cout << "  Создан: " << w->type() << " → ";
        w->attack();
        delete w;
        delete f;
    }
}

} // namespace FactoryMethod

// ══════════════════════════════════════════════════
//  2. ABSTRACT FACTORY — GUI для разных платформ
// ══════════════════════════════════════════════════
namespace AbstractFactory {

class Button {
public:
    virtual void render() = 0;
    virtual ~Button() {}
};

class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() {}
};

class WinButton   : public Button   { public: void render() override { cout << "  [Win Button]\n";   } };
class WinCheckbox : public Checkbox { public: void render() override { cout << "  [Win Checkbox]\n"; } };
class MacButton   : public Button   { public: void render() override { cout << "  [Mac Button]\n";   } };
class MacCheckbox : public Checkbox { public: void render() override { cout << "  [Mac Checkbox]\n"; } };

class GUIFactory {
public:
    virtual Button*   createButton()   = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

class WinFactory : public GUIFactory {
public:
    Button*   createButton()   override { return new WinButton();   }
    Checkbox* createCheckbox() override { return new WinCheckbox(); }
};

class MacFactory : public GUIFactory {
public:
    Button*   createButton()   override { return new MacButton();   }
    Checkbox* createCheckbox() override { return new MacCheckbox(); }
};

void renderUI(GUIFactory* factory) {
    Button*   btn = factory->createButton();
    Checkbox* chk = factory->createCheckbox();
    btn->render();
    chk->render();
    delete btn;
    delete chk;
}

void demo() {
    cout << "\n=== Abstract Factory ===\n";
    cout << "  Windows UI:\n";
    WinFactory win;
    renderUI(&win);

    cout << "  Mac UI:\n";
    MacFactory mac;
    renderUI(&mac);
}

} // namespace AbstractFactory

// ══════════════════════════════════════════════════
//  3. SINGLETON — логгер
// ══════════════════════════════════════════════════
namespace SingletonPattern {

class Logger {
private:
    Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
public:
    static Logger& getInstance() {
        static Logger instance; // Singleton Мэйерса
        return instance;
    }
    void log(const string& msg) {
        cout << "  [LOG] " << msg << "\n";
    }
};

void demo() {
    cout << "\n=== Singleton ===\n";
    Logger::getInstance().log("Запуск системы");
    Logger::getInstance().log("Создан воин");

    // Проверяем что это один и тот же объект
    Logger& a = Logger::getInstance();
    Logger& b = Logger::getInstance();
    cout << "  Один объект? " << (&a == &b ? "да" : "нет") << "\n";
}

} // namespace SingletonPattern

// ══════════════════════════════════════════════════
//  4. PROTOTYPE — клонирование воинов
// ══════════════════════════════════════════════════
namespace PrototypePattern {

class Warrior {
public:
    string name;
    int    power;
    Warrior(const string& n, int p) : name(n), power(p) {}
    virtual Warrior* clone() const = 0;
    virtual string type() const = 0;
    void info() const {
        cout << "  " << type() << ": " << name << " (power=" << power << ")\n";
    }
    virtual ~Warrior() {}
};

class Infantryman : public Warrior {
public:
    Infantryman(const string& n, int p) : Warrior(n, p) {}
    Warrior* clone() const override { return new Infantryman(*this); }
    string type() const override { return "Infantryman"; }
};

class Archer : public Warrior {
public:
    Archer(const string& n, int p) : Warrior(n, p) {}
    Warrior* clone() const override { return new Archer(*this); }
    string type() const override { return "Archer"; }
};

class WarriorRegistry {
    map<string, Warrior*> registry;
public:
    void add(const string& key, Warrior* proto) { registry[key] = proto; }
    Warrior* create(const string& key) {
        if (registry.count(key)) return registry[key]->clone();
        return nullptr;
    }
    ~WarriorRegistry() { for (auto& p : registry) delete p.second; }
};

void demo() {
    cout << "\n=== Prototype ===\n";
    WarriorRegistry reg;
    reg.add("infantry", new Infantryman("Легионер", 80));
    reg.add("archer",   new Archer("Стрелок", 60));

    Warrior* w1 = reg.create("infantry");
    Warrior* w2 = reg.create("infantry");
    Warrior* w3 = reg.create("archer");

    w1->info();
    w2->info();
    w3->info();

    // Изменяем клон — оригинал не меняется
    w2->name = "Легионер II";
    w2->power = 90;
    cout << "  После изменения клона:\n";
    w1->info();
    w2->info();

    delete w1; delete w2; delete w3;
}

} // namespace PrototypePattern

// ══════════════════════════════════════════════════
//  5. BUILDER — армии Пунических войн
// ══════════════════════════════════════════════════
namespace BuilderPattern {

struct Army {
    string name;
    int infantry = 0, archers = 0, cavalry = 0;
    int catapults = 0, elephants = 0;

    void show() const {
        cout << "  Армия " << name << ":"
             << " пехота=" << infantry
             << " лучники=" << archers
             << " конница=" << cavalry;
        if (catapults) cout << " катапульты=" << catapults;
        if (elephants) cout << " слоны=" << elephants;
        cout << "\n";
    }
};

class ArmyBuilder {
public:
    Army army;
    virtual void buildInfantry()  {}
    virtual void buildArchers()   {}
    virtual void buildCavalry()   {}
    virtual void buildCatapults() {}
    virtual void buildElephants() {}
    Army getArmy() { return army; }
    virtual ~ArmyBuilder() {}
};

class RomanArmyBuilder : public ArmyBuilder {
public:
    RomanArmyBuilder() { army.name = "Рима"; }
    void buildInfantry()  override { army.infantry  = 100; }
    void buildArchers()   override { army.archers   = 50;  }
    void buildCavalry()   override { army.cavalry   = 30;  }
    void buildCatapults() override { army.catapults = 10;  }
};

class CarthaginianArmyBuilder : public ArmyBuilder {
public:
    CarthaginianArmyBuilder() { army.name = "Карфагена"; }
    void buildInfantry()  override { army.infantry  = 80;  }
    void buildArchers()   override { army.archers   = 60;  }
    void buildCavalry()   override { army.cavalry   = 40;  }
    void buildElephants() override { army.elephants = 20;  }
};

class Director {
    ArmyBuilder* builder;
public:
    Director(ArmyBuilder* b) : builder(b) {}
    Army construct() {
        builder->buildInfantry();
        builder->buildArchers();
        builder->buildCavalry();
        builder->buildCatapults();
        builder->buildElephants();
        return builder->getArmy();
    }
};

void demo() {
    cout << "\n=== Builder ===\n";
    RomanArmyBuilder        romanBuilder;
    CarthaginianArmyBuilder carthBuilder;

    Director d1(&romanBuilder);
    Director d2(&carthBuilder);

    d1.construct().show();
    d2.construct().show();
}

} // namespace BuilderPattern

// ══════════════════════════════════════════════════
//  main
// ══════════════════════════════════════════════════
int main() {
    FactoryMethod::demo();
    AbstractFactory::demo();
    SingletonPattern::demo();
    PrototypePattern::demo();
    BuilderPattern::demo();
    return 0;
}
