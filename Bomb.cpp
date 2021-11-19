#include "Bomb.h"
#include <iostream>
Bomb::Bomb()
{
	this->creationTime = getCurrentTime();
	this->power = 1;
	this->msToExplode = 5000L;
}

Bomb::Bomb(int power, long msToExplode)
{
	this->creationTime = getCurrentTime();
	this->power = power;
	this->msToExplode = msToExplode;
}


void Bomb::setPower(int power)
{
	this->power = power;
}

void Bomb::setMsToExplode(long msToExplode)
{
	this->msToExplode = msToExplode;
}

bool Bomb::isReadyToExplode()
{
	return (creationTime + msToExplode) < getCurrentTime();
}

int Bomb::getPower()
{
	return power;
}
