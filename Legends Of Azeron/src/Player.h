#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

// Forward declaration
class Inventory;

class Player : public Character
{
protected:
    int xp;
    int xpToNextLevel;
    int gold;
    Inventory* inventory;

public:
    Player(string name, int health, int level, int attackPower, int defense);
    virtual ~Player();

    // Override attack and special ability (polymorphism)
    virtual void attack(Character& enemy) = 0;
    virtual void useSpecialAbility(Character& enemy) = 0;

    // Player-specific functions
    void gainXP(int amount);
    void levelUp();
    void addGold(int amount);
    void spendGold(int amount);

    // Potion functions
    void useHealthPotion();
    void useManaPotion();
    void displayInventory() const;
    void displayPotions() const;
    
    // Getters
    int getXP() const;
    int getGold() const;
    Inventory* getInventory() const;
    
    // Setters (for save/load)
    void setXP(int x);
    void setGold(int g);

    // Operator overloading
    bool operator>(const Player& other) const;  // Compare by level
};

#endif
