#include "GameMap.h"
#include <iostream>

GameMap::GameMap(int mapWidthElements, int mapHeightElements)
{
	this->elements = new MapElement ** [mapWidthElements];

	this->mapWidthElements = mapWidthElements;
	this->mapHeightElements = mapHeightElements;

	for (int i = 0; i < mapWidthElements; ++i) {
		elements[i] = new MapElement * [mapHeightElements];
		std::memset(elements[i], NULL, sizeof(MapElement*)*mapHeightElements);
	}
}

void GameMap::setElement(int x, int y, MapElement *element)
{
	delete elements[x][y];
	elements[x][y] = element;
}

void GameMap::clearElement(int x, int y)
{
	delete elements[x][y];
	elements[x][y] = NULL;
}

MapElement* GameMap::getElement(int x, int y)
{
	return elements[x][y];
}

void GameMap::drawMap(sf::RenderWindow* window)
{
	sf::Vector2u sizeWindow = window->getSize();
	double singleElementWidth = (double)sizeWindow.x / mapWidthElements,
		singleElementHeight = (double)sizeWindow.y / mapHeightElements;

	

	for(int x = 0; x < mapWidthElements; ++x)
		for (int y = 0; y < mapHeightElements; ++y)
		{
			MapElement* element = getElement(x, y);

			if (element == NULL)
				continue;

			sf::RectangleShape shape = element->getToDraw();

			shape.setSize(sf::Vector2f(singleElementWidth, singleElementHeight));
			shape.setPosition(sf::Vector2f(singleElementWidth*x, singleElementHeight*y));

			window->draw(shape);
		}

	player.drawPlayer(singleElementWidth, singleElementHeight, window);
	
}



