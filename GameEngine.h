#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameMap.h"
#include "Logger.h"
#include <vector>

using namespace sf;

class GameEngine
{
private:
	Color color;
	RenderWindow *window;
	GameMap *map = NULL;
	std::vector<Player*> playerList;
	int fps = 60;
	auto getCurrentTime();
	sf::RectangleShape shape;
	sf::Texture texture;
public:
	GameEngine(std::string title, int width, int height);
	void addPlayer(Player& player);
	void clearPlayers();
	void setFps(int fps);
	void setGameMap(GameMap& map);

	void run();

	RenderWindow* getWindow();
	
};

