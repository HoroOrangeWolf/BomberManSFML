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
    if (!unbreakableBlockTexture.loadFromFile("images/unbreakable_block.png")) {
        Logger::log("Nie mozna zaladowac statycznego bloku");
    }
    shape.setTexture(&unbreakableBlockTexture);
}