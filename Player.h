#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <chrono>
#include "HealthBar.h"
#include "Direction.h"
#include "BitmapObject.h"
#include "AnimatedObject.h"

class Player
	:public BitmapObject,
	public AnimatedObject
{
private: 
	sf::RectangleShape playerModel;
	std::pair<sf::Keyboard::Key, sf::Vector2f> up;
	std::pair<sf::Keyboard::Key, sf::Vector2f> down;
	std::pair<sf::Keyboard::Key, sf::Vector2f> left;
	std::pair<sf::Keyboard::Key, sf::Vector2f> right;
	sf::Keyboard::Key placeBomb;
	Direction direction = Direction::RIGHT;
	long long msDelayToPlaceBomb;
	long long lastBombPlace;
	long long lastDamage = 0;
	HealthBar healthBar;
	//ms = 2s
	long long immortality = 2000L;
	int power = 1;
	int maxPower = 7;

	
	sf::CircleShape point1,
		point2,
		point3,
		point4;

	std::string playerName;

public:
	Player(std::string playerName);
	std::string getPlayerName();
	void drawPlayer(double width, double height, sf::RenderWindow* window);
	void moveBy(sf::Vector2f position);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getCalculateMove();

	int getPower();
	void setPower(int power);

	int getMaxPower();
	void setMaxPower(int maxPower);

	void setHealthBar(HealthBar healthBar);

	int getHealth();
	void setHealth(int health);

	bool isImmortal();
	void resetImmortality();
	void setImmortalityDuration(long long duration);

	void setUp(std::pair < sf::Keyboard::Key, sf::Vector2f> cont);
	void setLeft(std::pair < sf::Keyboard::Key, sf::Vector2f> cont);
	void setRight(std::pair < sf::Keyboard::Key, sf::Vector2f> cont);
	void setDown(std::pair < sf::Keyboard::Key, sf::Vector2f> cont);
	void setPlaceBomb(sf::Keyboard::Key);
	void setDelayToPlaceBomb(long msToPlaceBomb);
	void setDirection(Direction direction);
	Direction getDirection();
	void restartBombPlaceTime();

	bool isIntersect(sf::FloatRect rl);

	bool isCanMoveRight(sf::FloatRect shape);
	bool isCanMoveLeft(sf::FloatRect shape);
	bool isCanMoveUp(sf::FloatRect shape);
	bool isCanMoveDown(sf::FloatRect shape);
	bool isCanPlaceBomb();

	auto getCurrentTime();

	void animate() override;

	void initAnimation();

};

