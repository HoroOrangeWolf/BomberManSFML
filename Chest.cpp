#include "Chest.h"

/**
 * .
 * \brief Ustawienie mocy skrzyni
 * \param power Moc skrzyni
 */
void Chest::setPower(int power)
{
    this->power = power;
}

/**
 * .
 * \brief Pobranie mocy skrzyni
 * \return Moc skrzyni
 */
int Chest::getPower()
{
    return power;
}

/**
 * .
 * \brief Czy obiekt jest interaktywny z graczem
 * \return Zwraca true jesli jest interaktywny
 */
bool Chest::isInteractive()
{
    return true;
}
