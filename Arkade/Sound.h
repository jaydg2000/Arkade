#pragma once
#include <SDL_mixer.h>

namespace arkade {

	class Sound {
	public:
		Sound(Mix_Chunk* ptr_mix_chunk);
		~Sound();

		int					play_sound(Mix_Chunk* sound, bool loop);
		void				stop_sound(int channel);

	private:
		Mix_Chunk*			m_ptr_mix_chunk;
		};
	};

}