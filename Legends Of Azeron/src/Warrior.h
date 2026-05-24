#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior : public Player
{
public:
    Warrior(string name);
    ~Warrior() = default;

    // Override attack with warrior-specific behavior
    void attack(Character& enemy) override;
    void useSpecialAbility(Character& enemy) override;
};

#endif
