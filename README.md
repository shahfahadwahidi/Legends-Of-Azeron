# ⚔️ Legends of Azeron

> **A console-based RPG battle game built in C++ using Object-Oriented Programming principles.**

**Legends of Azeron** is a command-line role-playing game developed as a C++ group project. The game combines character classes, turn-based combat, enemies, weapons, potions, inventory management, an in-game shop, experience progression, gold rewards, and file-based save/load functionality into a modular RPG system.

The project was designed to demonstrate practical application of **Object-Oriented Programming (OOP)** concepts in C++, including **inheritance, polymorphism, encapsulation, composition, dynamic memory management, exception handling, and file handling**.

---

## 🎮 Overview

In **Legends of Azeron**, players create their own character and choose a class before entering a series of battles against randomly generated enemies.

Players can:

* 🧙 Choose between multiple character classes
* ⚔️ Fight randomly generated enemies
* 🛡️ Use class-specific attacks and abilities
* ⭐ Gain experience and level up
* 💰 Earn gold from defeated enemies
* 🏪 Purchase weapons and potions
* 🎒 Manage a limited-capacity inventory
* ❤️ Restore health and use temporary buffs
* 💾 Save and load game progress
* 📊 View character statistics
* 🐉 Battle different enemy types
* ❌ Handle invalid input and runtime errors

The game is entirely **console-based**, making it focused on gameplay logic and C++ architecture rather than graphical interfaces.

---

## ✨ Features

### 🧑‍🚀 Character Creation

At the beginning of a new game, players enter a character name and select one of three available classes:

| Class        | Starting HP | Playstyle                           | Special Mechanic                    |
| ------------ | ----------: | ----------------------------------- | ----------------------------------- |
| ⚔️ Warrior   |         120 | High durability and physical damage | 30% chance to deal double damage    |
| 🔮 Mage      |          70 | High magical damage                 | Magic attacks deal amplified damage |
| 🗡️ Assassin |          80 | Fast, critical-hit focused          | 40% chance for critical strikes     |

The three classes inherit from the common `Player` class and override their combat behavior using polymorphism.

---

## ⚔️ Turn-Based Combat

Combat is handled through a dedicated `BattleSystem` class.

Each battle follows a turn-based loop:

```text
Player Turn
     ↓
Enemy Status Check
     ↓
Enemy Turn
     ↓
Player Status Check
     ↓
Repeat Until Someone Is Defeated
```

The battle system keeps track of the total number of battles and resets temporary defensive boosts at the beginning of each round.

### Player Actions

During combat, players can perform actions such as:

* Normal attack
* Special ability
* Use available items
* Defend
* Manage combat resources

Different character classes implement their attacks differently.

### Warrior

The Warrior has high health and a chance to deal double damage with a **Powerful Strike**.

Its special ability is:

> **Whirlwind Slash**

which deals increased damage to the enemy.

### Mage

The Mage has lower health but specializes in magical damage.

Normal attack:

> **Magic Missile**

Special ability:

> **Fireball**

The Mage's special attack deals significantly increased damage.

### Assassin

The Assassin focuses on critical hits and burst damage.

Normal attacks have a **40% critical hit chance**, while its special ability is:

> **Shadow Clone Attack**

which deals amplified damage.

---

## 👹 Enemy System

Enemies are generated randomly during gameplay.

The current game includes:

* 👺 Goblin
* 🪓 Orc
* 🐉 Dragon

Whenever the player chooses **Fight Enemy**, the `GameManager` randomly selects one of the three enemy types.

### Goblin

The Goblin is a relatively weak enemy with a basic attack and an **Ambush** special ability.

### Orc

The Orc provides a stronger combat challenge than the Goblin.

### Dragon

The Dragon is the strongest enemy currently implemented.

It has an **Enraged** state: when its health drops below 50%, its attack damage is doubled.

Its special ability is:

> **Inferno Breath**

which deals heavy damage to the player.

---

## ⭐ Progression System

Winning battles rewards the player with:

* **XP**
* **Gold**

The reward is determined by the defeated enemy.

The game manager awards XP and gold after a successful battle, allowing the player to progress and improve their character.

The player's progression data includes:

