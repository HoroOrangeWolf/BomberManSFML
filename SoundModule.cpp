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

	death = sf::Sound(deathBuff);


	explosionBuff = sf::SoundBuffer();

	if (!explosionBuff.loadFromFile("sounds/ExplosionSound.wav"))
		std::cout << "Can't load ExplosionSound" << std::endl;

	explosion = sf::Sound(explosionBuff);

	splat_buff = sf::SoundBuffer();

	if (!splat_buff.loadFromFile("sounds/splat.wav"))
		std::cout << "Can't load splat sound" << std::endl;
	
	splat = sf::Sound(splat_buff);
}

sf::Sound SoundModule::SoundModule::explosion = sf::Sound();
sf::Sound SoundModule::SoundModule::death = sf::Sound();
sf::Sound SoundModule::SoundModule::collect_bonus = sf::Sound();
sf::Sound SoundModule::SoundModule::click = sf::Sound();
sf::Sound SoundModule::SoundModule::splat = sf::Sound();

sf::SoundBuffer SoundModule::SoundModule::clickBuff = sf::SoundBuffer();
sf::SoundBuffer SoundModule::SoundModule::explosionBuff = sf::SoundBuffer();
sf::SoundBuffer SoundModule::SoundModule::deathBuff = sf::SoundBuffer();
sf::SoundBuffer SoundModule::SoundModule::collect_bonusBuff = sf::SoundBuffer();
sf::SoundBuffer SoundModule::SoundModule::splat_buff = sf::SoundBuffer();

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
	case SOUNDS::PLACE_BOMB:
		splat.play();
		break;
	default:
		break;
	}
}
