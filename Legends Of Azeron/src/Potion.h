#ifndef POTION_H
#define POTION_H

#include <string>
#include <iostream>

using namespace std;

class Potion
{
private:
    string potionType;  // Health, Mana
    int restoreAmount;

public:
    Potion(string type, int amount);
    
    // Getters
    string getPotionType() const;
    int getRestoreAmount() const;
    
    // Functions
    void displayPotion() const;
};

#endif
