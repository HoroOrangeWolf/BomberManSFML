#pragma once

#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::Font font;
	sf::Text text;
	sf::RectangleShape shape;
	void alignCenterText();
public:
	Button(sf::Vector2f widthHeight, std::string text);
	void setPosition(sf::Vector2f position);
	void draw(sf::RenderWindow* window);
	sf::Vector2f getSize();
	sf::Vector2f getPosition();

};

