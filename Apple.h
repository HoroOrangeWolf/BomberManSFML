#pragma once
#include "MapElement.h"
class Apple :
    public MapElement
{
private:
    int power = 0;
public:
    Apple(int power) {
        this->power = power;
        this->shape.setFillColor(sf::Color::Magenta);
    }
    void setPower(int power);
    int getPower();

};

