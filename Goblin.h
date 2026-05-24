#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"

class Goblin : public Enemy
{
public:
    Goblin();
    ~Goblin() = default;

    // Override attack with goblin-specific behavior
    void attack(Character& player) override;
    void useSpecialAbility(Character& player) override;
};

#endif
