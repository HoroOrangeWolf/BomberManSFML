#pragma once

#include <SFML/Audio.hpp>
#include "Logger.h"

namespace SoundModule {

	enum class SOUNDS { EXPLOSION, DEATH, COLLECT_BONUS, CLICK, PLACE_BOMB };

	class SoundModule
	{
	private:
		static sf::Sound explosion, death, collect_bonus, click, splat;
		static sf::SoundBuffer clickBuff, explosionBuff, deathBuff, collect_bonusBuff, splat_buff;
	public:

		void static loadSounds();
		void static play(SOUNDS sound);

	};

}