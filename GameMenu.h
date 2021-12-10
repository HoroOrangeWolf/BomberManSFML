#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include "MenuStates.h"
#include "Button.h"
#include "GameEngine.h"
#include "LevelMenu.h"
#include "Logger.h"

class GameMenu
{
protected:
	sf::RenderWindow* window;
	sf::RectangleShape background;
	sf::Texture texture;
	bool isMouseIn(Button& shape);
	auto getCurrentTime();
public:
	GameMenu(sf::RenderWindow *window);
	virtual MenuStates run();
};

