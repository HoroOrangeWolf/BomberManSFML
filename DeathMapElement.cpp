#include "DeathMapElement.h"

/**
 * .
 * \brief Konstruktor niebezpiecznych elementow na mapie
 */
DeathMapElement::DeathMapElement()
{
	this->msToDisappear = 1500L;
	this->creationTime = getCurrentTime();
}

/**
 * .
 * \brief Konstruktor niebezpiecznych elementow na mapie
 * \param msToDisappear Czas do znikniecia obiektu z mapy
 */
DeathMapElement::DeathMapElement(long msToDisappear)
{
	this->msToDisappear = msToDisappear;
	this->creationTime = getCurrentTime();
}

/**
 * .
 * \brief Ustawia czas do znikniecia elementu z mapy
 * \param msToDisappear Czas do znikniecia obiektu z mapy
 */
void DeathMapElement::setMsToDisappear(long msToDisappear)
{
	this->msToDisappear = msToDisappear;
}

/**
 * .
 * \brief Ustawia teksture dla niebezpiecznego elementu
 * \param path Sciezka do tekstury
 */
void DeathMapElement::setTexture(std::string path)
{
	if (!deathElementTexture.loadFromFile(path))
		Logger::log("Nie uda³o siê za³adowaæ Bomb");
	shape.setTexture(&deathElementTexture);
}

/**
 * .
 * \brief Sprawdza czy element moze byc juz usuniety z mapy
 * \return True jesli moze byc usuniety z mapy
 */
bool DeathMapElement::isCanDisappear()
{
	return (creationTime + msToDisappear) < getCurrentTime();
}
