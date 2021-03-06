#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <sstream>
#include "MapElement.h"
#include "Player.h"
#include "Bomb.h"
#include "DeathMapElement.h"
#include "Apple.h"
#include "Chest.h"
#include "SoundModule.h"
#include "EndGameScreen.h"

class GameMap
{
private:
	int mapWidthElements, mapHeightElements;
	MapElement ***elements;
	double singleElementWidth, singleElementHeight;
	std::list<MapElement*> interactiveBlocks;
	std::vector<Bomb*> bombs;
	std::vector<DeathMapElement*> deathMapElements;
	std::vector<Player*> players;
	std::vector<Apple*> apples;
	void removeInteractiveItem(int x, int y);
public:
	GameMap(int mapWidthElements, int mapHeightElements);
	~GameMap();

	void addBomb(Bomb* bomb);
	void addPlayer(Player& player);
	void clearPlayers();

	bool gameCycle(sf::RenderWindow *window);

	void setUpPlayers(sf::RenderWindow* window);

	void setElement(int x, int y, MapElement *element);
	void clearElement(int x, int y);
	double getSingleElementWidth();
	double getSingleElementHeight();
	MapElement* getElement(int x, int y);
	void drawMap(sf::RenderWindow* window);
	sf::Vector2f calculatePlayerMovement(Player* player);

	static GameMap loadMapFromFile(std::string path);


};

