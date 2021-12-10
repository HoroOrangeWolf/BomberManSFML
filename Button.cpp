#include "Button.h"

/**
 * .
 * \brief Wysrodkowanie tekstu przycisku
 */
void Button::alignCenterText()
{
	int textWidth = text.getGlobalBounds().width,
		textHeight = text.getGlobalBounds().height;
	
	int buttonCenterX = shape.getPosition().x + shape.getSize().x / 2,
		buttonCenterY = shape.getPosition().y + shape.getSize().y / 2;

	text.setPosition(sf::Vector2f(buttonCenterX - textWidth/2, buttonCenterY - textHeight/1.4f));
}

/**
 * .
 * \brief Konstruktor przyciskow
 * \param widthHeight Szerokosc i wysokosc
 * \param content Tekst
 */
Button::Button(sf::Vector2f widthHeight, std::string content)
{
	if (!font.loadFromFile("font/consola.ttf"))
		Logger::log("Nie udalo sie zaladowac font consola");

	shape.setFillColor(sf::Color{ 80,80,80,180 });

	shape.setPosition(sf::Vector2f(0.f, 0.f));

	shape.setSize(widthHeight);

	text.setCharacterSize(30);

	text.setString(content);
	text.setFont(font);

	text.setFillColor(sf::Color{ 255,255,255,200 });
	alignCenterText();
}

/**
 * .
 * \brief Ustawienie pozycji przyciskow
 * \param position Pozycja
 */
void Button::setPosition(sf::Vector2f position)
{
	shape.setPosition(position);
	alignCenterText();
}

/**
 * .
 * \brief Rysowanie przyciskow
 * \param window Wskaznik na okno
 */
void Button::draw(sf::RenderWindow* window)
{
	window->draw(shape);
	window->draw(text);
}

/**
 * .
 * \brief Pobranie rozmiaru przycisku
 * \return 
 */
sf::Vector2f Button::getSize()
{
	return shape.getSize();
}

/**
 * .
 * \brief Pobranie pozycji przycisku
 * \return 
 */
sf::Vector2f Button::getPosition()
{
	return shape.getPosition();
}
