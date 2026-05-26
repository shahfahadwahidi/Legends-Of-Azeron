#include "Inventory.h"
#include "Weapon.h"
#include "Potion.h"

Inventory::Inventory(int capacity) 
    : maxCapacity(capacity), weaponCount(0), potionCount(0)
{
}

Inventory::~Inventory()
{
    for (int i = 0; i < weaponCount; i++)
    {
        delete weapons[i];
    }
    
    for (int i = 0; i < potionCount; i++)
    {
        delete potions[i];
    }
}

// Weapon functions
void Inventory::addWeapon(Weapon* weapon)
{
    if ((weaponCount + potionCount) < maxCapacity && weaponCount < MAX_ITEMS)
    {
        weapons[weaponCount++] = weapon;
        cout << "Added " << weapon->getWeaponName() << " to inventory!" << endl;
    }
    else
    {
        cout << "Inventory is full! Cannot add " << weapon->getWeaponName() << endl;
    }
}

void Inventory::removeWeapon(int index)
{
    if (index >= 0 && index < weaponCount)
    {
        cout << "Removed " << weapons[index]->getWeaponName() << " from inventory!" << endl;
        // Shift remaining weapons
        for (int i = index; i < weaponCount - 1; i++)
        {
            weapons[i] = weapons[i + 1];
        }
        weaponCount--;
    }
}

// Potion functions
void Inventory::addPotion(Potion* potion)
{
    if ((weaponCount + potionCount) < maxCapacity && potionCount < MAX_ITEMS)
    {
        potions[potionCount++] = potion;
        cout << "Added " << potion->getPotionName() << " to inventory!" << endl;
    }
    else
    {
        cout << "Inventory is full! Cannot add " << potion->getPotionName() << endl;
    }
}

void Inventory::removePotion(int index)
{
    if (index >= 0 && index < potionCount)
    {
        cout << "Used " << potions[index]->getPotionName() << "!" << endl;
        // Shift remaining potions
        for (int i = index; i < potionCount - 1; i++)
        {
            potions[i] = potions[i + 1];
        }
        potionCount--;
    }
}

void Inventory::usePotion(int index)
{
    if (index >= 0 && index < potionCount)
    {
        cout << "Using " << potions[index]->getPotionName() << "..." << endl;
        // Shift remaining potions
        for (int i = index; i < potionCount - 1; i++)
        {
            potions[i] = potions[i + 1];
        }
        potionCount--;
    }
}

// Display functions
void Inventory::displayInventory() const
{
    int totalItems = weaponCount + potionCount;
    cout << "\n=== INVENTORY (" << totalItems << "/" << maxCapacity << ") ===" << endl;
    
    if (weaponCount > 0)
    {
        cout << "\n--- WEAPONS ---" << endl;
        for (int i = 0; i < weaponCount; i++)
        {
            cout << i + 1 << ". ";
            weapons[i]->displayWeapon();
        }
    }
    
    if (potionCount > 0)
    {
        cout << "\n--- POTIONS ---" << endl;
        for (int i = 0; i < potionCount; i++)
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
    cout << "\n--- WEAPONS (" << weaponCount << ") ---" << endl;
    for (int i = 0; i < weaponCount; i++)
    {
        cout << i + 1 << ". ";
        weapons[i]->displayWeapon();
    }
}

void Inventory::displayPotions() const
{
    cout << "\n--- POTIONS (" << potionCount << ") ---" << endl;
    for (int i = 0; i < potionCount; i++)
    {
        cout << i + 1 << ". ";
        potions[i]->displayPotion();
    }
}

// Getters
int Inventory::getItemCount() const { return weaponCount + potionCount; }
int Inventory::getWeaponCount() const { return weaponCount; }
int Inventory::getPotionCount() const { return potionCount; }
int Inventory::getMaxCapacity() const { return maxCapacity; }
bool Inventory::isFull() const { return (weaponCount + potionCount) >= maxCapacity; }

Weapon* Inventory::getWeapon(int index) const
{
    if (index >= 0 && index < weaponCount)
        return weapons[index];
    return nullptr;
}

Potion* Inventory::getPotion(int index) const
{
    if (index >= 0 && index < potionCount)
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
