#include "EndGameScreen.h"

/**
 * .
 * \brief Wyswietla ekran po zakonczeniu gry
 * \param window Wskaznik na okno
 * \param text Tekst
 */
void EndGameScreen::run(sf::RenderWindow* window, std::string text)
{
	window->clear();

    sf::Font font;

    if (!font.loadFromFile("font/consola.ttf"))
        Logger::log("Nie udalo sie zaladowac font consola");


    sf::Text textPlay;
    textPlay.setFont(font);
    textPlay.setString(text + "\nClick Left Mouse Button");
    textPlay.setCharacterSize(40);

    sf::Vector2u size = window->getSize();

    textPlay.setPosition(sf::Vector2f(size.x / 2 - textPlay.getGlobalBounds().width/2, size.y / 2 - textPlay.getGlobalBounds().height/2));

    window->draw(textPlay);

    window->display();

	while (!sf::Mouse::isButtonPressed(sf::Mouse::Left));

	window->clear();
}
