#include "Inventory.h"
#include "Weapon.h"

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
}

void Inventory::addWeapon(Weapon* weapon)
{
    if (weapons.size() < maxCapacity)
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

void Inventory::displayInventory() const
{
    cout << "\n=== INVENTORY (" << weapons.size() << "/" << maxCapacity << ") ===" << endl;
    for (size_t i = 0; i < weapons.size(); i++)
    {
        cout << i + 1 << ". ";
        weapons[i]->displayWeapon();
    }
}

int Inventory::getItemCount() const { return weapons.size(); }

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
