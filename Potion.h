#ifndef POTION_H
#define POTION_H

#include <string>
#include <iostream>

using namespace std;

// Potion Types
enum class PotionType
{
    HEALTH,           // Restore HP
    MEGA_HEALTH,      // Restore large amount of HP
    MANA,             // Restore Mana (for Mages)
    STRENGTH,         // +attack for 1 turn
    DEFENSE,          // +defense for 1 turn
    CRITICAL,         // Higher crit chance for 1 turn
    REVIVE            // Restore from 0 HP (if health == 0)
};

class Potion
{
private:
    PotionType potionType;
    string potionName;
    int restoreAmount;
    int duration;  // Turns (0 = instant, 1+ = temporary buff)
    int price;     // Gold cost in shop

public:
    Potion(PotionType type, string name, int amount, int dur, int goldPrice);
    
    // Getters
    PotionType getPotionType() const;
    string getPotionName() const;
    int getRestoreAmount() const;
    int getDuration() const;
    int getPrice() const;
    
    // Functions
    void displayPotion() const;
};

#endif
