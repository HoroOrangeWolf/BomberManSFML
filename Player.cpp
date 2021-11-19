#include "Player.h"

Player::Player()
{
	this->msDelayToPlaceBomb = 500;
	this->playerModel = sf::RectangleShape(sf::Vector2f(5.f, 5.f));

	playerModel.setPosition(sf::Vector2f(50.f, 50.f));

	this->playerModel.setFillColor(sf::Color::Blue);

	sf::CircleShape shape(2.f);

	shape.setFillColor(sf::Color::Red);

	this->point1 = shape;
	this->point2 = shape;
	this->point3 = shape;
	this->point4 = shape;
	this->point5 = shape;
	this->point6 = shape;
	this->point7 = shape;
	this->point8 = shape;

	up = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));
	down = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));
	left = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));
	right = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));
}

void Player::drawPlayer(double width, double height, sf::RenderWindow* window)
{
	playerModel.setSize(sf::Vector2f(width, height));

	window->draw(playerModel);

	sf::Vector2f pos = playerModel.getPosition();

	point1.setPosition(pos.x + 1.f, pos.y + 1.f);

	point2.setPosition(pos.x + width/2, pos.y + 1.f);

	point3.setPosition(pos.x + width - 4.f, pos.y + 1.f);

	point4.setPosition(pos.x + width - 4.f, pos.y + height/2);

	point5.setPosition(pos.x + width - 4.f, pos.y + height - 4.f);

	point6.setPosition(pos.x + width/2, pos.y + height - 4.f);

	point7.setPosition(pos.x + 1.f, pos.y + height - 4.f);

	point8.setPosition(pos.x, pos.y + height / 2);

	window->draw(point1);
	window->draw(point2);
	window->draw(point3);
	window->draw(point4);
	window->draw(point5);
	window->draw(point6);
	window->draw(point7);
	window->draw(point8);
}

void Player::moveBy(sf::Vector2f position)
{
	playerModel.move(position);
}

sf::Vector2f Player::getPosition()
{
	return this->playerModel.getPosition();
}

auto Player::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


sf::Vector2f Player::getCalculateMove()
{
	if (sf::Keyboard::isKeyPressed(up.first))
		return up.second;

	if (sf::Keyboard::isKeyPressed(down.first))
		return down.second;

	if (sf::Keyboard::isKeyPressed(left.first))
		return left.second;

	if (sf::Keyboard::isKeyPressed(right.first))
		return right.second;

	return sf::Vector2f(0.f, 0.f);
}

void Player::setUp(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	up = cont;
}

void Player::setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	left = cont;
}

void Player::setRight(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	right = cont;
}

void Player::setDown(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	down = cont;
}

void Player::setPlaceBomb(sf::Keyboard::Key key)
{
	this->placeBomb = key;
}

void Player::setDelayToPlaceBomb(long msToPlaceBomb)
{
	this->msDelayToPlaceBomb;
}

void Player::setDirection(Direction direction)
{
	this->direction = direction;
}

Direction Player::getDirection()
{
	return direction;
}

void Player::restartBombPlaceTime()
{
	this->lastBombPlace = 0;
}

bool Player::isCanMoveRight(sf::FloatRect shape)
{
	return (!point3.getGlobalBounds().intersects(shape) && !point4.getGlobalBounds().intersects(shape) && !point5.getGlobalBounds().intersects(shape));
}

bool Player::isCanMoveLeft(sf::FloatRect shape)
{
	return (!point1.getGlobalBounds().intersects(shape) && !point7.getGlobalBounds().intersects(shape) && !point8.getGlobalBounds().intersects(shape));
}

bool Player::isCanMoveUp(sf::FloatRect shape)
{
	return (!point1.getGlobalBounds().intersects(shape) && !point2.getGlobalBounds().intersects(shape) && !point3.getGlobalBounds().intersects(shape));
}

bool Player::isCanMoveDown(sf::FloatRect shape)
{
	return (!point5.getGlobalBounds().intersects(shape) && !point6.getGlobalBounds().intersects(shape) && !point7.getGlobalBounds().intersects(shape));
}

bool Player::isCanPlaceBomb()
{

	if (sf::Keyboard::isKeyPressed(placeBomb) && (lastBombPlace + msDelayToPlaceBomb < getCurrentTime()))
	{
		lastBombPlace = getCurrentTime();
		return true;
	}
	else 
		return false;
}

