#pragma once
#include "MapElement.h"
#include <chrono>

class Bomb :
    public MapElement
{
private:
    int power;
    long long msToExplode;
    long long creationTime;
public:
    Bomb();
    Bomb(int power, long msToExplode);
    void setPower(int power);
    void setMsToExplode(long msToExplode);
    bool isReadyToExplode();
    int getPower();
};

