#include "Bomb.h"

/**
 * .
 * \brief Konstruktor bomby
 */
Bomb::Bomb()
{
	this->creationTime = getCurrentTime();
	this->power = 1;
	this->msToExplode = 1500L;
	if (!texture.loadFromFile("images/bomba.png"))
		Logger::log("Nie uda³o siê za³adowaæ Bomb");
	shape.setTexture(&texture);
}

/**
 * .
 * \brief Konstruktor bomby
 * \param power Moc bomby
 * \param msToExplode Czas do wybuchu
 */
Bomb::Bomb(int power, long msToExplode)
{
	this->creationTime = getCurrentTime();
	this->power = power;
	this->msToExplode = msToExplode;
	if (!texture.loadFromFile("images/bomba.png"))
		Logger::log("Nie uda³o siê za³adowaæ Bomb");
	shape.setTexture(&texture);
}

/**
 * .
 * \brief Ustawienie mocy bomby
 * \param power Moc bomby
 */
void Bomb::setPower(int power)
{
	this->power = power;
}

/**
 * .
 * \brief Ustawienie czasu do wybuchu
 * \param msToExplode Czas do wybuchu
 */
void Bomb::setMsToExplode(long msToExplode)
{
	this->msToExplode = msToExplode;
}

/**
 * .
 * \brief Sprawdzenie czy bomba jest gotowa do wybuchu
 * \return Zwraca true jesli jest gotowa
 */
bool Bomb::isReadyToExplode()
{
	return (creationTime + msToExplode) < getCurrentTime();
}

/**
 * .
 * \brief Sprawdza moc bomby
 * \return Moc bomby
 */
int Bomb::getPower()
{
	return power;
}
