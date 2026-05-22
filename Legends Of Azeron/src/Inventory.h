#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>

using namespace std;

// Forward declarations
class Weapon;
class Potion;

class Inventory
{
private:
    vector<Weapon*> weapons;
    vector<Potion*> potions;
    int maxCapacity;

public:
    Inventory(int capacity = 10);
    ~Inventory();

    // Weapon functions
    void addWeapon(Weapon* weapon);
    void removeWeapon(int index);
    
    // Potion functions
    void addPotion(Potion* potion);
    void removePotion(int index);
    Potion* getPotion(int index) const;
    
    void displayInventory() const;
    void displayPotions() const;
    
    // Getters
    int getItemCount() const;
    int getPotionCount() const;
    int getWeaponCount() const;
    Weapon* getWeapon(int index) const;
    
    // Operator overloading
    Inventory& operator+(Weapon* weapon);  // Add weapon using + operator
    Inventory& operator+(Potion* potion);  // Add potion using + operator
};

#endif
