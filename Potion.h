#ifndef POTION_H
#define POTION_H

#include <string>
#include <iostream>

using namespace std;

class Potion
{
private:
    string potionType;  // HEALTH, MEGA_HEALTH, MANA, STRENGTH, DEFENSE, CRITICAL, REVIVE
    string potionName;
    int restoreAmount;
    int duration;  // Turns (0 = instant, 1+ = temporary buff)
    int price;     // Gold cost in shop

public:
    Potion(string type, string name, int amount, int dur, int goldPrice);
    
    // Getters
    string getPotionType() const;
    string getPotionName() const;
    int getRestoreAmount() const;
    int getDuration() const;
    int getPrice() const;
    
    // Functions
    void displayPotion() const;
};

#endif
