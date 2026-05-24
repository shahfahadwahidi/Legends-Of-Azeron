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
    virtual ~Player() = default;

    // Override attack and special ability (polymorphism)
    virtual void attack(Character& enemy) = 0;
    virtual void useSpecialAbility(Character& enemy) = 0;

    // Player-specific functions
    void gainXP(int amount);
    void levelUp();
    void addGold(int amount);
    
    // Gold-based features
    bool healWithGold(int goldCost, int hpRestore);  // Pay gold to restore HP
    bool upgradeWeaponWithGold(int goldCost);        // Pay gold to upgrade weapon
    bool expandInventoryWithGold(int goldCost);      // Pay 100 gold for +5 slots

    // Inventory functions
    Inventory* getInventory() const;
    void displayInventory() const;

    // Getters
    int getXP() const;
    int getGold() const;
    
    // Setters (for save/load)
    void setXP(int x);
    void setGold(int g);

    // Operator overloading
    bool operator>(const Player& other) const;  // Compare by level
};

#endif
