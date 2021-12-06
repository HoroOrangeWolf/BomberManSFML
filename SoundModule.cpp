#include "SoundModule.h"
#include <iostream>

#include <SFML/System.hpp>

#include <fstream>

void SoundModule::SoundModule::loadSounds()
{
	clickBuff = sf::SoundBuffer();

	if (!clickBuff.loadFromFile("sounds/ClickSound.wav"))
		std::cout << "Can't load ClickSound" << std::endl;

	click = sf::Sound(clickBuff);


	collect_bonusBuff = sf::SoundBuffer();

	if (!collect_bonusBuff.loadFromFile("sounds/CollectSound.wav"))
		std::cout << "Can't load CollectSound" << std::endl;

	collect_bonus = sf::Sound(collect_bonusBuff);


	deathBuff = sf::SoundBuffer();

	if (!deathBuff.loadFromFile("sounds/DeathSound.wav"))
		std::cout << "Can't load DeathSound" << std::endl;

	death = sf::Sound(clickBuff);


	explosionBuff = sf::SoundBuffer();

	if (!deathBuff.loadFromFile("sounds/ExplosionSound.wav"))
		std::cout << "Can't load ExplosionSound" << std::endl;

	explosion = sf::Sound(clickBuff);
}

void SoundModule::SoundModule::play(SOUNDS sound)
{
	switch (sound) {
	case SOUNDS::EXPLOSION:
		explosion.play();
		break;
	case SOUNDS::COLLECT_BONUS:
		collect_bonus.play();
		break;
	case SOUNDS::DEATH:
		death.play();
		break;
	case SOUNDS::CLICK:
		click.play();
		break;
	default:
		break;
	}
}
