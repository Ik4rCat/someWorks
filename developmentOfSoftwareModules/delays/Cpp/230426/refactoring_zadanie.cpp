// Задание на рефакторинг (230426)
// Исправлены проблемы: копирование кода, магические числа, длинные функции
// 1) Функция calculate — рефакторинг с устранением дублирования
// 2) Класс Character — исправление heal/takeDamage, const-корректность

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

// ============================================================
// 1) БЫЛО: функция calculate с дублированием кода и if-else chain
// СТАЛО: отдельные функции + диспетчер
// ============================================================

double calcSum(const std::vector<double>& data) {
    return std::accumulate(data.begin(), data.end(), 0.0);
}

double calcAverage(const std::vector<double>& data) {
    if (data.empty()) throw std::invalid_argument("Пустой вектор");
    return calcSum(data) / data.size();
}

double calcMax(const std::vector<double>& data) {
    if (data.empty()) throw std::invalid_argument("Пустой вектор");
    return *std::max_element(data.begin(), data.end());
}

double calcMin(const std::vector<double>& data) {
    if (data.empty()) throw std::invalid_argument("Пустой вектор");
    return *std::min_element(data.begin(), data.end());
}

// Диспетчер — заменяет длинный if-else
double calculate(const std::vector<double>& data, const std::string& type) {
    if (type == "sum")     return calcSum(data);
    if (type == "average") return calcAverage(data);
    if (type == "max")     return calcMax(data);
    if (type == "min")     return calcMin(data);
    throw std::invalid_argument("Неизвестный тип: " + type);
}


// ============================================================
// 2) БЫЛО: класс Character с ошибками в heal/takeDamage,
//    без const-корректности, без проверок границ
// СТАЛО: исправленный класс
// ============================================================

class Character {
public:
    Character(const std::string& name, int maxHealth, int maxMana,
              int strength, int intelligence)
        : name_(name), maxHealth_(maxHealth), health_(maxHealth),
          maxMana_(maxMana), mana_(maxMana),
          strength_(strength), intelligence_(intelligence), experience_(0) {}

    // Геттеры — const-корректные
    const std::string& getName() const { return name_; }
    int getHealth() const { return health_; }
    int getMana()   const { return mana_;   }
    int getExp()    const { return experience_; }

    // ИСПРАВЛЕНО: takeDamage уменьшает HP (было: health += amount)
    void takeDamage(int amount) {
        health_ = std::max(0, health_ - amount);
    }

    // ИСПРАВЛЕНО: heal увеличивает HP (было: health -= amount)
    void heal(int amount) {
        health_ = std::min(maxHealth_, health_ + amount);
    }

    void gainExp(int exp) {
        experience_ += exp;
    }

    void addItem(const std::string& item) {
        inventory_.push_back(item);
    }

    void printStatus() const {
        std::cout << "[" << name_ << "] "
                  << "HP: " << health_ << "/" << maxHealth_ << "  "
                  << "MP: " << mana_ << "/" << maxMana_ << "  "
                  << "EXP: " << experience_ << "\n";
    }

private:
    std::string name_;
    int maxHealth_, health_;
    int maxMana_,   mana_;
    int strength_, intelligence_, experience_;
    std::vector<std::string> inventory_;
};


// ============================================================
// main — демонстрация
// ============================================================
int main() {
    // Тест calculate
    std::vector<double> data = {3, 7, 1, 9, 4, 6};
    std::cout << "=== calculate ===\n";
    std::cout << "Sum:     " << calculate(data, "sum")     << "\n";
    std::cout << "Average: " << calculate(data, "average") << "\n";
    std::cout << "Max:     " << calculate(data, "max")     << "\n";
    std::cout << "Min:     " << calculate(data, "min")     << "\n";

    // Тест Character
    std::cout << "\n=== Character ===\n";
    Character hero("Герой", 100, 50, 15, 10);
    hero.printStatus();
    hero.takeDamage(30);
    std::cout << "После takeDamage(30): ";
    hero.printStatus();
    hero.heal(15);
    std::cout << "После heal(15):       ";
    hero.printStatus();
    hero.gainExp(100);
    hero.addItem("Меч");
    hero.printStatus();

    return 0;
}
