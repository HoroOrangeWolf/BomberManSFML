#pragma once
#include "MapElement.h"
class Chest :
    public MapElement
{
private:
    int power = 0;
    sf::Texture breakableChest;
public:
    Chest(int power) {
        this->power = power;
        breakableChest.loadFromFile("images/breakable_block.png");
        shape.setTexture(&breakableChest);
    }
    void setPower(int power);
    int getPower();
    bool isInteractive() override;

};

