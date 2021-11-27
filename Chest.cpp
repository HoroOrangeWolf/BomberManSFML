#include "Chest.h"

void Chest::setPower(int power)
{
    this->power = power;
}

int Chest::getPower()
{
    return power;
}

bool Chest::isInteractive()
{
    return true;
}
