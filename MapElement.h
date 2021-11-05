#pragma once
#include <SFML/Graphics.hpp>

class MapElement
{
private:
    int x, y;
    sf::RectangleShape shape;
public:
    MapElement() {
        shape = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    }
	virtual sf::RectangleShape& getToDraw();
    virtual bool isInteractive();
    sf::FloatRect getFloatRect();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    auto getCurrentTime();
};

