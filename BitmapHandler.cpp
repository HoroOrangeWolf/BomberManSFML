#include "BitmapHandler.h"
#include <iostream>

/**
 * .
 * \brief Tworzy bitmape
 * \param width Szerokosc bitmapy
 * \param height Wysokosc bitmapy
 * \return Zwraca bitmape
 */
sf::Image BitmapHandler::create(int width, int height)
{
	sf::Image ims = sf::Image();

	ims.create(width, height, sf::Color::Transparent);

	return ims;
}

/**
 * .
 * \brief Zapisuje bitmape
 * \param ims Obraz do zapisania
 * \param path Sciezka
 */
void BitmapHandler::save(sf::Image& ims, std::string path)
{
	ims.saveToFile(path);
}

/**
 * .
 * \brief Otwiera bitmape z pliku
 * \param path Sciezka
 * \return Zwraca bitmape
 */
sf::Image BitmapHandler::getImageFromFile(std::string path)
{
	sf::Texture texture;

	texture.loadFromFile(path);

	return texture.copyToImage();
}

/**
 * .
 * \brief Kopiuje bitmape
 * \param from Z bitmapy
 * \param to Do bitmapy
 * \param destinationX Pozycja X na bitmapie
 * \param destinationY Pozycja Y na bitmapie
 */
void BitmapHandler::copyTo(sf::Image& from, sf::Image& to, int destinationX, int destinationY)
{
	to.copy(from, destinationX, destinationY);
}
