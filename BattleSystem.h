#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Character.h"

class BattleSystem
{
private:
    static int totalBattles;  // Static member

public:
    BattleSystem();
    
    // Main battle functions
    void startBattle(Character& player, Character& enemy);
    void playerTurn(Character& player, Character& enemy);
    void enemyTurn(Character& player, Character& enemy);
    void handlePlayerChoice(Character& player, Character& enemy);
    void checkWinner(Character& player, Character& enemy);
    
    // Static function
    static int getTotalBattles();
};

#endif
