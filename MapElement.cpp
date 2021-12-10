#include "MapElement.h"
#include <chrono>

/**
 * .
 * \brief Zwraca element mapy do narysowania
 * \return 
 */
sf::RectangleShape& MapElement::getToDraw()
{
	return shape;
}

/**
 * .
 * \brief Sprawdza czy element mapy jest interaktywny
 * \return 
 */
bool MapElement::isInteractive()
{
	return false;
}

/**
 * .
 * \brief Pobiera aktualny czas
 * \return 
 */
long long MapElement::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * .
 * \brief Zwraca rozmiar float rect
 * \return 
 */
sf::FloatRect MapElement::getFloatRect()
{
	return shape.getGlobalBounds();
}

/**
 * .
 * \brief Zwraca wspolrzedna X
 * \return 
 */
int MapElement::getX()
{
	return x;
}

/**
 * .
 * \brief Zwraca wspolrzedna X
 * \return
 */
int MapElement::getY()
{
	return y;
}

/**
 * .
 * \brief Ustawia wspolrzedna X
 * \param x Wspolrzedna X
 */
void MapElement::setX(int x)
{
	this->x = x;
}

/**
 * .
 * \brief Ustawia wspolrzedna Y
 * \param y Wspolrzedna Y
 */
void MapElement::setY(int y)
{
	this->y = y;
}
