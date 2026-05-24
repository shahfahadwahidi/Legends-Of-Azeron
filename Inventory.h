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
    void usePotion(int index);
    
    // Display functions
    void displayInventory() const;
    void displayWeapons() const;
    void displayPotions() const;
    
    // Getters
    int getItemCount() const;
    int getWeaponCount() const;
    int getPotionCount() const;
    int getMaxCapacity() const;
    bool isFull() const;
    
    Weapon* getWeapon(int index) const;
    Potion* getPotion(int index) const;
    
    // Capacity management
    void expandCapacity(int additionalSlots);
    
    // Operator overloading
    Inventory& operator+(Weapon* weapon);  // Add weapon using + operator
};

#endif
