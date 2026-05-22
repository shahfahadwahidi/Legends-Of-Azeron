@echo off
echo Compiling Legends of Azeron...
g++ -o game.exe main.cpp Character.cpp Player.cpp Warrior.cpp Mage.cpp Assassin.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp BattleSystem.cpp SaveManager.cpp GameManager.cpp Inventory.cpp Potion.cpp
echo.
if exist game.exe (
    echo Compilation successful!
    echo.
    echo Running game...
    game.exe
) else (
    echo Compilation failed!
)
pause
