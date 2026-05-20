#include "Player.h"

Player::Player(string name, int health, int level, int attackPower, int defense)
    : Character(name, health, level, attackPower, defense),
      xp(0), xpToNextLevel(100), gold(0)
{
}

void Player::gainXP(int amount)
{
    this->xp += amount;
    cout << this->name << " gained " << amount << " XP!" << endl;
    
    if (this->xp >= this->xpToNextLevel)
    {
        levelUp();
    }
}

void Player::levelUp()
{
    this->level++;
    this->xp = 0;
    this->xpToNextLevel = 100 * this->level;
    this->attackPower += 5;
    this->defense += 2;
    this->health = this->maxHealth;
    cout << "\n*** LEVEL UP! " << this->name << " is now level " << this->level << "! ***\n" << endl;
}

void Player::addGold(int amount)
{
    this->gold += amount;
}

int Player::getXP() const { return this->xp; }
int Player::getGold() const { return this->gold; }

void Player::setXP(int x) { this->xp = (x < 0) ? 0 : x; }
void Player::setGold(int g) { this->gold = (g < 0) ? 0 : g; }

bool Player::operator>(const Player& other) const
{
    return this->level > other.level;
}
