#include "SaveManager.h"
#include <iostream>
#include <cstdio>

SaveManager::SaveManager(string path)
    : saveFilePath(path)
{
}

void SaveManager::saveGame(Player* player)
{
    if (player == nullptr)
    {
        throw runtime_error("Cannot save: Player is null!");
    }
    
    ofstream saveFile(saveFilePath);
    
    if (!saveFile.is_open())
    {
        throw runtime_error("Cannot open save file for writing!");
    }
    
    // Determine player class type
    int classType = 0;
    if (dynamic_cast<Warrior*>(player)) classType = 1;
    else if (dynamic_cast<Mage*>(player)) classType = 2;
    else if (dynamic_cast<Assassin*>(player)) classType = 3;
    
    // Save player data: class, name, level, health, xp, gold, maxHealth
    saveFile << classType << endl;
    saveFile << player->getName() << endl;
    saveFile << player->getLevel() << endl;
    saveFile << player->getHealth() << endl;
    saveFile << player->getXP() << endl;
    saveFile << player->getGold() << endl;
    
    saveFile.close();
    cout << "\n*** Game saved successfully! ***" << endl;
}

Player* SaveManager::loadGame()
{
    ifstream loadFile(saveFilePath);
    
    if (!loadFile.is_open())
    {
        throw runtime_error("Save file not found!");
    }
    
    try
    {
        int classType;
        string name;
        int level, health, xp, gold;
        
        loadFile >> classType;
        loadFile.ignore();  // Ignore newline after classType
        getline(loadFile, name);
        loadFile >> level >> health >> xp >> gold;
        
        loadFile.close();
        
        if (classType < 1 || classType > 3)
        {
            throw runtime_error("Invalid save file format!");
        }
        
        // Recreate player based on class type
        Player* player = nullptr;
        
        switch (classType)
        {
            case 1:
                player = new Warrior(name);
                break;
            case 2:
                player = new Mage(name);
                break;
            case 3:
                player = new Assassin(name);
                break;
        }
        
        // Restore player stats
        if (player != nullptr)
        {
            // Set level (this will adjust health/attack/defense based on level)
            for (int i = 1; i < level; i++)
            {
                player->levelUp();
            }
            
            // Restore health and gold directly
            player->setHealth(health);
            player->setGold(gold);
            player->setXP(xp);
            
            cout << "\n*** Game loaded successfully! ***" << endl;
        }
        
        return player;
    }
    catch (const exception& e)
    {
        throw runtime_error("Error loading save file: " + string(e.what()));
    }
}

bool SaveManager::fileExists() const
{
    ifstream file(saveFilePath);
    bool exists = file.good();
    file.close();
    return exists;
}

void SaveManager::deleteSaveFile()
{
    if (fileExists())
    {
        remove(saveFilePath.c_str());
        cout << "Save file deleted!" << endl;
    }
}

void SaveManager::displaySaveInfo() const
{
    if (fileExists())
    {
        cout << "Save file found at: " << saveFilePath << endl;
        
        // Try to display some info
        ifstream loadFile(saveFilePath);
        if (loadFile.is_open())
        {
            int classType;
            string name;
            int level;
            
            loadFile >> classType;
            loadFile.ignore();
            getline(loadFile, name);
            loadFile >> level;
            
            string classNames[] = {"Unknown", "Warrior", "Mage", "Assassin"};
            cout << "Character: " << name << " (Level " << level << " " 
                 << classNames[classType] << ")" << endl;
            
            loadFile.close();
        }
    }
    else
    {
        cout << "No save file exists." << endl;
    }
}
