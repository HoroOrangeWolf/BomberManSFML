#pragma once

#include <list>
#include "MapElement.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

class GameMap
{
private:
	int mapWidthElements, mapHeightElements;
	MapElement ***elements;
	Player player;
public:
	GameMap(int mapWidthElements, int mapHeightElements);
	void setElement(int x, int y, MapElement *element);
	void clearElement(int x, int y);
	MapElement* getElement(int x, int y);

	void drawMap(sf::RenderWindow* window);


};

