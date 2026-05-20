#include "Warrior.h"
#include <cstdlib>
#include <ctime>

Warrior::Warrior(string name)
    : Player(name, 120, 1, 15, 8)
{
    cout << "Warrior " << name << " has entered the arena!" << endl;
}

void Warrior::attack(Character& enemy)
{
    int damage = this->attackPower;
    
    // Warrior has 30% chance to do double damage
    if (rand() % 100 < 30)
    {
        damage *= 2;
        cout << this->name << " performs a POWERFUL STRIKE!" << endl;
    }
    else
    {
        cout << this->name << " attacks with sword!" << endl;
    }
    
    enemy.takeDamage(damage);
}

void Warrior::useSpecialAbility(Character& enemy)
{
    int damage = this->attackPower * 2;
    cout << this->name << " unleashes WHIRLWIND SLASH!" << endl;
    cout << "Hits " << enemy.getName() << " with devastating force!" << endl;
    enemy.takeDamage(damage);
}