* Character name
* Class
* Level
* Health
* XP
* Gold

---

## 🎒 Inventory System

The project includes a dedicated `Inventory` class for managing player items.

The inventory supports:

* Weapons
* Potions
* Capacity limits
* Adding items
* Removing/using items
* Inventory display
* Memory cleanup

The inventory tracks weapons and potions separately while enforcing an overall capacity limit.

This provides a practical example of **composition**, where a player owns and manages an inventory containing other objects.

---

## ⚔️ Weapon System

Weapons are represented using a dedicated `Weapon` class.

Weapons contain properties such as:

* Weapon name
* Damage
* Rarity
* Weapon type
* Critical-hit chance
* Special damage
* Price

The shop currently contains several weapon tiers:

### Common

* Sword
* Dagger
* Bow

### Rare

* Battle Axe
* Poison Dagger
* Fire Sword
* Magic Staff

### Legendary

* Legendary Blade

Weapons can be purchased using gold and added to the player's inventory, provided the player has enough gold and inventory space.

---

## 🧪 Potion System

Potions are implemented through the `Potion` class.

Each potion stores:

* Potion type
* Potion name
* Restore amount
* Duration
* Gold price

Available potion types include:

* ❤️ Health Potion
* ❤️ Mega Health Potion
* 💙 Mana Potion
* 💪 Strength Potion
* 🛡️ Defense Potion
* 🎯 Critical Potion
* 🔄 Revive Potion

Some potions provide immediate restoration while others represent temporary combat buffs.

---

## 🏪 Shop System

The game includes a dedicated shop where players can spend their earned gold.

The shop provides two primary purchasing categories:

```text
SHOP
├── Weapons
└── Potions
```

Before completing a purchase, the game checks:

1. Whether the selected item exists
2. Whether the player has enough gold
3. Whether the inventory has available space

Successful purchases deduct gold and create an appropriate item for the player's inventory.

---

## 💾 Save & Load System

Game progress can be saved to a local text file:

```text
savegame.txt
```

The `SaveManager` class handles both saving and loading.

The save system records information such as:

```text
Character Class
Character Name
Level
Health
XP
Gold
```

When loading a game, the system determines the saved class and reconstructs the appropriate `Warrior`, `Mage`, or `Assassin` object before restoring its saved statistics.

This demonstrates practical use of:

* File I/O
* Serialization-style data storage
* Runtime type identification
* Object reconstruction
* Exception handling

---

## 🕹️ Game Flow

The main menu provides three options:

```text
=====================================
 LEGENDS OF AZERON - Main Menu
=====================================
1. Start New Game
2. Load Game
3. Exit
=====================================
```

After creating or loading a character, the player enters the main game loop:

```text
=== GAME MENU ===

1. Fight Enemy
2. View Stats
3. View Inventory
4. Visit Shop
5. Use Gold Features
6. Save Game
7. Exit Game
```

These options allow the player to manage their character and progress through the game.

---

# 🧠 Object-Oriented Programming

One of the primary goals of this project was to apply C++ OOP concepts to a practical game system.

## Inheritance

The project uses inheritance to create specialized characters and enemies.

### Player hierarchy

```text
Character
   │
   └── Player
        ├── Warrior
        ├── Mage
        └── Assassin
```

### Enemy hierarchy

```text
Character
   │
   └── Enemy
        ├── Goblin
        ├── Orc
        └── Dragon
```

This structure allows shared properties and behavior to exist in base classes while specialized classes implement their own combat mechanics.

---

## Polymorphism

Combat behavior is customized by derived classes.

For example:

```cpp
void attack(Character& enemy);
void useSpecialAbility(Character& enemy);
```

Different classes provide their own implementations of these functions.

This allows the battle system to interact with a `Character` or `Player` object without needing to know the exact derived class.

---

## Encapsulation

Game data such as:

* Health
* Attack power
* XP
* Gold
* Weapon properties
* Potion properties

is managed through class interfaces and member functions rather than being accessed directly throughout the entire program.

This keeps individual systems modular and easier to maintain.

---

## Composition

The project uses composition to connect multiple game systems.

For example:

```text
Player
 ├── Inventory
 │    ├── Weapons
 │    └── Potions
 │
 └── Character Statistics
```

