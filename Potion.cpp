#include "Potion.h"

Potion::Potion(string type, string name, int amount, int dur, int goldPrice)
    : potionType(type), potionName(name), restoreAmount(amount), duration(dur), price(goldPrice)
{
}

string Potion::getPotionType() const { return potionType; }
string Potion::getPotionName() const { return potionName; }
int Potion::getRestoreAmount() const { return restoreAmount; }
int Potion::getDuration() const { return duration; }
int Potion::getPrice() const { return price; }

void Potion::displayPotion() const
{
    cout << "Potion: " << potionName << " | Restores: " << restoreAmount;
    
    if (duration > 0)
        cout << " | Duration: " << duration << " turn(s)";
    
    cout << " | Price: " << price << " gold" << endl;
}
