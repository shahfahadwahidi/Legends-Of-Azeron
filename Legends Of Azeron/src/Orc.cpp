#include "Orc.h"

Orc::Orc()
    : Enemy("Orc", 50, 2, 10, 3, 50, 25)
{
}

void Orc::attack(Character& player)
{
    cout << this->name << " slams its massive club!" << endl;
    player.takeDamage(this->attackPower + 3);
}

void Orc::useSpecialAbility(Character& player)
{
    cout << this->name << " performs OVERHEAD SMASH!" << endl;
    cout << "Brings the massive club down with full force!" << endl;
    player.takeDamage(this->attackPower * 2);
}
