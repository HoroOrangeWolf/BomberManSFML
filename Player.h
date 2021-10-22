#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private: 
	sf::RectangleShape playerModel;
	sf::CircleShape point1,
		point2,
		point3,
		point4,
		point5,
		point6,
		point7,
		point8;

public:
	Player();

	void drawPlayer(double width, double height, sf::RenderWindow* window);

};

