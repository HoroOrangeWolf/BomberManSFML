#include "MapElement.h"
#include <chrono>


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

auto MapElement::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
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
