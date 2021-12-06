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
	shape.setTexture(&deathElementTexture);
}

bool DeathMapElement::isCanDisappear()
{
	return (creationTime + msToDisappear) < getCurrentTime();
}
