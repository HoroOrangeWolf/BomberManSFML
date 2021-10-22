#pragma once
#include <SFML/Graphics.hpp>

class MapElement
{
private:
public:
	virtual sf::RectangleShape& getToDraw();
};

