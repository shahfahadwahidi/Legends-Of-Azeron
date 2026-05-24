#include "GameManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Assassin.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

GameManager::GameManager()
    : currentPlayer(nullptr), saveManager("savegame.txt"), shop(nullptr)
{
    srand(time(0));
    shop = new Shop();
}

GameManager::~GameManager()
{
    if (this->currentPlayer != nullptr)
        delete this->currentPlayer;
    if (this->shop != nullptr)
        delete this->shop;
}

void GameManager::run()
{
    int choice = 0;
    
    while (choice != 3)
    {
        displayMenu();
        cin >> choice;
        
        try
        {
            if (choice < 1 || choice > 3)
                throw runtime_error("Invalid choice! Please try again.");
            
            if (choice == 1)
            {
                createPlayer();
                if (this->currentPlayer != nullptr)
                {
                    gameLoop();
                    delete this->currentPlayer;
                    this->currentPlayer = nullptr;
                }
            }
            else if (choice == 2)
            {
                try 
                {
                    this->currentPlayer = saveManager.loadGame();
                    if (this->currentPlayer != nullptr)
                    {
                        gameLoop();
                        delete this->currentPlayer;
                        this->currentPlayer = nullptr;
                    }
                }
                catch (const exception& e)
                {
                    cout << "\nError: " << e.what() << endl;
                }
            }
            else if (choice == 3)
            {
                cout << "\nThank you for playing Legends of Azeron!" << endl;
            }
        }
        catch (const exception& e)
        {
            cout << "\nError: " << e.what() << endl;
        }
    }
}

void GameManager::displayMenu()
{
    cout << "\n=====================================" << endl;
    cout << "  LEGENDS OF AZERON - Main Menu" << endl;
    cout << "=====================================" << endl;
    cout << "1. Start New Game" << endl;
    
    if (saveManager.fileExists())
        cout << "2. Load Game" << endl;
    else
        cout << "2. Load Game (No save available)" << endl;
    
    cout << "3. Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Enter choice: ";
}

