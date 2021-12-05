#include "StaticBlock.h"

sf::RectangleShape& StaticBlock::getToDraw()
{
    return shape;
}

bool StaticBlock::isInteractive()
{
    return true;
}

StaticBlock::StaticBlock()
{
    unbreakableBlockTexture.loadFromFile("images/unbreakable_block.png");
    shape.setTexture(&unbreakableBlockTexture);
}