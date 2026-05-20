#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <iostream>

using namespace std;

// Forward declaration
class Weapon;

class Inventory
{
private:
    vector<Weapon*> weapons;
    int maxCapacity;

public:
    Inventory(int capacity = 10);
    ~Inventory();

    // Functions
    void addWeapon(Weapon* weapon);
    void removeWeapon(int index);
    void displayInventory() const;
    
    // Getters
    int getItemCount() const;
    Weapon* getWeapon(int index) const;
    
    // Operator overloading
    Inventory& operator+(Weapon* weapon);  // Add weapon using + operator
};

#endif
