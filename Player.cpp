#include "Player.h"
#include "Inventory.h"

Player::Player(string name, int health, int level, int attackPower, int defense)
    : Character(name, health, level, attackPower, defense),
      xp(0), xpToNextLevel(100), gold(0), inventory(nullptr)
{
    inventory = new Inventory(10);  // Default capacity: 10 items
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

// Gold-based features
bool Player::healWithGold(int goldCost, int hpRestore)
{
    if (this->gold >= goldCost)
    {
        this->gold -= goldCost;
        this->health = min(this->health + hpRestore, this->maxHealth);
        cout << this->name << " paid " << goldCost << " gold to restore " 
             << hpRestore << " HP! Current HP: " << this->health << endl;
        return true;
    }
    else
    {
        cout << "Not enough gold! You have " << this->gold << " gold but need " << goldCost << endl;
        return false;
    }
}

bool Player::upgradeWeaponWithGold(int goldCost)
{
    if (this->gold >= goldCost)
    {
        this->gold -= goldCost;
        cout << this->name << " paid " << goldCost << " gold to upgrade a weapon!" << endl;
        return true;
    }
    else
    {
        cout << "Not enough gold! You have " << this->gold << " gold but need " << goldCost << endl;
        return false;
    }
}

bool Player::expandInventoryWithGold(int goldCost)
{
    if (this->gold >= goldCost)
    {
        this->gold -= goldCost;
        this->inventory->expandCapacity(5);
        return true;
    }
    else
    {
        cout << "Not enough gold! You have " << this->gold << " gold but need " << goldCost << endl;
        return false;
    }
}

// Inventory functions
Inventory* Player::getInventory() const { return inventory; }

void Player::displayInventory() const
{
    if (inventory != nullptr)
        inventory->displayInventory();
}

int Player::getXP() const { return this->xp; }
int Player::getGold() const { return this->gold; }

void Player::setXP(int x) { this->xp = (x < 0) ? 0 : x; }
void Player::setGold(int g) { this->gold = (g < 0) ? 0 : g; }

bool Player::operator>(const Player& other) const
{
    return this->level > other.level;
}
