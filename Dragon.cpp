#include "Dragon.h"

Dragon::Dragon()
    : Enemy("Dragon", 150, 5, 25, 8, 200, 100)
{
}

void Dragon::attack(Character& player)
{
    cout << this->name << " takes a deep breath..." << endl;
    
    // Dragon becomes stronger when below 50% HP
    if (this->health < this->maxHealth / 2)
    {
        cout << this->name << " is ENRAGED! Attacks with fury!" << endl;
        player.takeDamage(this->attackPower * 2);
    }
    else
    {
        cout << this->name << " breathes flames!" << endl;
        player.takeDamage(this->attackPower);
    }
}

void Dragon::useSpecialAbility(Character& player)
{
    cout << this->name << " unleashes INFERNO BREATH!" << endl;
    cout << "Engulfs the area in scorching flames!" << endl;
    player.takeDamage(this->attackPower * 3);
}
