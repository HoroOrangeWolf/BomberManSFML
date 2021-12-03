#include "Player.h"

Player::Player()
{
	this->msDelayToPlaceBomb = 500;
	this->playerModel = sf::RectangleShape(sf::Vector2f(5.f, 5.f));

	playerModel.setPosition(sf::Vector2f(100.f, 100.f));

	this->playerModel.setFillColor(sf::Color::Blue);

	sf::CircleShape shape(2.f);

	shape.setFillColor(sf::Color::Red);

	this->point1 = shape;
	this->point2 = shape;
	this->point3 = shape;
	this->point4 = shape;

	up = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));
	down = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));
	left = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));
	right = std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, 0.f));

	this->healthBar = HealthBar(sf::Vector2f(0.f, 0.f), 3);
}

void Player::drawPlayer(double width, double height, sf::RenderWindow* window)
{
	width *= 0.9f;
	height *= 0.9f;

	playerModel.setSize(sf::Vector2f(width, height));

	window->draw(playerModel);

	sf::Vector2f pos = playerModel.getPosition();

	point1.setPosition(pos.x + width/2, pos.y + 1.f);

	point2.setPosition(pos.x + width - 4.f, pos.y + height/2);

	point3.setPosition(pos.x + width/2, pos.y + height - 4.f);

	point4.setPosition(pos.x, pos.y + height / 2);

	window->draw(point1);
	window->draw(point2);
	window->draw(point3);
	window->draw(point4);
	healthBar.draw(window);
}

void Player::moveBy(sf::Vector2f position)
{
	playerModel.move(position);
}

sf::Vector2f Player::getPosition()
{
	return this->playerModel.getPosition();
}

sf::Vector2f Player::getSize()
{
	return playerModel.getSize();
}

void Player::setPosition(sf::Vector2f position)
{
	this->playerModel.setPosition(position);
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

int Player::getPower()
{
	return power;
}

void Player::setPower(int power)
{
	this->power = power;
}

int Player::getMaxPower()
{
	return maxPower;
}

void Player::setMaxPower(int maxPower)
{
	this->maxPower = maxPower;
}

void Player::setHealthBar(HealthBar healthBar)
{
	this->healthBar = healthBar;
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

bool Player::isIntersect(sf::FloatRect rl)
{
	return (point1.getGlobalBounds().intersects(rl) || point2.getGlobalBounds().intersects(rl) || point3.getGlobalBounds().intersects(rl) ||
		point4.getGlobalBounds().intersects(rl));
}

bool Player::isCanMoveRight(sf::FloatRect shape)
{
	return !point2.getGlobalBounds().intersects(shape);
}

bool Player::isCanMoveLeft(sf::FloatRect shape)
{
	return !point4.getGlobalBounds().intersects(shape);
}

bool Player::isCanMoveUp(sf::FloatRect shape)
{
	return !point1.getGlobalBounds().intersects(shape);
}

bool Player::isCanMoveDown(sf::FloatRect shape)
{
	return !point3.getGlobalBounds().intersects(shape);
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

