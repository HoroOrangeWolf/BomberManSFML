#pragma once
#include "MapElement.h"
class DeathMapElement :
    public MapElement
{
private:
    long msToDisappear;
    long creationTime;
public:
    DeathMapElement();
    DeathMapElement(long msToDisappear);
    void setMsToDisappear(long msToDisappear);
    
    bool isCanDisappear();
};