The `GameManager` also coordinates major systems such as:

```text
GameManager
 ├── BattleSystem
 ├── SaveManager
 └── Shop
```

---

## Dynamic Memory Management

The project makes extensive use of dynamic allocation with C++ pointers.

Examples include dynamically creating:

* Players
* Enemies
* Weapons
* Potions
* Shop objects

The project also includes destructors that clean up dynamically allocated resources, particularly in systems such as `Inventory` and `Shop`.

---

## Exception Handling

The game validates user input and uses C++ exception handling to prevent invalid selections from crashing the application.

Examples include:

* Invalid menu choices
* Invalid class selections
* Missing save files
* Invalid save-file formats
* Failed file operations

The main game entry point also catches unexpected exceptions and reports the error instead of terminating silently.

---

# 🗂️ Project Structure

```text
Legends-Of-Azeron/
│
├── main.cpp
│
├── Character.h
├── Character.cpp
│
├── Player.h
├── Player.cpp
│
├── Warrior.h
├── Warrior.cpp
├── Mage.h
├── Mage.cpp
├── Assassin.h
├── Assassin.cpp
│
├── Enemy.h
├── Enemy.cpp
├── Goblin.h
├── Goblin.cpp
├── Orc.h
├── Orc.cpp
├── Dragon.h
├── Dragon.cpp
│
├── BattleSystem.h
├── BattleSystem.cpp
│
├── Inventory.h
├── Inventory.cpp
│
├── Weapon.h
├── Weapon.cpp
│
├── Potion.h
├── Potion.cpp
│
├── Shop.h
├── Shop.cpp
│
├── SaveManager.h
├── SaveManager.cpp
│
├── GameManager.h
├── GameManager.cpp
│
├── savegame.txt
│
├── compile.bat
├── compile.sh
│
└── README.md
```

The repository also currently contains precompiled Windows executables such as `game.exe` and `SaveManager.exe`.

---

# 🛠️ Technologies Used

| Technology                      | Purpose                                          |
| ------------------------------- | ------------------------------------------------ |
| **C++**                         | Core programming language                        |
| **Object-Oriented Programming** | Game architecture                                |
| **Standard Library**            | Input/output, strings, exceptions, file handling |
| **File I/O**                    | Save/load functionality                          |
| **Dynamic Memory**              | Runtime object creation                          |
| **Randomization**               | Random enemy generation and combat mechanics     |
| **Shell / Batch Scripts**       | Automated compilation                            |

---

# 💻 Requirements

To compile the project from source, you need:

* A C++ compiler with `g++`
* C++ standard library support
* Terminal / Command Prompt
* Git (recommended)

The repository already includes separate compilation scripts for Windows and Unix-like environments.

---

# 🚀 Installation

## 1. Clone the Repository

```bash
git clone https://github.com/shahfahadwahidi/Legends-Of-Azeron.git
```

Move into the project directory:

```bash
cd Legends-Of-Azeron
```

---

# 🪟 Windows

If `g++` is installed and available in your PATH, you can use the included batch script:

```cmd
compile.bat
```

The script compiles all required `.cpp` files into:

```text
game.exe
```

and automatically launches the game after successful compilation.

### Manual compilation

You can also compile manually:

```cmd
g++ -o game.exe main.cpp Character.cpp Player.cpp Warrior.cpp Mage.cpp Assassin.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp BattleSystem.cpp SaveManager.cpp GameManager.cpp Weapon.cpp Potion.cpp Inventory.cpp Shop.cpp
```

Then run:

```cmd
game.exe
```

---

# 🐧 Linux / macOS

The repository includes a shell script:

```bash
chmod +x compile.sh
./compile.sh
```

The script compiles the complete project and launches the resulting executable.

### Manual compilation

```bash
g++ -o game main.cpp Character.cpp Player.cpp Warrior.cpp Mage.cpp Assassin.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp BattleSystem.cpp SaveManager.cpp GameManager.cpp Weapon.cpp Potion.cpp Inventory.cpp Shop.cpp
```

Run the game:

```bash
./game
```

---

# 🎯 How to Play

### Step 1 — Start the Game

