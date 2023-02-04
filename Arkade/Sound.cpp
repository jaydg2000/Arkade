#include "Sound.h"
#include "Audio.h"

namespace arkade {

	Sound::Sound(const char* filename)
	{
		_audio = Audio::instance();
		m_ptr_mix_chunk = _audio->load_sound(filename);		
	}

	Sound::~Sound()
	{
	}

	void Sound::stop_sound() {
		if (m_channel == -1)
			return;
		stop_sound(m_channel);
	}

	void Sound::stop_sound(int channel) {
		if (channel == -1)
			return;
		Mix_HaltChannel(channel);
	}

	int Sound::play_sound(bool loop, int number_of_loops) {
		if (!_audio->enabled())
			return -1;
		m_channel = Mix_PlayChannel(-1, m_ptr_mix_chunk, loop ? number_of_loops : 0);
		return m_channel;
	}

}