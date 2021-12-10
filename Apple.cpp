#include "Apple.h"

/**
 * .
 * \brief Zwiekszenie zasiegu razenia bomby
 * \param power Moc bomby
 */
void Apple::setPower(int power)
{
    this->power = power;
}

/**
 * .
 * \brief Pobranie informacji o mocy specjalnej
 * \return Zwraca moc mocy specjalnej
 */
int Apple::getPower()
{
    return power;
}

/**
 * .
 * \brief Czy obiekt jest interaktywny z graczem
 * \return Zwraca true jesli jest interaktywny
 */
bool Apple::isInteractive()
{
    return true;
}
