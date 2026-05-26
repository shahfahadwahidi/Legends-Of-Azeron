#include "Shop.h"
#include "Player.h"
#include "Inventory.h"

Shop::Shop(string name) : shopName(name), weaponCount(0), potionCount(0)
{
    initializeWeapons();
    initializePotions();
}

Shop::~Shop()
{
    for (int i = 0; i < weaponCount; i++)
        delete availableWeapons[i];

    for (int i = 0; i < potionCount; i++)
        delete availablePotions[i];
}

void Shop::initializeWeapons()
{
    // COMMON weapons
    availableWeapons[weaponCount++] = new Weapon("Sword", 15, "Common", "SWORD", 5, 0, 50);
    availableWeapons[weaponCount++] = new Weapon("Dagger", 8, "Common", "DAGGER", 25, 0, 30);
    availableWeapons[weaponCount++] = new Weapon("Bow", 12, "Common", "BOW", 10, 0, 45);

    // RARE weapons
    availableWeapons[weaponCount++] = new Weapon("Battle Axe", 20, "Rare", "AXE", 0, 5, 75);
    availableWeapons[weaponCount++] = new Weapon("Poison Dagger", 10, "Rare", "POISON_DAGGER", 20, 8, 60);
    availableWeapons[weaponCount++] = new Weapon("Fire Sword", 18, "Rare", "FIRE_SWORD", 5, 10, 70);
    availableWeapons[weaponCount++] = new Weapon("Magic Staff", 16, "Rare", "STAFF", 0, 0, 65);

    // LEGENDARY weapons
    availableWeapons[weaponCount++] = new Weapon("Legendary Blade", 30, "Legendary", "LEGENDARY_BLADE", 15, 15, 150);
}

void Shop::initializePotions()
{
    // Health potions
    availablePotions[potionCount++] = new Potion("HEALTH", "Health Potion", 30, 0, 20);
    availablePotions[potionCount++] = new Potion("MEGA_HEALTH", "Mega Health Potion", 80, 0, 50);

    // Buff potions
    availablePotions[potionCount++] = new Potion("MANA", "Mana Potion", 50, 0, 35);
    availablePotions[potionCount++] = new Potion("STRENGTH", "Strength Potion", 10, 1, 40);
    availablePotions[potionCount++] = new Potion("DEFENSE", "Defense Potion", 10, 1, 40);
    availablePotions[potionCount++] = new Potion("CRITICAL", "Critical Potion", 25, 1, 45);

    // Revive potion
    availablePotions[potionCount++] = new Potion("REVIVE", "Revive Potion", 1, 0, 100);
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
    for (int i = 0; i < weaponCount; i++)
    {
        cout << i + 1 << ". ";
        availableWeapons[i]->displayWeapon();
        cout << "   Price: " << availableWeapons[i]->getPrice() << " gold" << endl;
    }
}

void Shop::displayPotions() const
{
    cout << "\n--- POTIONS ---" << endl;
    for (int i = 0; i < potionCount; i++)
    {
        cout << i + 1 << ". ";
        availablePotions[i]->displayPotion();
    }
}

bool Shop::buyWeapon(int index, Player* player)
{
    if (index < 0 || index >= weaponCount)
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
    if (index < 0 || index >= potionCount)
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

int Shop::getWeaponCount() const { return weaponCount; }
int Shop::getPotionCount() const { return potionCount; }
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
