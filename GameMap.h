#pragma once

#include <vector>
#include "MapElement.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bomb.h"
#include "DeathMapElement.h"

class GameMap
{
private:
	int mapWidthElements, mapHeightElements;
	MapElement ***elements;
	double singleElementWidth, singleElementHeight;
	std::list<MapElement*> interactiveBlocks;
	std::vector<Bomb*> bombs;
	std::vector<DeathMapElement*> deathMapElements;
	void removeInteractiveItem(int x, int y);
public:
	void addBomb(Bomb* bomb);
	void gameCycle();
	GameMap(int mapWidthElements, int mapHeightElements);
	void setElement(int x, int y, MapElement *element);
	void clearElement(int x, int y);
	double getSingleElementWidth();
	double getSingleElementHeight();
	MapElement* getElement(int x, int y);
	void drawMap(sf::RenderWindow* window);
	sf::Vector2f calculatePlayerMovement(Player* player);


};

