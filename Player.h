#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Player
{
private: 
	sf::RectangleShape playerModel;
	std::pair<sf::Keyboard::Key, sf::Vector2f> up;
	std::pair<sf::Keyboard::Key, sf::Vector2f> down;
	std::pair<sf::Keyboard::Key, sf::Vector2f> left;
	std::pair<sf::Keyboard::Key, sf::Vector2f> right;
	
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

