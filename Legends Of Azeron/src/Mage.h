#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player
{
public:
    Mage(string name);
    ~Mage() = default;

    // Override attack with mage-specific behavior
    void attack(Character& enemy) override;
    void useSpecialAbility(Character& enemy) override;
};

#endif
