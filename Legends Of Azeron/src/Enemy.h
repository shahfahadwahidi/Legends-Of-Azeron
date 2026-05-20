#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{
protected:
    int xpReward;
    int lootAmount;

public:
    Enemy(string name, int health, int level, int attackPower, 
          int defense, int xpReward, int loot);
    virtual ~Enemy() = default;

    // Pure virtual - must be overridden
    virtual void attack(Character& player) = 0;
    virtual void useSpecialAbility(Character& player) = 0;

    // Getters
    int getXPReward() const;
    int getLootAmount() const;
};

#endif
