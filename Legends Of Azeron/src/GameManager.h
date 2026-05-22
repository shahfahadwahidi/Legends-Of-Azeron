#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "BattleSystem.h"
#include "SaveManager.h"

using namespace std;

class GameManager
{
private:
    Player* currentPlayer;
    BattleSystem battleSystem;
    SaveManager saveManager;

public:
    GameManager();
    ~GameManager();

    void run();

private:
    void displayMenu();
    void createPlayer();
    void gameLoop();
    void visitPotionShop();
};

#endif
