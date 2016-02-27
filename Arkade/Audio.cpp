#include "Audio.h"
#include "Sound.h"
#include <iostream>

namespace arkade {

	Audio* Audio::m_instance = nullptr;

	Audio::Audio()
	{
		initialize();
	}


	Audio::~Audio()
	{
	}

	Audio* Audio::instance() {
		if (!m_instance)
			m_instance = new Audio();

		return m_instance;
	}

	void Audio::initialize() {
		// 11000,22050, 44100,     AUDIO_S16SYS
		initialize(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
	}

	void Audio::initialize(int audioRate, Uint16 audioFormat, int audioChannels, int audioBuffers) {
		if (Mix_OpenAudio(audioRate, audioFormat, audioChannels, audioBuffers) != 0) {
			exit(21);
		}
	}

	void Audio::uninitialize() {
		Mix_CloseAudio();
	}

	Mix_Chunk* Audio::load_sound(std::string& filename) {
		Mix_Chunk* ptr_mix = Mix_LoadWAV(filename.c_str());
		if (!ptr_mix) {
			exit(22);
		}

		return ptr_mix;
	}

	void Audio::stop_all_sound() {
		Mix_HaltChannel(-1);
	}

}