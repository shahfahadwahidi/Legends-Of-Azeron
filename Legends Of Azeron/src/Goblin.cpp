#include "Goblin.h"

Goblin::Goblin()
    : Enemy("Goblin", 25, 1, 5, 1, 20, 10)
{
}

void Goblin::attack(Character& player)
{
    cout << this->name << " strikes with a rusty blade!" << endl;
    player.takeDamage(this->attackPower);
}

void Goblin::useSpecialAbility(Character& player)
{
    cout << this->name << " performs AMBUSH!" << endl;
    cout << "Tries to catch you off guard!" << endl;
    player.takeDamage(this->attackPower * 2);
}
