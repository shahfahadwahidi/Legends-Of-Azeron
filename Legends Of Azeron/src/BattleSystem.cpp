#include "BattleSystem.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Initialize static member
int BattleSystem::totalBattles = 0;

BattleSystem::BattleSystem()
{
}

void BattleSystem::startBattle(Character& player, Character& enemy)
{
    cout << "\n================================" << endl;
    cout << "   BATTLE START" << endl;
    cout << "================================" << endl;
    cout << player.getName() << " vs " << enemy.getName() << endl;
    cout << "================================\n" << endl;
    
    totalBattles++;
    
    // Battle loop
    while (player.isAlive() && enemy.isAlive())
    {
        // Reset defense boosts at start of round
        player.resetDefenseBoost();
        enemy.resetDefenseBoost();
        
        playerTurn(player, enemy);
        if (!enemy.isAlive()) break;
        
        enemyTurn(player, enemy);
        if (!player.isAlive()) break;
    }
    
    checkWinner(player, enemy);
}

void BattleSystem::playerTurn(Character& player, Character& enemy)
{
    cout << "\n" << player.getName() << "'s Turn!" << endl;
    cout << player.getName() << " HP: " << player.getHealth() << endl;
    cout << enemy.getName() << " HP: " << enemy.getHealth() << endl;
    
    handlePlayerChoice(player, enemy);
}

void BattleSystem::handlePlayerChoice(Character& player, Character& enemy)
{
    int choice;
    
    cout << "\nChoose your action:" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Special Ability" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;
    
    try
    {
        if (choice < 1 || choice > 3)
            throw runtime_error("Invalid choice! Please try again.");
        
        switch (choice)
        {
            case 1:
                player.attack(enemy);
                break;
            case 2:
                player.defend();
                break;
            case 3:
                player.useSpecialAbility(enemy);
                break;
        }
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
        handlePlayerChoice(player, enemy);  // Ask again
    }
}

void BattleSystem::enemyTurn(Character& player, Character& enemy)
{
    cout << "\n" << enemy.getName() << "'s Turn!" << endl;
    
    // Enemy AI: 30% chance to use special ability
    int action = rand() % 100;
    if (action < 30)
    {
        enemy.useSpecialAbility(player);
    }
    else
    {
        enemy.attack(player);
    }
}

void BattleSystem::checkWinner(Character& player, Character& enemy)
{
    cout << "\n================================" << endl;
    if (player.isAlive())
    {
        cout << "VICTORY! " << player.getName() << " wins!" << endl;
    }
    else
    {
        cout << "DEFEAT! " << player.getName() << " has fallen!" << endl;
    }
    cout << "================================" << endl;
}

int BattleSystem::getTotalBattles()
{
    return totalBattles;
}
