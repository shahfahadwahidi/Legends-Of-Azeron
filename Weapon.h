#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

using namespace std;

class Weapon
{
private:
    string weaponName;
    int damage;
    string rarity;  // Common, Uncommon, Rare, Legendary
    string weaponType;  // SWORD, AXE, DAGGER, STAFF, BOW, etc.
    int critChance;  // 0-100%
    int specialDamage;  // Poison/Fire damage
    int price;  // Gold cost in shop
    int upgradeLevel;  // Number of times upgraded

public:
    Weapon(string name, int dmg, string rar, string type);
    Weapon(string name, int dmg, string rar, string type, int crit, int special, int goldPrice);
    
    // Getters
    string getWeaponName() const;
    int getDamage() const;
    string getRarity() const;
    string getWeaponType() const;
    int getCritChance() const;
    int getSpecialDamage() const;
    int getPrice() const;
    int getUpgradeLevel() const;
    
    // Functions
    void displayWeapon() const;
    void upgradeWeapon(int goldCost = 50);  // Upgrade costs gold
    int calculateTotalDamage() const;  // Includes special effects
    
    // Operator overloading
    bool operator==(const Weapon& other) const;  // Compare damage
    bool operator<(const Weapon& other) const;   // Compare by damage
};

#endif
