#include "Player.h"
#include "Inventory.h"
#include "Potion.h"

Player::Player(string name, int health, int level, int attackPower, int defense)
    : Character(name, health, level, attackPower, defense),
      xp(0), xpToNextLevel(100), gold(0), inventory(new Inventory(20))
{
}

Player::~Player()
{
    if (inventory != nullptr)
        delete inventory;
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
    cout << this->name << " gained " << amount << " gold!" << endl;
}

void Player::spendGold(int amount)
{
    if (this->gold >= amount)
    {
        this->gold -= amount;
        return;
    }
    else
    {
        cout << "Not enough gold! You have " << this->gold << " gold." << endl;
    }
}

int Player::getXP() const { return this->xp; }
int Player::getGold() const { return this->gold; }

void Player::setXP(int x) { this->xp = (x < 0) ? 0 : x; }
void Player::setGold(int g) { this->gold = (g < 0) ? 0 : g; }

bool Player::operator>(const Player& other) const
{
    return this->level > other.level;
}

// ===== POTION FUNCTIONS =====
void Player::useHealthPotion()
{
    if (inventory->getPotionCount() == 0)
    {
        cout << "You have no potions in your inventory!" << endl;
        return;
    }
    
    inventory->displayPotions();
    int choice;
    cout << "Select potion to use (0 to cancel): ";
    cin >> choice;
    
    if (choice <= 0 || choice > inventory->getPotionCount())
    {
        if (choice != 0)
            cout << "Invalid choice!" << endl;
        return;
    }
    
    Potion* potion = inventory->getPotion(choice - 1);
    if (potion != nullptr)
    {
        this->health += potion->getRestoreAmount();
        if (this->health > this->maxHealth)
            this->health = this->maxHealth;
        
        cout << "\n" << this->name << " used " << potion->getPotionType() << " Potion!" << endl;
        cout << "Restored " << potion->getRestoreAmount() << " HP!" << endl;
        cout << "Current HP: " << this->health << "/" << this->maxHealth << endl;
        
        inventory->removePotion(choice - 1);
    }
}

void Player::useManaPotion()
{
    cout << "Mana potions coming soon!" << endl;
}

void Player::displayInventory() const
{
    if (inventory != nullptr)
        inventory->displayInventory();
}

void Player::displayPotions() const
{
    if (inventory != nullptr)
        inventory->displayPotions();
}

Inventory* Player::getInventory() const
{
    return inventory;
}
