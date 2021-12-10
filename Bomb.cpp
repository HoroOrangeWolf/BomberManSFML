#include "Bomb.h"
Bomb::Bomb()
{
	this->creationTime = getCurrentTime();
	this->power = 1;
	this->msToExplode = 1500L;
	if (!texture.loadFromFile("images/bomba.png"))
		Logger::log("Nie uda³o siê za³adowaæ Bomb");
	shape.setTexture(&texture);
}

Bomb::Bomb(int power, long msToExplode)
{
	this->creationTime = getCurrentTime();
	this->power = power;
	this->msToExplode = msToExplode;
	if (!texture.loadFromFile("images/bomba.png"))
		Logger::log("Nie uda³o siê za³adowaæ Bomb");
	shape.setTexture(&texture);
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
