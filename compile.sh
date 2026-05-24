#!/bin/bash
echo "Compiling Legends of Azeron..."
g++ -o game main.cpp Character.cpp Player.cpp Warrior.cpp Mage.cpp Assassin.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp BattleSystem.cpp SaveManager.cpp GameManager.cpp Weapon.cpp Potion.cpp Inventory.cpp Shop.cpp

if [ -f game ]; then
    echo "Compilation successful!"
    echo ""
    echo "Running game..."
    ./game
else
    echo ""
    echo "Compilation failed!"
fi
