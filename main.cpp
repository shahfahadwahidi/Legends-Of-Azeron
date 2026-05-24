#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
    cout << "========================================" << endl;
    cout << "   LEGENDS OF AZERON - RPG Battle Game" << endl;
    cout << "========================================" << endl;
    cout << "Welcome to your adventure!\n" << endl;
    
    try
    {
        GameManager game;
        game.run();
    }
    catch (const exception& e)
    {
        cout << "Fatal Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
