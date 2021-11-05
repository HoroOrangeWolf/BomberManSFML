#include "DeathMapElement.h"

DeathMapElement::DeathMapElement()
{
	this->msToDisappear = 5000L;
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

bool DeathMapElement::isCanDisappear()
{
	return (creationTime + msToDisappear) < getCurrentTime();
}
