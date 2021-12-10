#include "HealthBar.h"

HealthBar::HealthBar(sf::Vector2f position, int healthPoints)
{
	this->position = position;
	this->healthPoints = healthPoints;

	if (!texture.loadFromFile("images/kuba_heart.png")) {
		Logger::log("Nie mozna zaladowac serduszka w ksztalcie kuby!");
	}

	shape.setTexture(&texture);
	drawDirect = Direction::RIGHT;
}

HealthBar::HealthBar()
{
	this->position = sf::Vector2f(0.f, 0.f);
	healthPoints = 3;
	if (!texture.loadFromFile("images/kuba_heart.png")) {
		Logger::log("Nie mozna zaladowac serduszka w ksztalcie kuby!");
	}
	shape.setTexture(&texture);
	drawDirect = Direction::RIGHT;
}

sf::Texture HealthBar::texture = sf::Texture();

void HealthBar::setHealthPoints(int healthPoints)
{
	this->healthPoints = healthPoints;
}

int HealthBar::getHealthPoints()
{
	return healthPoints;
}

void HealthBar::setDrawDirection(Direction direction)
{
	this->drawDirect = direction;
}

Direction HealthBar::getDrawDirection()
{
	return drawDirect;
}

void HealthBar::draw(sf::RenderWindow* window)
{
	if(drawDirect == Direction::RIGHT)
		for (int i = 0; i < healthPoints; ++i)
		{
			sf::RectangleShape shap = shape;
			shap.setPosition(sf::Vector2f(i * shap.getSize().x, position.y));
			window->draw(shap);
		}
	else {
		int windowWidth = window->getSize().x - shape.getSize().x;
		for (int i = 0; i < healthPoints; ++i)
		{
			sf::RectangleShape shap = shape;
			shap.setPosition(sf::Vector2f(windowWidth - i * shap.getSize().x, position.y));
			window->draw(shap);
		}
	}

}

void HealthBar::loadHealthTextureFromFile(std::string path)
{
	if (!texture.loadFromFile(path))
		throw "Can't load from file";
}

