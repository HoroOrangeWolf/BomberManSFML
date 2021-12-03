#pragma once
#include "MapElement.h"
class Chest :
    public MapElement
{
private:
    int power = 0;

public:
    Chest(int power) {
        this->shape.setFillColor(sf::Color::Blue);
        this->power = power;
    }
    void setPower(int power);
    int getPower();
    bool isInteractive() override;

};

