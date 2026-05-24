#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy
{
public:
    Orc();
    ~Orc() = default;

    // Override attack with orc-specific behavior
    void attack(Character& player) override;
    void useSpecialAbility(Character& player) override;
};

#endif
