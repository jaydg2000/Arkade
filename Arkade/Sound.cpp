#include "Sound.h"
#include "Audio.h"

namespace arkade {

	Sound::Sound(const char* filename)
	{
		m_ptr_mix_chunk = Audio::instance()->load_sound(filename);
	}

	Sound::~Sound()
	{
	}

	void Sound::stop_sound() {
		stop_sound(m_channel);
	}

	void Sound::stop_sound(int channel) {
		Mix_HaltChannel(channel);
	}

	int Sound::play_sound(bool loop, int number_of_loops) {
		m_channel = Mix_PlayChannel(-1, m_ptr_mix_chunk, loop ? number_of_loops : 0);
		return m_channel;
	}

}