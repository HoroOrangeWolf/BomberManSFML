#pragma once
#include "MapElement.h"
#include <SFML/Graphics.hpp>
#include "Logger.h"

class StaticBlock :
    public MapElement
{
public:
    virtual sf::RectangleShape& getToDraw();
    virtual bool isInteractive() override;
    StaticBlock();
private:
    sf::Texture unbreakableBlockTexture;
};

