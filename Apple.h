#pragma once
#include "MapElement.h"
class Apple :
    public MapElement
{
private:
    int power = 0;
    sf::Texture texture;
public:
    Apple(int power) {
        this->power = power;
        texture.loadFromFile("images/powerup.png");
        shape.setTexture(&texture);
    }
    void setPower(int power);
    int getPower();
    bool isInteractive() override;

};

