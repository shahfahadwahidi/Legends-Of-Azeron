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
    : currentPlayer(nullptr), saveManager("savegame.txt")
{
    srand(time(0));
}

GameManager::~GameManager()
{
    if (this->currentPlayer != nullptr)
        delete this->currentPlayer;
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
        cout << "3. Save Game" << endl;
        cout << "4. Exit Game" << endl;
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
                    }
                    
                    delete enemy;
                    break;
                }
                case 2:
                    this->currentPlayer->displayStats();
                    break;
                case 3:
                    try
                    {
                        saveManager.saveGame(this->currentPlayer);
                    }
                    catch (const exception& e)
                    {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                case 4:
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