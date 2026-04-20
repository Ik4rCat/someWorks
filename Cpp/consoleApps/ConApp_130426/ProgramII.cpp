#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character {
private:
    string name;

    int health;
    int maxHealth;
    int mana;
    int maxMana;
    int level;
    int experience;
    int strength;
    int agility;
    int intelligence;
    
    vector<string> inventory;
    
public:
    Character(string n) : name(n), health(100), maxHealth(100), mana(50), maxMana(50), 
                               level(1), experience(0), strength(10), agility(10), intelligence(10) {}
    
    void takeDamage(int amount) 
    {    
        health -= amount;
        
        if (health <= 0) 
        {
            health = 0;
            cout << name << " died!" << endl;
        }
    }
    
    void heal(int amount) 
    {
        health += amount;
        if (health > maxHealth) health = maxHealth;
    }
    
    void addExperience(int exp) 
    {
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
    
    void addItem(string item) { inventory.push_back(item); }
    
    
    bool useItem(string item) {
        for (int i = 0; i < inventory.size(); i++)
        {
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
    
    int attack() { return strength + (rand() % 10); }
    
    string getName() { return name; }
    
    int getHealth() { return health; }
    int getMana() { return mana; }
    int getLevel() { return level; }
};


