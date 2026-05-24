#include "Shop.h"
#include "Player.h"
#include "Inventory.h"

Shop::Shop(string name) : shopName(name)
{
    initializeWeapons();
    initializePotions();
}

Shop::~Shop()
{
    for (auto weapon : availableWeapons)
        delete weapon;
    availableWeapons.clear();

    for (auto potion : availablePotions)
        delete potion;
    availablePotions.clear();
}

void Shop::initializeWeapons()
{
    // COMMON weapons
    availableWeapons.push_back(new Weapon("Sword", 15, "Common", WeaponType::SWORD, 5, 0, 50));
    availableWeapons.push_back(new Weapon("Dagger", 8, "Common", WeaponType::DAGGER, 25, 0, 30));
    availableWeapons.push_back(new Weapon("Bow", 12, "Common", WeaponType::BOW, 10, 0, 45));

    // RARE weapons
    availableWeapons.push_back(new Weapon("Battle Axe", 20, "Rare", WeaponType::AXE, 0, 5, 75));
    availableWeapons.push_back(new Weapon("Poison Dagger", 10, "Rare", WeaponType::POISON_DAGGER, 20, 8, 60));
    availableWeapons.push_back(new Weapon("Fire Sword", 18, "Rare", WeaponType::FIRE_SWORD, 5, 10, 70));
    availableWeapons.push_back(new Weapon("Magic Staff", 16, "Rare", WeaponType::STAFF, 0, 0, 65));

    // LEGENDARY weapons
    availableWeapons.push_back(new Weapon("Legendary Blade", 30, "Legendary", WeaponType::LEGENDARY_BLADE, 15, 15, 150));
}

void Shop::initializePotions()
{
    // Health potions
    availablePotions.push_back(new Potion(PotionType::HEALTH, "Health Potion", 30, 0, 20));
    availablePotions.push_back(new Potion(PotionType::MEGA_HEALTH, "Mega Health Potion", 80, 0, 50));

    // Buff potions
    availablePotions.push_back(new Potion(PotionType::MANA, "Mana Potion", 50, 0, 35));
    availablePotions.push_back(new Potion(PotionType::STRENGTH, "Strength Potion", 10, 1, 40));
    availablePotions.push_back(new Potion(PotionType::DEFENSE, "Defense Potion", 10, 1, 40));
    availablePotions.push_back(new Potion(PotionType::CRITICAL, "Critical Potion", 25, 1, 45));

    // Revive potion
    availablePotions.push_back(new Potion(PotionType::REVIVE, "Revive Potion", 1, 0, 100));
}

void Shop::displayShop() const
{
    cout << "\n======================================" << endl;
    cout << "    Welcome to " << shopName << endl;
    cout << "======================================" << endl;
    displayWeapons();
    displayPotions();
}

void Shop::displayWeapons() const
{
    cout << "\n--- WEAPONS ---" << endl;
    for (size_t i = 0; i < availableWeapons.size(); i++)
    {
        cout << i + 1 << ". ";
        availableWeapons[i]->displayWeapon();
        cout << "   Price: " << availableWeapons[i]->getPrice() << " gold" << endl;
    }
}

void Shop::displayPotions() const
{
    cout << "\n--- POTIONS ---" << endl;
    for (size_t i = 0; i < availablePotions.size(); i++)
    {
        cout << i + 1 << ". ";
        availablePotions[i]->displayPotion();
    }
}

bool Shop::buyWeapon(int index, Player* player)
{
    if (index < 0 || index >= availableWeapons.size())
    {
        cout << "Invalid weapon selection!" << endl;
        return false;
    }

    Weapon* weapon = availableWeapons[index];
    int cost = weapon->getPrice();

    if (player->getGold() < cost)
    {
        cout << "Not enough gold! You have " << player->getGold() 
             << " but need " << cost << endl;
        return false;
    }

    if (player->getInventory()->isFull())
    {
        cout << "Inventory is full! Cannot buy " << weapon->getWeaponName() << endl;
        return false;
    }

    // Purchase successful
    player->setGold(player->getGold() - cost);
    Weapon* newWeapon = new Weapon(weapon->getWeaponName(), weapon->getDamage(), 
                                    weapon->getRarity(), weapon->getWeaponType(),
                                    weapon->getCritChance(), weapon->getSpecialDamage(), cost);
    player->getInventory()->addWeapon(newWeapon);
    cout << "\nSuccessfully bought " << weapon->getWeaponName() << " for " << cost << " gold!" << endl;
    cout << "Remaining gold: " << player->getGold() << endl;
    return true;
}

bool Shop::buyPotion(int index, Player* player)
{
    if (index < 0 || index >= availablePotions.size())
    {
        cout << "Invalid potion selection!" << endl;
        return false;
    }

    Potion* potion = availablePotions[index];
    int cost = potion->getPrice();

    if (player->getGold() < cost)
    {
        cout << "Not enough gold! You have " << player->getGold() 
             << " but need " << cost << endl;
        return false;
    }

    if (player->getInventory()->isFull())
    {
        cout << "Inventory is full! Cannot buy " << potion->getPotionName() << endl;
        return false;
    }

    // Purchase successful
    player->setGold(player->getGold() - cost);
    Potion* newPotion = new Potion(potion->getPotionType(), potion->getPotionName(),
                                     potion->getRestoreAmount(), potion->getDuration(), cost);
    player->getInventory()->addPotion(newPotion);
    cout << "\nSuccessfully bought " << potion->getPotionName() << " for " << cost << " gold!" << endl;
    cout << "Remaining gold: " << player->getGold() << endl;
    return true;
}

int Shop::getWeaponCount() const { return availableWeapons.size(); }
int Shop::getPotionCount() const { return availablePotions.size(); }
Weapon* Shop::getWeapon(int index) const
{
    if (index >= 0 && index < availableWeapons.size())
        return availableWeapons[index];
    return nullptr;
}

Potion* Shop::getPotion(int index) const
{
    if (index >= 0 && index < availablePotions.size())
        return availablePotions[index];
    return nullptr;
}
