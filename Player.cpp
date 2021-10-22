#include "Player.h"

Player::Player()
{
	this->playerModel = sf::RectangleShape(sf::Vector2f(5.f, 5.f));

	playerModel.setPosition(sf::Vector2f(50.f, 50.f));

	this->playerModel.setFillColor(sf::Color::Blue);

	sf::CircleShape shape(2.f);

	shape.setFillColor(sf::Color::Red);

	this->point1 = shape;
	this->point2 = shape;
	this->point3 = shape;
	this->point4 = shape;
	this->point5 = shape;
	this->point6 = shape;
	this->point7 = shape;
	this->point8 = shape;
}

void Player::drawPlayer(double width, double height, sf::RenderWindow* window)
{
	playerModel.setSize(sf::Vector2f(width, height));

	window->draw(playerModel);

	sf::Vector2f pos = playerModel.getPosition();

	point1.setPosition(pos.x + 1.f, pos.y + 1.f);

	point2.setPosition(pos.x + width/2, pos.y + 1.f);

	point3.setPosition(pos.x + width - 4.f, pos.y + 1.f);

	point4.setPosition(pos.x + width - 4.f, pos.y + height/2);

	point5.setPosition(pos.x + width - 4.f, pos.y + height - 4.f);

	point6.setPosition(pos.x + width/2, pos.y + height - 4.f);

	point7.setPosition(pos.x + 1.f, pos.y + height - 4.f);

	point8.setPosition(pos.x, pos.y + height/2);

	window->draw(point1);
	window->draw(point2);
	window->draw(point3);
	window->draw(point4);
	window->draw(point5);
	window->draw(point6);
	window->draw(point7);
	window->draw(point8);
}