void GameManager::createPlayer()
{
    string playerName;
    int classChoice;
    
    cout << "\nEnter your character name: ";
    cin >> playerName;
    
    cout << "\nChoose your class:" << endl;
    cout << "1. Warrior (High HP, Strong attacks, 30% chance to double damage)" << endl;
    cout << "2. Mage (Low HP, Powerful magic attacks)" << endl;
    cout << "3. Assassin (40% critical hit chance)" << endl;
    cout << "Enter choice (1-3): ";
    cin >> classChoice;
    
    try
    {
        if (classChoice < 1 || classChoice > 3)
            throw runtime_error("Invalid class choice!");
        
        switch (classChoice)
        {
            case 1:
                this->currentPlayer = new Warrior(playerName);
                break;
            case 2:
                this->currentPlayer = new Mage(playerName);
                break;
            case 3:
                this->currentPlayer = new Assassin(playerName);
                break;
        }
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

void GameManager::gameLoop()
{
    if (this->currentPlayer == nullptr) return;
    
    int choice;
    
    while (this->currentPlayer->isAlive())
    {
        cout << "\n=== GAME MENU ===" << endl;
        cout << "1. Fight Enemy" << endl;
        cout << "2. View Stats" << endl;
        cout << "3. View Inventory" << endl;
        cout << "4. Visit Shop" << endl;
        cout << "5. Use Gold Features" << endl;
        cout << "6. Save Game" << endl;
        cout << "7. Exit Game" << endl;
        cout << "Enter choice (1-7): ";
        cin >> choice;
        
        try
        {
            if (choice < 1 || choice > 7)
                throw runtime_error("Invalid choice!");
            
            switch (choice)
            {
                case 1:
                {
                    // Random enemy type
                    Enemy* enemy;
                    int enemyType = rand() % 3;
                    
                    if (enemyType == 0)
                        enemy = new Goblin();
                    else if (enemyType == 1)
                        enemy = new Orc();
                    else
                        enemy = new Dragon();
                    
                    battleSystem.startBattle(*this->currentPlayer, *enemy);
                    
                    if (this->currentPlayer->isAlive())
                    {
                        this->currentPlayer->gainXP(enemy->getXPReward());
                        this->currentPlayer->addGold(enemy->getLootAmount());
                        cout << "\nYou earned " << enemy->getLootAmount() << " gold!" << endl;
                    }
                    
                    delete enemy;
                    break;
                }
                case 2:
                    this->currentPlayer->displayStats();
                    break;
                case 3:
                    if (this->currentPlayer != nullptr)
                    {
                        this->currentPlayer->displayInventory();
                        cout << "\nYour Gold: " << this->currentPlayer->getGold() << endl;
                    }
                    break;
                case 4:
                    visitShop();
                    break;
                case 5:
                    useGoldFeatures();
                    break;
                case 6:
                    try
                    {
                        saveManager.saveGame(this->currentPlayer);
                    }
                    catch (const exception& e)
                    {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                case 7:
                    cout << "\nExiting game..." << endl;
                    return;
                default:
                    throw runtime_error("Invalid choice!");
            }
        }
        catch (const exception& e)
        {
            cout << "\nError: " << e.what() << endl;
        }
    }
    
    cout << "\n*** GAME OVER! ***" << endl;
    cout << "Your character has been defeated!" << endl;
    cout << "Final Level: " << this->currentPlayer->getLevel() << endl;
    cout << "Total Battles in Game: " << BattleSystem::getTotalBattles() << endl;
}

void GameManager::visitShop()
{
    if (this->currentPlayer == nullptr || this->shop == nullptr)
        return;

    int choice;
    bool shopping = true;

    while (shopping)
    {
        shop->displayShop();
        cout << "\n" << this->currentPlayer->getName() << "'s Gold: " << this->currentPlayer->getGold() << endl;
        cout << "\n--- SHOP MENU ---" << endl;
        cout << "1. Buy Weapon" << endl;
        cout << "2. Buy Potion" << endl;
        cout << "3. Exit Shop" << endl;
        cout << "Enter choice (1-3): ";
        cin >> choice;

        try
        {
            if (choice < 1 || choice > 3)
                throw runtime_error("Invalid choice!");

            switch (choice)
            {
                case 1:
                {
                    cout << "\n--- SELECT WEAPON ---" << endl;
                    shop->displayWeapons();
                    cout << "Enter weapon number (0 to cancel): ";
                    int weaponChoice;
                    cin >> weaponChoice;

                    if (weaponChoice > 0 && weaponChoice <= shop->getWeaponCount())
                    {
                        shop->buyWeapon(weaponChoice - 1, this->currentPlayer);
                    }
                    break;
                }
                case 2:
                {
                    cout << "\n--- SELECT POTION ---" << endl;
                    shop->displayPotions();
                    cout << "Enter potion number (0 to cancel): ";
                    int potionChoice;
                    cin >> potionChoice;

                    if (potionChoice > 0 && potionChoice <= shop->getPotionCount())
                    {
                        shop->buyPotion(potionChoice - 1, this->currentPlayer);
                    }
                    break;
                }
                case 3:
                    cout << "\nLeaving shop..." << endl;
                    shopping = false;
                    break;
                default:
                    throw runtime_error("Invalid choice!");
            }
        }
        catch (const exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void GameManager::useGoldFeatures()
{
    if (this->currentPlayer == nullptr)
        return;

    int choice;
    bool using_features = true;

    while (using_features)
    {
        cout << "\n========== GOLD FEATURES ==========" << endl;
        cout << "Current Gold: " << this->currentPlayer->getGold() << endl;
        cout << "=====================================" << endl;
        cout << "1. Heal using Gold (20 gold = +30 HP)" << endl;
        cout << "2. Upgrade Weapon (50 gold)" << endl;
        cout << "3. Expand Inventory (100 gold = +5 slots)" << endl;
        cout << "4. Back to Game" << endl;
        cout << "Enter choice (1-4): ";
        cin >> choice;

        try
        {
            if (choice < 1 || choice > 4)
                throw runtime_error("Invalid choice!");

            switch (choice)
            {
                case 1:
                {
                    if (this->currentPlayer->healWithGold(20, 30))
                    {
                        cout << "Successfully healed!" << endl;
                    }
                    break;
                }
                case 2:
                {
                    if (this->currentPlayer->upgradeWeaponWithGold(50))
                    {
                        cout << "Successfully upgraded weapon!" << endl;
                    }
                    break;
                }
                case 3:
                {
                    if (this->currentPlayer->expandInventoryWithGold(100))
                    {
                        cout << "Successfully expanded inventory by 5 slots!" << endl;
                    }
                    break;
                }
                case 4:
                    cout << "\nReturning to game..." << endl;
                    using_features = false;
                    break;
                default:
                    throw runtime_error("Invalid choice!");
            }
        }
        catch (const exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}