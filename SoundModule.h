#pragma once

#include <SFML/Audio.hpp>

namespace SoundModule {

	enum class SOUNDS { EXPLOSION, DEATH, COLLECT_BONUS, CLICK };

	class SoundModule
	{
	private:
		static sf::Sound explosion, death, collect_bonus, click;
		static sf::SoundBuffer clickBuff, explosionBuff, deathBuff, collect_bonusBuff;
	public:

		void static loadSounds();
		void static play(SOUNDS sound);

	};

}