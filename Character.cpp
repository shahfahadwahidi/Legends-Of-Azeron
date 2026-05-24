#include "Character.h"

Character::Character(string name, int health, int level, int attackPower, int defense)
    : name(name), health(health), maxHealth(health), level(level), 
      attackPower(attackPower), defense(defense), defenseBoost(0)
{
}

void Character::takeDamage(int damage)
{
    int totalDefense = this->defense + this->defenseBoost;
    int actualDamage = max(0, damage - totalDefense);
    this->health -= actualDamage;
    if (this->health < 0) this->health = 0;
    cout << this->name << " takes " << actualDamage << " damage!" << endl;
}

void Character::defend()
{
    this->defenseBoost = 5;  // Temporary +5 defense
    cout << this->name << " takes a defensive stance! Defense +5 for this turn!" << endl;
}

void Character::resetDefenseBoost()
{
    this->defenseBoost = 0;
}

void Character::displayStats() const
{
    cout << "\n=== " << this->name << " ===" << endl;
    cout << "Level: " << this->level << endl;
    cout << "HP: " << this->health << "/" << this->maxHealth << endl;
    cout << "Attack: " << this->attackPower << endl;
    cout << "Defense: " << this->defense << endl;
}

bool Character::isAlive() const
{
    return this->health > 0;
}

string Character::getName() const { return this->name; }
int Character::getHealth() const { return this->health; }
int Character::getLevel() const { return this->level; }
int Character::getAttackPower() const { return this->attackPower; }
int Character::getDefense() const { return this->defense; }
int Character::getTotalDefense() const { return this->defense + this->defenseBoost; }

void Character::setHealth(int h)
{
    this->health = (h < 0) ? 0 : h;
}
