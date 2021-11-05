#pragma once
#include <SFML/Graphics.hpp>

enum class Button {EXIT_BUTTON, PLAY_BUTTON};

class GameMenu
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape background;
	sf::RectangleShape playButton;
	sf::RectangleShape exitButton;
	sf::Texture texture;
	bool isMouseIn(sf::RectangleShape& shape);
	auto getCurrentTime();
public:
	GameMenu(sf::RenderWindow *window);
	Button run();
};

