#pragma once
#include "GameMenu.h"
#include "MenuStates.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class LevelMenu
{
private:
	sf::RenderWindow* window = NULL;
	sf::RectangleShape background;
	sf::Texture texture;
	bool isMouseIn(Button& shape);
	auto getCurrentTime();
public:
	LevelMenu(sf::RenderWindow* window);
    MenuStates run();
};

