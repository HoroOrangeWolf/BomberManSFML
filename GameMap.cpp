#include "GameMap.h"
#include <iostream>

void GameMap::removeInteractiveItem(int x, int y)
{
	std::list<MapElement*>::iterator it = interactiveBlocks.begin();
	for (; it != interactiveBlocks.end(); ++it)
	{
		MapElement* el = *it;
		if (el->getX() == x && el->getY() == y) {
			interactiveBlocks.remove(el);
			return;
		}
 	}

}

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
	element->setX(x);
	element->setY(y);

	if (element->isInteractive()) 
		this->interactiveBlocks.push_back(element);
	

	delete elements[x][y];
	elements[x][y] = element;
}

void GameMap::clearElement(int x, int y)
{
	delete elements[x][y];
	elements[x][y] = NULL;

	this->removeInteractiveItem(x, y);
}

double GameMap::getSingleElementWidth()
{
	return singleElementWidth;
}

double GameMap::getSingleElementHeight()
{
	return singleElementHeight;
}

MapElement* GameMap::getElement(int x, int y)
{
	return elements[x][y];
}

void GameMap::drawMap(sf::RenderWindow* window)
{
	sf::Vector2u sizeWindow = window->getSize();
	singleElementWidth = (double)sizeWindow.x / mapWidthElements,
	singleElementHeight = (double)sizeWindow.y / mapHeightElements;

	

	for(int x = 0; x < mapWidthElements; ++x)
		for (int y = 0; y < mapHeightElements; ++y)
		{
			MapElement* element = getElement(x, y);

			if (element == NULL)
				continue;

			sf::RectangleShape &shape = element->getToDraw();

			shape.setSize(sf::Vector2f(singleElementWidth, singleElementHeight));
			shape.setPosition(sf::Vector2f(singleElementWidth*x, singleElementHeight*y));

			window->draw(shape);
		}
}

sf::Vector2f GameMap::calculatePlayerMovement(Player* player)
{
	std::list<MapElement*>::iterator it = this->interactiveBlocks.begin();
	sf::Vector2f mover = player->getCalculateMove();
	
	for (; it != interactiveBlocks.end(); ++it) {
		MapElement* el = *it;
		sf::FloatRect recta = el->getFloatRect();

		if (mover.x > 0.f && !player->isCanMoveRight(recta))
			mover.x = 0;
		else if (mover.x < 0.f && !player->isCanMoveLeft(recta))
			mover.x = 0;
		else if (mover.y < 0.f && !player->isCanMoveUp(recta))
			mover.y = 0;
		else if (mover.y > 0.f && !player->isCanMoveDown(recta))
			mover.y = 0;

	}

	return mover;
}



