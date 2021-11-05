#include "DeathMapElement.h"

DeathMapElement::DeathMapElement()
{
	this->msToDisappear = 200;
}

DeathMapElement::DeathMapElement(long msToDisappear)
{
	this->msToDisappear = msToDisappear;
}

void DeathMapElement::setMsToDisappear(long msToDisappear)
{
	this->msToDisappear = msToDisappear;
}

bool DeathMapElement::isCanDisappear()
{
	return (creationTime + msToDisappear) < getCurrentTime();
}
