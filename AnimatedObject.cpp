#include "AnimatedObject.h"
#include "AnimatedObject.h"

/**
 * .
 * \brief Ustawianie klatek animacji dla poruszania sie do przodu
 * \param arr Tablica elementow animacji
 * \param length Dlugosc tablicy
 */
void AnimatedObject::setFramesFront(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesFront.push_back(arr[i]);
}

/**
 * .
 * \brief Ustawianie klatek animacji dla poruszania sie do tylu
 * \param arr Tablica elementow animacji
 * \param length Dlugosc tablicy
 */
void AnimatedObject::setFramesBack(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesBack.push_back(arr[i]);
}

/**
 * .
 * \brief Ustawianie klatek animacji dla poruszania sie w lewo
 * \param arr Tablica elementow animacji
 * \param length Dlugosc tablicy
 */
void AnimatedObject::setFramesLeft(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesLeft.push_back(arr[i]);
}

/**
 * .
 * \brief Ustawianie klatek animacji dla poruszania sie w prawo
 * \param arr Tablica elementow animacji
 * \param length Dlugosc tablicy
 */
void AnimatedObject::setFramesRight(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesRight.push_back(arr[i]);
}


/**
 * .
 * \brief Ustawienie interwalu klatek dla animacji
 * \param fps Ilosc klatek na sekunde
 */
void AnimatedObject::setIntervalFPS(int fps)
{
	intervalFPS = fps;
}

/**
 * .
 * \brief Pobranie interwalu klatek na sekunde
 * \return
 */
int AnimatedObject::getIntervalFPS()
{
	return intervalFPS;
}

/**
 * .
 * \brief Wstrzymywanie i wznawianie animacji
 * \param isStop Wartosc true oznacza ze animacja zostala przerwana
 */
void AnimatedObject::setIsStop(bool isStop)
{
	this->isStop = isStop;
}

/**
 * .
 * \brief Pobieranie informacji o stanie animacji
 * \return Zwraca true lub false
 */
bool AnimatedObject::getIsStop()
{
	return isStop;
}
