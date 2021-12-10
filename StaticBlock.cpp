#include "StaticBlock.h"

/**
 * .
 * \brief Rysuje statyczny blok na mapie
 * \return 
 */
sf::RectangleShape& StaticBlock::getToDraw()
{
    return shape;
}

/**
 * .
 * \brief Sprawdza czy obiekt jest interaktywny
 * \return 
 */
bool StaticBlock::isInteractive()
{
    return true;
}

/**
 * .
 * \brief Konstruktor bloku statycznego
 */
StaticBlock::StaticBlock()
{
    if (!unbreakableBlockTexture.loadFromFile("images/unbreakable_block.png")) {
        Logger::log("Nie mozna zaladowac statycznego bloku");
    }
    shape.setTexture(&unbreakableBlockTexture);
}