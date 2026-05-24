#include "Inventory.h"
#include "Weapon.h"
#include "Potion.h"

Inventory::Inventory(int capacity) 
    : maxCapacity(capacity)
{
}

Inventory::~Inventory()
{
    for (auto weapon : weapons)
    {
        delete weapon;
    }
    weapons.clear();
    
    for (auto potion : potions)
    {
        delete potion;
    }
    potions.clear();
}

// Weapon functions
void Inventory::addWeapon(Weapon* weapon)
{
    if ((weapons.size() + potions.size()) < maxCapacity)
    {
        weapons.push_back(weapon);
        cout << "Added " << weapon->getWeaponName() << " to inventory!" << endl;
    }
    else
    {
        cout << "Inventory is full! Cannot add " << weapon->getWeaponName() << endl;
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

// Potion functions
void Inventory::addPotion(Potion* potion)
{
    if ((weapons.size() + potions.size()) < maxCapacity)
    {
        potions.push_back(potion);
        cout << "Added " << potion->getPotionName() << " to inventory!" << endl;
    }
    else
    {
        cout << "Inventory is full! Cannot add " << potion->getPotionName() << endl;
    }
}

void Inventory::removePotion(int index)
{
    if (index >= 0 && index < potions.size())
    {
        cout << "Used " << potions[index]->getPotionName() << "!" << endl;
        potions.erase(potions.begin() + index);
    }
}

void Inventory::usePotion(int index)
{
    if (index >= 0 && index < potions.size())
    {
        cout << "Using " << potions[index]->getPotionName() << "..." << endl;
        potions.erase(potions.begin() + index);
    }
}

// Display functions
void Inventory::displayInventory() const
{
    int totalItems = weapons.size() + potions.size();
    cout << "\n=== INVENTORY (" << totalItems << "/" << maxCapacity << ") ===" << endl;
    
    if (weapons.size() > 0)
    {
        cout << "\n--- WEAPONS ---" << endl;
        for (size_t i = 0; i < weapons.size(); i++)
        {
            cout << i + 1 << ". ";
            weapons[i]->displayWeapon();
        }
    }
    
    if (potions.size() > 0)
    {
        cout << "\n--- POTIONS ---" << endl;
        for (size_t i = 0; i < potions.size(); i++)
        {
            cout << i + 1 << ". ";
            potions[i]->displayPotion();
        }
    }
    
    if (totalItems == 0)
        cout << "Your inventory is empty!" << endl;
}

void Inventory::displayWeapons() const
{
    cout << "\n--- WEAPONS (" << weapons.size() << ") ---" << endl;
    for (size_t i = 0; i < weapons.size(); i++)
    {
        cout << i + 1 << ". ";
        weapons[i]->displayWeapon();
    }
}

void Inventory::displayPotions() const
{
    cout << "\n--- POTIONS (" << potions.size() << ") ---" << endl;
    for (size_t i = 0; i < potions.size(); i++)
    {
        cout << i + 1 << ". ";
        potions[i]->displayPotion();
    }
}

// Getters
int Inventory::getItemCount() const { return weapons.size() + potions.size(); }
int Inventory::getWeaponCount() const { return weapons.size(); }
int Inventory::getPotionCount() const { return potions.size(); }
int Inventory::getMaxCapacity() const { return maxCapacity; }
bool Inventory::isFull() const { return (weapons.size() + potions.size()) >= maxCapacity; }

Weapon* Inventory::getWeapon(int index) const
{
    if (index >= 0 && index < weapons.size())
        return weapons[index];
    return nullptr;
}

Potion* Inventory::getPotion(int index) const
{
    if (index >= 0 && index < potions.size())
        return potions[index];
    return nullptr;
}

// Capacity management
void Inventory::expandCapacity(int additionalSlots)
{
    maxCapacity += additionalSlots;
    cout << "Inventory expanded! New capacity: " << maxCapacity << " slots" << endl;
}

Inventory& Inventory::operator+(Weapon* weapon)
{
    addWeapon(weapon);
    return *this;
}
