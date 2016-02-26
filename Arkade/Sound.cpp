#include "Sound.h"

namespace arkade {

	Sound::Sound(Mix_Chunk* ptr_mix_chunk)
	{
		m_ptr_mix_chunk = ptr_mix_chunk;
	}


	Sound::~Sound()
	{
	}

	void Sound::stop_sound(int channel) {
		Mix_HaltChannel(channel);
	}

	int Sound::play_sound(Mix_Chunk* sound, bool loop = false) {
		return Mix_PlayChannel(-1, sound, loop ? -1 : 0);
	}

}