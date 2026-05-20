#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "Player.h"

class Assassin : public Player
{
public:
    Assassin(string name);
    ~Assassin() = default;

    // Override attack with assassin-specific behavior
    void attack(Character& enemy) override;
    void useSpecialAbility(Character& enemy) override;
};

#endif
