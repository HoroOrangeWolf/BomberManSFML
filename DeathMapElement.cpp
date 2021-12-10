#include "DeathMapElement.h"

DeathMapElement::DeathMapElement()
{
	this->msToDisappear = 1500L;
	this->creationTime = getCurrentTime();
}

DeathMapElement::DeathMapElement(long msToDisappear)
{
	this->msToDisappear = msToDisappear;
	this->creationTime = getCurrentTime();
}

void DeathMapElement::setMsToDisappear(long msToDisappear)
{
	this->msToDisappear = msToDisappear;
}

void DeathMapElement::setTexture(std::string path)
{
	deathElementTexture.loadFromFile(path);
	if (!deathElementTexture.loadFromFile(path))
		Logger::log("Nie uda³o siê za³adowaæ Bomb");
	shape.setTexture(&deathElementTexture);
}

bool DeathMapElement::isCanDisappear()
{
	return (creationTime + msToDisappear) < getCurrentTime();
}
