#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameMap.h"

using namespace sf;

class GameEngine
{
private:
	Color color;
	RenderWindow *window;
	Player* player1 = NULL;
	Player* player2 = NULL;
	GameMap *map = NULL;
	int fps = 60;
	auto getCurrentTime();
public:
	void setBackGroundColor(Color color);
	GameEngine(std::string title, int width, int height);
	void setPlayer1(Player& player);
	void setPlayer2(Player& player);
	void setFps(int fps);
	void setGameMap(GameMap& map);

	void run();

	RenderWindow* getWindow();
	
};

