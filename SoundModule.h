#pragma once

#include <SFML/Audio.hpp>

namespace SoundModule {

	enum class SOUNDS { EXPLOSION, DEATH, COLLECT_BONUS, CLICK };

	class SoundModule
	{
	private:
		sf::Sound explosion, death, collect_bonus, click;
		sf::SoundBuffer clickBuff, explosionBuff, deathBuff, collect_bonusBuff;
	public:

		void loadSounds();
		void play(SOUNDS sound);

	};

}