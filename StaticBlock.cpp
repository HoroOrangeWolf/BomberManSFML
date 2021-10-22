#include "StaticBlock.h"

sf::RectangleShape& StaticBlock::getToDraw()
{
    sf::RectangleShape shape = MapElement::getToDraw();

    shape.setFillColor(sf::Color::Green);

    return shape;
}
