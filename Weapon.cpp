#include "Weapon.h"

Weapon::Weapon(string name, int dmg, string rar, string type)
    : weaponName(name), damage(dmg), rarity(rar), weaponType(type), 
      critChance(0), specialDamage(0), price(50), upgradeLevel(0)
{
}

Weapon::Weapon(string name, int dmg, string rar, string type, int crit, int special, int goldPrice)
    : weaponName(name), damage(dmg), rarity(rar), weaponType(type), 
      critChance(crit), specialDamage(special), price(goldPrice), upgradeLevel(0)
{
}

string Weapon::getWeaponName() const { return weaponName; }
int Weapon::getDamage() const { return damage; }
string Weapon::getRarity() const { return rarity; }
string Weapon::getWeaponType() const { return weaponType; }
int Weapon::getCritChance() const { return critChance; }
int Weapon::getSpecialDamage() const { return specialDamage; }
int Weapon::getPrice() const { return price; }
int Weapon::getUpgradeLevel() const { return upgradeLevel; }

void Weapon::displayWeapon() const
{
    cout << "Weapon: " << weaponName << " | Damage: " << damage 
         << " | Rarity: " << rarity << " | Upgrades: " << upgradeLevel;
    
    if (critChance > 0)
        cout << " | Crit: " << critChance << "%";
    if (specialDamage > 0)
        cout << " | Special: " << specialDamage;
    
    cout << endl;
}

void Weapon::upgradeWeapon(int goldCost)
{
    damage += 5;
    upgradeLevel++;
    cout << weaponName << " has been upgraded! New damage: " << damage 
         << " (Level " << upgradeLevel << "). Cost: " << goldCost << " gold" << endl;
}

int Weapon::calculateTotalDamage() const
{
    return damage + specialDamage;
}

bool Weapon::operator==(const Weapon& other) const
{
    return this->damage == other.damage;
}

bool Weapon::operator<(const Weapon& other) const
{
    return this->damage < other.damage;
}
