#include "MapElement.h"


sf::RectangleShape& MapElement::getToDraw()
{
	sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));

	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(2.f);

	return shape;
	
}
