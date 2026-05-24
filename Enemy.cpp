#include "Enemy.h"

Enemy::Enemy(string name, int health, int level, int attackPower, 
             int defense, int xpReward, int loot)
    : Character(name, health, level, attackPower, defense),
      xpReward(xpReward), lootAmount(loot)
{
}

int Enemy::getXPReward() const { return this->xpReward; }
int Enemy::getLootAmount() const { return this->lootAmount; }
