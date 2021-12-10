#include "Player.h"
#include <iostream>

/**
 * .
 * \brief Konstruktor gracza
 * \param playerName Nickname gracza
 */
Player::Player(std::string playerName)
{
	this->playerName = playerName;
	this->msDelayToPlaceBomb = 500;
	this->playerModel = sf::RectangleShape(sf::Vector2f(5.f, 5.f));

	playerModel.setPosition(sf::Vector2f(100.f, 100.f));

	//this->playerModel.setFillColor(sf::Color::Blue);

	sf::CircleShape shape(2.f);

	shape.setFillColor(sf::Color::Transparent);

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

/**
 * .
 * \brief Pobiera nazwe gracza
 * \return 
 */
std::string Player::getPlayerName()
{
	return playerName;
}

/**
 * .
 * \brief Rysuje gracza na mapie
 * \param width Szerokosc
 * \param height Wysokosc
 * \param window Wskaznik na okno
 */
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

/**
 * .
 * \brief Przesuwa gracza
 * \param position Pozycja
 */
void Player::moveBy(sf::Vector2f position)
{
	//std::cout << position.x << ' ' << position.y << '\n';

	if (position.x == 0.f && position.y == 0.f)
		isStop = true;
	else
		isStop = false;



	playerModel.move(position);
}

/**
 * .
 * \brief Pobiera pozycje gracza
 * \return 
 */
sf::Vector2f Player::getPosition()
{
	return this->playerModel.getPosition();
}

/**
 * .
 * \brief Pobiera rozmiar gracza
 * \return 
 */
sf::Vector2f Player::getSize()
{
	return playerModel.getSize();
}

/**
 * .
 * \brief Ustawia pozycje gracza
 * \param position Pozycja
 */
void Player::setPosition(sf::Vector2f position)
{
	this->playerModel.setPosition(position);
}

/**
 * .
 * \brief Pobiera aktualny czas
 * \return 
 */
auto Player::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * .
 * \brief Animuje ruchy gracza
 */
void Player::animate()
{
	countFPS++;

	if (isStop)
		return;

	if (countFPS >= intervalFPS) {
		imgIndex++;
		countFPS = 0;
	}

	switch (direction)
	{
	case Direction::DOWN:
	{
		if (imgIndex >= (framesFront.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesFront[imgIndex]);
		playerModel.setTexture(&currentTexture);
	}
	break;
	case Direction::TOP:
	{
		if (imgIndex >= (framesBack.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesBack[imgIndex]);
		playerModel.setTexture(&currentTexture);
	}
	break;
	case Direction::LEFT:
	{
		if (imgIndex >= (framesLeft.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesLeft[imgIndex]);
		playerModel.setTexture(&currentTexture);
	}
	break;
	case Direction::RIGHT:
	{
		if (imgIndex >= (framesRight.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesRight[imgIndex]);
		playerModel.setTexture(&currentTexture);
	}
	break;
	default:
		break;
	}
}

/**
 * .
 * \brief Inicjuje animacje
 */
void Player::initAnimation()
{
	switch (direction)
	{
	case Direction::DOWN:
		currentTexture.loadFromImage(framesFront[0]);
		playerModel.setTexture(&currentTexture);
		break;
	case Direction::TOP:
		currentTexture.loadFromImage(framesBack[0]);
		playerModel.setTexture(&currentTexture);
		break;
	case Direction::RIGHT:
		currentTexture.loadFromImage(framesRight[0]);
		playerModel.setTexture(&currentTexture);
		break;
	case Direction::LEFT:
		currentTexture.loadFromImage(framesLeft[0]);
		playerModel.setTexture(&currentTexture);
		break;
	default:
		break;
	}
}

/**
 * .
 * \brief Kalkuluje sposob poruszania animacji gracza
 * \return 
 */
sf::Vector2f Player::getCalculateMove()
{
	if (sf::Keyboard::isKeyPressed(up.first)) {
		return up.second;
	}

	if (sf::Keyboard::isKeyPressed(down.first)) {
		return down.second;
	}

	if (sf::Keyboard::isKeyPressed(left.first)) {
		return left.second;
	}

	if (sf::Keyboard::isKeyPressed(right.first)) {
		return right.second;
	}


	return sf::Vector2f(0.f, 0.f);
}

/**
 * .
 * \brief Pobiera moc gracza
 * \return 
 */
int Player::getPower()
{
	return power;
}

/**
 * .
 * \brief Ustawia moc gracza
 * \param power Moc
 */
void Player::setPower(int power)
{
	this->power = power;
}

/**
 * .
 * \brief Pobiera maksymalna moc gracza
 * \return 
 */
int Player::getMaxPower()
{
	return maxPower;
}

/**
 * .
 * \brief Ustawia maksymalna moc gracza
 * \param maxPower Maksymalna moc
 */
void Player::setMaxPower(int maxPower)
{
	this->maxPower = maxPower;
}

/**
 * .
 * \brief Ustawia pasek zdrowia
 * \param healthBar Pasek zdrowia
 */
void Player::setHealthBar(HealthBar healthBar)
{
	this->healthBar = healthBar;
}

/**
 * .
 * \brief Pobiera ilosc zdrowia gracza
 * \return 
 */
int Player::getHealth()
{
	return healthBar.getHealthPoints();
}

/**
 * .
 * \brief Ustawia ilosc zdrowia gracza
 * \param health Ilosc zdrowia
 */
void Player::setHealth(int health)
{
	healthBar.setHealthPoints(health);
}

/**
 * .
 * \brief Sprawdza czy gracz jest niesmiertelny
 * \return 
 */
bool Player::isImmortal()
{
	return getCurrentTime() < (lastDamage + immortality);;
}

/**
 * .
 * \brief Resetuje niesmiertelnosc gracza
 */
void Player::resetImmortality()
{
	lastDamage = getCurrentTime();
}

/**
 * .
 * \brief Ustawia czas trwania niesmiertelnosci
 * \param duration Czas trwania
 */
void Player::setImmortalityDuration(long long duration)
{
	immortality = duration;
}

/**
 * .
 * \brief Ustawia ktory klawisz nalezy kliknac zeby poruszac sie w gore
 * \param cont Obiekt przechowujacy klawisz i wektor przesuniecia
 */
void Player::setUp(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	up = cont;
}

/**
 * .
 * \brief Ustawia ktory klawisz nalezy kliknac zeby poruszac sie w lewo
 * \param cont Obiekt przechowujacy klawisz i wektor przesuniecia
 */
void Player::setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	left = cont;
}

/**
 * .
 * \brief Ustawia ktory klawisz nalezy kliknac zeby poruszac sie w prawo
 * \param cont Obiekt przechowujacy klawisz i wektor przesuniecia
 */
void Player::setRight(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	right = cont;
}

/**
 * .
 * \brief Ustawia ktory klawisz nalezy kliknac zeby poruszac sie w dol
 * \param cont Obiekt przechowujacy klawisz i wektor przesuniecia
 */
void Player::setDown(std::pair<sf::Keyboard::Key, sf::Vector2f> cont)
{
	down = cont;
}

/**
 * .
 * \brief Podkladanie bomby
 * \param key Klawisz
 */
void Player::setPlaceBomb(sf::Keyboard::Key key)
{
	this->placeBomb = key;
}

/**
 * .
 * \brief Ustawia opoznienie dla podkladania nastepnej bomby
 * \param msToPlaceBomb Czas opoznienia
 */
void Player::setDelayToPlaceBomb(long msToPlaceBomb)
{
	this->msDelayToPlaceBomb;
}

/**
 * .
 * \brief Ustawia kierunek
 * \param direction Kierunek
 */
void Player::setDirection(Direction direction)
{
	this->direction = direction;
}

/**
 * .
 * \brief Pobiera kierunek
 * \return 
 */
Direction Player::getDirection()
{
	return direction;
}

/**
 * .
 * \brief Restartuje czas polozenia bomby
 */
void Player::restartBombPlaceTime()
{
	this->lastBombPlace = 0;
}

/**
 * .
 * \brief Sprawdza czy sie nakladaja na siebie obiekty
 * \param rl Obiekty
 * \return 
 */
bool Player::isIntersect(sf::FloatRect rl)
{
	return (point1.getGlobalBounds().intersects(rl) || point2.getGlobalBounds().intersects(rl) || point3.getGlobalBounds().intersects(rl) ||
		point4.getGlobalBounds().intersects(rl));
}

/**
 * .
 * \brief Sprawdza czy mozna poruszac sie w prawo
 * \param shape Gracz
 * \return 
 */
bool Player::isCanMoveRight(sf::FloatRect shape)
{
	return !point2.getGlobalBounds().intersects(shape);
}

/**
 * .
 * \brief Sprawdza czy mozna poruszac sie w lewo
 * \param shape Gracz
 * \return
 */
bool Player::isCanMoveLeft(sf::FloatRect shape)
{
	return !point4.getGlobalBounds().intersects(shape);
}

/**
 * .
 * \brief Sprawdza czy mozna poruszac sie w gore
 * \param shape Gracz
 * \return
 */
bool Player::isCanMoveUp(sf::FloatRect shape)
{
	return !point1.getGlobalBounds().intersects(shape);
}

/**
 * .
 * \brief Sprawdza czy mozna poruszac sie w dol
 * \param shape Gracz
 * \return
 */
bool Player::isCanMoveDown(sf::FloatRect shape)
{
	return !point3.getGlobalBounds().intersects(shape);
}

/**
 * .
 * \brief Sprawdza czy mozna polozyc bombe
 * \return 
 */
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

