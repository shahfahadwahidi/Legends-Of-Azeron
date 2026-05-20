#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

using namespace std;

// ABSTRACT BASE CLASS
class Character
{
protected:
    string name;
    int health;
    int maxHealth;
    int level;
    int attackPower;
    int defense;
    int defenseBoost;  // Temporary defense increase from defend action

public:
    Character(string name, int health, int level, int attackPower, int defense);
    virtual ~Character() = default;

    // Pure virtual functions - must be overridden in derived classes
    virtual void attack(Character& enemy) = 0;
    virtual void useSpecialAbility(Character& enemy) = 0;

    // Common functions
    void takeDamage(int damage);
    void defend();
    void resetDefenseBoost();
    void displayStats() const;
    bool isAlive() const;

    // Getters
    string getName() const;
    int getHealth() const;
    int getLevel() const;
    int getAttackPower() const;
    int getDefense() const;
    int getTotalDefense() const;
    
    // Setters (for save/load)
    void setHealth(int h);
};

#endif
