#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include "Player.h"
#include "Warrior.h"
#include "Mage.h"
#include "Assassin.h"
#include <string>
#include <fstream>

using namespace std;

class SaveManager
{
private:
    string saveFilePath;

public:
    SaveManager(string path = "savegame.txt");
    
    // File handling
    void saveGame(Player* player);
    Player* loadGame();
    bool fileExists() const;
    void deleteSaveFile();
    
    // Utility
    void displaySaveInfo() const;
};

#endif
