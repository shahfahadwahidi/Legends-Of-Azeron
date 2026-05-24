#include "Mage.h"

Mage::Mage(string name)
    : Player(name, 70, 1, 8, 3)
{
    cout << "Mage " << name << " has entered the arena!" << endl;
}

void Mage::attack(Character& enemy)
{
    // Mage does lower physical damage but more consistent
    int magicDamage = this->attackPower * 2;
    cout << this->name << " casts a MAGIC MISSILE!" << endl;
    enemy.takeDamage(magicDamage);
}

void Mage::useSpecialAbility(Character& enemy)
{
    int magicDamage = this->attackPower * 3;
    cout << this->name << " unleashes FIREBALL!" << endl;
    cout << "Engulfs " << enemy.getName() << " in flames!" << endl;
    enemy.takeDamage(magicDamage);
}
