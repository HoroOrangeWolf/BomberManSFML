#pragma once
#include "MapElement.h"
#include <SFML/Graphics.hpp>

class StaticBlock :
    public MapElement
{
public:
    virtual sf::RectangleShape& getToDraw();
    virtual bool isInteractive() override;
    

};

