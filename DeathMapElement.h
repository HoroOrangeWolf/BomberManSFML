#pragma once
#include "MapElement.h"
class DeathMapElement :
    public MapElement
{
private:
    long long msToDisappear;
    long long creationTime;
    sf::Texture deathElementTexture;
public:
    DeathMapElement();
    DeathMapElement(long msToDisappear);
    void setMsToDisappear(long msToDisappear);
    void setTexture(std::string path);

    bool isCanDisappear();
};

