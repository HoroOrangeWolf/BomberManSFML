#pragma once
#include <SFML/Graphics.hpp>

class GameMenu
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape background;
	sf::RectangleShape playButton;
	sf::RectangleShape exitButton;
	sf::Texture texture;
	auto getCurrentTime();
	void initGameMenuGui();
public:
	GameMenu(sf::RenderWindow *window);
	int run();
};

