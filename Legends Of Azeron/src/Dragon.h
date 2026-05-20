#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"

class Dragon : public Enemy
{
public:
    Dragon();
    ~Dragon() = default;

    // Override attack with dragon-specific behavior
    void attack(Character& player) override;
    void useSpecialAbility(Character& player) override;
};

#endif
