#pragma once
#include "MapElement.h"
class DeathMapElement :
    public MapElement
{
private:
    long long msToDisappear;
    long long creationTime;
public:
    DeathMapElement();
    DeathMapElement(long msToDisappear);
    void setMsToDisappear(long msToDisappear);
    
    bool isCanDisappear();
};

