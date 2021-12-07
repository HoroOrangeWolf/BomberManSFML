#pragma once
#include "GameMenu.h"
#include "MenuStates.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class LevelMenu :
    public GameMenu
{
private:
    
public:
    LevelMenu(sf::RenderWindow* window) :GameMenu(window) {};
    MenuStates run() override;
};

