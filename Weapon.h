#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

using namespace std;

// Weapon Types
enum class WeaponType
{
    SWORD,              // Balanced damage
    AXE,                // High damage, slow
    DAGGER,             // Low damage, high crit chance
    STAFF,              // Boosts Mage attacks
    BOW,                // Consistent ranged damage
    POISON_DAGGER,      // Extra damage over time
    FIRE_SWORD,         // Bonus fire damage
    LEGENDARY_BLADE     // High damage + special effect
};

class Weapon
{
private:
    string weaponName;
    int damage;
    string rarity;  // Common, Uncommon, Rare, Legendary
    WeaponType weaponType;
    int critChance;  // 0-100%
    int specialDamage;  // Poison/Fire damage
    int price;  // Gold cost in shop
    int upgradeLevel;  // Number of times upgraded

public:
    Weapon(string name, int dmg, string rar, WeaponType type);
    Weapon(string name, int dmg, string rar, WeaponType type, int crit, int special, int goldPrice);
    
    // Getters
    string getWeaponName() const;
    int getDamage() const;
    string getRarity() const;
    WeaponType getWeaponType() const;
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
