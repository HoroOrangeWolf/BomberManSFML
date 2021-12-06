#pragma once
#include <SFML/Graphics.hpp>

class BitmapHandler
{
public:
	static sf::Image create(int width, int height);
	static void save(sf::Image& ims, std::string path);
	static sf::Image getImageFromFile(std::string path);
	static void copyTo(sf::Image& from, sf::Image& to, int destinationX, int destinationY);

};

