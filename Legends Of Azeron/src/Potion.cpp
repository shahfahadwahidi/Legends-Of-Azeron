#include "Potion.h"

Potion::Potion(string type, int amount)
    : potionType(type), restoreAmount(amount)
{
}

string Potion::getPotionType() const { return potionType; }
int Potion::getRestoreAmount() const { return restoreAmount; }

void Potion::displayPotion() const
{
    cout << "Potion: " << potionType << " | Restores: " << restoreAmount << endl;
}
