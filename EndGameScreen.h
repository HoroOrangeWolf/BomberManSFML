#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Logger.h"


class EndGameScreen
{
public:
	void run(sf::RenderWindow *window,std::string text);
};

