#include "Inventory.h"
#include "Weapon.h"
#include "Potion.h"

Inventory::Inventory(int capacity) 
    : maxCapacity(capacity)
{
}

Inventory::~Inventory()
{
    for (Weapon* weapon : weapons)
    {
        delete weapon;
    }
    weapons.clear();
    
    for (Potion* potion : potions)
    {
        delete potion;
    }
    potions.clear();
}

// ===== WEAPON FUNCTIONS =====
void Inventory::addWeapon(Weapon* weapon)
{
    if (weapons.size() + potions.size() < maxCapacity)
    {
        weapons.push_back(weapon);
        cout << "Added " << weapon->getWeaponName() << " to inventory!" << endl;
    }
    else
    {
        cout << "Inventory is full!" << endl;
    }
}

void Inventory::removeWeapon(int index)
{
    if (index >= 0 && index < weapons.size())
    {
        cout << "Removed " << weapons[index]->getWeaponName() << " from inventory!" << endl;
        weapons.erase(weapons.begin() + index);
    }
}

// ===== POTION FUNCTIONS =====
void Inventory::addPotion(Potion* potion)
{
    if (weapons.size() + potions.size() < maxCapacity)
    {
        potions.push_back(potion);
        cout << "Added " << potion->getPotionType() << " Potion to inventory!" << endl;
    }
    else
    {
        cout << "Inventory is full!" << endl;
    }
}

void Inventory::removePotion(int index)
{
    if (index >= 0 && index < potions.size())
    {
        cout << "Used " << potions[index]->getPotionType() << " Potion!" << endl;
        potions.erase(potions.begin() + index);
    }
}

Potion* Inventory::getPotion(int index) const
{
    if (index >= 0 && index < potions.size())
        return potions[index];
    return nullptr;
}

// ===== DISPLAY FUNCTIONS =====
void Inventory::displayInventory() const
{
    cout << "\n=== WEAPONS (" << weapons.size() << "/" << maxCapacity << ") ===" << endl;
    if (weapons.empty())
    {
        cout << "No weapons in inventory." << endl;
    }
    else
    {
        for (size_t i = 0; i < weapons.size(); i++)
        {
            cout << i + 1 << ". ";
            weapons[i]->displayWeapon();
        }
    }
}

void Inventory::displayPotions() const
{
    cout << "\n=== POTIONS (" << potions.size() << "/" << maxCapacity << ") ===" << endl;
    if (potions.empty())
    {
        cout << "No potions in inventory." << endl;
    }
    else
    {
        for (size_t i = 0; i < potions.size(); i++)
        {
            cout << i + 1 << ". ";
            potions[i]->displayPotion();
        }
    }
}

// ===== GETTERS =====
int Inventory::getItemCount() const { return weapons.size() + potions.size(); }
int Inventory::getPotionCount() const { return potions.size(); }
int Inventory::getWeaponCount() const { return weapons.size(); }

Weapon* Inventory::getWeapon(int index) const
{
    if (index >= 0 && index < weapons.size())
        return weapons[index];
    return nullptr;
}

// ===== OPERATOR OVERLOADING =====
Inventory& Inventory::operator+(Weapon* weapon)
{
    addWeapon(weapon);
    return *this;
}

Inventory& Inventory::operator+(Potion* potion)
{
    addPotion(potion);
    return *this;
}

Weapon* Inventory::getWeapon(int index) const
{
    if (index >= 0 && index < weapons.size())
        return weapons[index];
    return nullptr;
}

Inventory& Inventory::operator+(Weapon* weapon)
{
    addWeapon(weapon);
    return *this;
}
