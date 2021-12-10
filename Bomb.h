#pragma once
#include "MapElement.h"
#include <chrono>
#include "Logger.h"

class Bomb :
    public MapElement
{
private:
    int power;
    long long msToExplode;
    long long creationTime;
    sf::Texture texture;
public:
    Bomb();
    Bomb(int power, long msToExplode);
    void setPower(int power);
    void setMsToExplode(long msToExplode);
    bool isReadyToExplode();

    int getPower();

};

