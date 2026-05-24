#include "Assassin.h"
#include <cstdlib>
#include <ctime>

Assassin::Assassin(string name)
    : Player(name, 80, 1, 18, 5)
{
    cout << "Assassin " << name << " has entered the arena!" << endl;
}

void Assassin::attack(Character& enemy)
{
    int damage = this->attackPower;
    
    // 40% chance for critical hit (double damage)
    if (rand() % 100 < 40)
    {
        damage *= 2;
        cout << this->name << " performs a CRITICAL STRIKE!" << endl;
    }
    else
    {
        cout << this->name << " strikes swiftly!" << endl;
    }
    
    enemy.takeDamage(damage);
}

void Assassin::useSpecialAbility(Character& enemy)
{
    int damage = this->attackPower * 2;
    cout << this->name << " executes SHADOW CLONE ATTACK!" << endl;
    cout << "Strikes from multiple angles!" << endl;
    enemy.takeDamage(damage);
}