Select:

```text
1. Start New Game
```

### Step 2 — Create Your Character

Enter a character name and select:

```text
1. Warrior
2. Mage
3. Assassin
```

### Step 3 — Enter the Game

You can now:

* Fight enemies
* Check your statistics
* Manage your inventory
* Buy equipment
* Use gold-related features
* Save your progress

### Step 4 — Fight

Choose **Fight Enemy**.

An enemy is randomly selected:

```text
Goblin
   OR
Orc
   OR
Dragon
```

Defeat the enemy to receive XP and gold.

### Step 5 — Upgrade

Use your gold in the shop to purchase stronger weapons and useful potions.

### Step 6 — Save

Select:

```text
6. Save Game
```

Your character information will be written to `savegame.txt`.

---

# 📊 System Architecture

A simplified view of the game's architecture:

```text
                    ┌──────────────┐
                    │    main.cpp  │
                    └───────┬──────┘
                            │
                            ▼
                    ┌──────────────┐
                    │ GameManager  │
                    └──────┬───────┘
                           │
          ┌────────────────┼────────────────┐
          │                │                │
          ▼                ▼                ▼
   ┌─────────────┐  ┌─────────────┐  ┌─────────────┐
   │ BattleSystem│  │    Shop     │  │ SaveManager │
   └──────┬──────┘  └──────┬──────┘  └─────────────┘
          │                │
          ▼                ▼
   ┌─────────────┐  ┌─────────────┐
   │ Characters  │  │   Items     │
   └──────┬──────┘  └──────┬──────┘
          │                │
     ┌────┴────┐       ┌───┴────┐
     │         │       │        │
     ▼         ▼       ▼        ▼
  Player     Enemy   Weapon   Potion
     │         │
 ┌───┼───┐ ┌───┼──────┐
 ▼   ▼   ▼ ▼   ▼      ▼
Warrior Mage Assassin Goblin Orc Dragon
```

---

# 🔮 Future Improvements

The current version provides a solid foundation for a larger RPG. Possible future improvements include:

* 🎨 Graphical user interface
* 🗺️ World exploration
* 📜 Story-driven quests
* 🏰 Multiple areas and dungeons
* 🧙 More character classes
* 👹 Additional enemy types
* 🧰 More equipment categories
* 📈 More advanced leveling mechanics
* 🪙 Expanded economy
* 🎯 More sophisticated combat mechanics
* 💾 More complete save-state serialization
* 🎵 Sound and music
* 🖼️ 2D or 3D graphics
* 🤖 More advanced enemy AI
* 🏆 Achievements and progression tracking

---

# 📚 What This Project Demonstrates

**Legends of Azeron** was created as a practical demonstration of C++ programming and Object-Oriented Design.

The project demonstrates experience with:

* C++ class design
* Header/source separation
* Inheritance
* Polymorphism
* Encapsulation
* Composition
* Constructors and destructors
* Virtual behavior
* Dynamic memory allocation
* Pointers and references
* File input/output
* Exception handling
* Random number generation
* Modular system design
* Game-state management
* Console-based UI
* Multi-class application architecture

---

# 👥 Project Type

**Academic Group Project**

Developed as a C++ Object-Oriented Programming project with a focus on applying classroom concepts to a complete interactive application.

---

# 📌 Project Status

🟢 **Playable**

The current repository contains the core gameplay loop, multiple player and enemy classes, combat, inventory, shop, progression, and save/load functionality.

The project is primarily intended as an **educational C++ RPG project** and a demonstration of Object-Oriented Programming concepts.

---

# 📄 License

This project is provided for educational and portfolio purposes.

If you plan to reuse, modify, or redistribute the project, please check the repository's current licensing information and respect any applicable third-party intellectual property.

---

# 👨‍💻 Author

**Shah Fahad Wahidi**

Software Engineering Student
IMSciences, Peshawar

GitHub: [@shahfahadwahidi](https://github.com/shahfahadwahidi)

---

## ⭐ Support the Project

If you found **Legends of Azeron** interesting or useful, consider giving the repository a ⭐ on GitHub.

> *Choose your class. Sharpen your weapon. Enter the arena. Become a Legend of Azeron.*
