1)_____________________________________________________________
```cpp
#include <vector>
#include <string>
#include <algorithm>

double calculate(std::vector<double> data, std::string type) {
    double result = 0.0;
    if (type == "sum") {
        for (int i = 0; i < data.size(); i++) {
            result = result + data[i];
        }
    } else if (type == "avg") {
        double sum = 0.0;
        for (int i = 0; i < data.size(); i++) {
            sum = sum + data[i];
        }
        if (data.size() > 0) {
            result = sum / data.size();
        }
    } else if (type == "max") {
        if (data.size() > 0) {
            result = data[0];
            for (int i = 1; i < data.size(); i++) {
                if (data[i] > result) {
                    result = data[i];
                }
            }
        }
    } else if (type == "min") {
        if (data.size() > 0) {
            result = data[0];
            for (int i = 1; i < data.size(); i++) {
                if (data[i] < result) {
                    result = data[i];
                }
            }
        }
    }
    return result;
}
```
Копирование кода, числа, длиннная функция

2)_______________________________________________________________________________________
```cpp
#include <string>
#include <vector>

class Character {
private:
    std::string name;
    int health;
    int maxHealth;
    int mana;
    int maxMana;
    int level;
    int experience;
    int strength;
    int agility;
    int intelligence;
    std::vector<std::string> inventory;
    
public:
    Character(std::string n) : name(n), health(100), maxHealth(100), mana(50), maxMana(50), 
                                level(1), experience(0), strength(10), agility(10), intelligence(10) {}
    
    void takeDamage(int amount) {
        health -= amount;
        if (health <= 0) {
            health = 0;
            std::cout << name << " died!" << std::endl;
        }
    }
    
    void heal(int amount) {
        health += amount;
        if (health > maxHealth) health = maxHealth;
    }
    
    void addExperience(int exp) {
        experience += exp;
        if (experience >= level * 100) {
            level++;
            experience = 0;
            strength += 5;
            agility += 5;
            intelligence += 5;
            maxHealth += 20;
            maxMana += 10;
            health = maxHealth;
            mana = maxMana;
        }
    }
    
    void addItem(std::string item) {
        inventory.push_back(item);
    }
    
    bool useItem(std::string item) {
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i] == item) {
                if (item == "potion") heal(30);
                else if (item == "mana_potion") {
                    mana += 20;
                    if (mana > maxMana) mana = maxMana;
                }
                inventory.erase(inventory.begin() + i);
                return true;
            }
        }
        return false;
    }
    
    int attack() {
        return strength + (rand() % 10);
    }
    
    std::string getName() { return name; }
    int getHealth() { return health; }
    int getMana() { return mana; }
    int getLevel() { return level; }
};
```
Много ответственности, длинные методы, дублированиие логики

3)))_____________________________________________________
```cpp
#include <vector>
#include <string>

struct Order {
    int id;
    std::string customer;
    double amount;
    int status; // 1=new, 2=paid, 3=shipped, 4=done
};

class OrderProcessor {
    std::vector<Order> orders;
    
public:
    void process(int id, int action) {
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].id == id) {
                if (action == 1) {
                    if (orders[i].status == 1) {
                        orders[i].status = 2;
                        sendEmail(orders[i].customer, "Order paid");
                    }
                } else if (action == 2) {
                    if (orders[i].status == 2) {
                        orders[i].status = 3;
                        sendEmail(orders[i].customer, "Order shipped");
                    }
                } else if (action == 3) {
                    if (orders[i].status == 3) {
                        orders[i].status = 4;
                    }
                } else if (action == 4) {
                    if (orders[i].status == 1) {
                        orders.erase(orders.begin() + i);
                    }
                }
                break;
            }
        }
    }
    
    void sendEmail(std::string to, std::string msg) {
        // sending email...
    }
};
```
