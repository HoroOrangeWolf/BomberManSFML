#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"

class HealthBar
{
private:
	int healthPoints;
	Direction drawDirect;
	sf::Vector2f position;
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(50.f, 50.f));
	static sf::Texture texture;
public:
	HealthBar(sf::Vector2f position, int healthPoints);
	HealthBar();
	void setHealthPoints(int healthPoints);
	int getHealthPoints();
	void setDrawDirection(Direction direction);
	Direction getDrawDirection();
	void draw(sf::RenderWindow* window);
	static void loadHealthTextureFromFile(std::string path);
};

