#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <iostream>
#include "Weapon.h"
#include "Potion.h"

using namespace std;

// Forward declarations
class Player;

class Shop
{
private:
    vector<Weapon*> availableWeapons;
    vector<Potion*> availablePotions;
    string shopName;

public:
    Shop(string name = "Azeron's Legendary Shop");
    ~Shop();

    // Initialize shop with items
    void initializeWeapons();
    void initializePotions();

    // Display functions
    void displayShop() const;
    void displayWeapons() const;
    void displayPotions() const;

    // Buy functions
    bool buyWeapon(int index, Player* player);
    bool buyPotion(int index, Player* player);

    // Getters
    int getWeaponCount() const;
    int getPotionCount() const;
    Weapon* getWeapon(int index) const;
    Potion* getPotion(int index) const;
};

#endif
