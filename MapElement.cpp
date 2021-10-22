#include "MapElement.h"


sf::RectangleShape& MapElement::getToDraw()
{
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(2.f);

	return shape;
	
}

bool MapElement::isInteractive()
{
	return false;
}

sf::FloatRect MapElement::getFloatRect()
{
	return shape.getGlobalBounds();
}

int MapElement::getX()
{
	return x;
}

int MapElement::getY()
{
	return y;
}

void MapElement::setX(int x)
{
	this->x = x;
}

void MapElement::setY(int y)
{
	this->y = y;
}
