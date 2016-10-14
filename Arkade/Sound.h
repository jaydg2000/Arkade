#pragma once
#include <string>
#include <SDL_mixer.h>

namespace arkade {

	class Sound {
	public:
		Sound(const char* filename);
		~Sound();

		int					play_sound(bool loop = false, int number_of_loops = -1);
		void				stop_sound();
		void				stop_sound(int channel);

	private:
		Mix_Chunk*			m_ptr_mix_chunk;
		int					m_channel;
	};
}