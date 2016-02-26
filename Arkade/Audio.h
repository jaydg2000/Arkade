#pragma once
#include <SDL_mixer.h>
#include <string>

namespace arkade {
	class Sound;
	class Audio {
	public:
		Audio();
		~Audio();

		static Audio*		instance();
		void				initialize();
		void				initialize(int audio_rate, Uint16 audio_format, int audio_channels, int audio_buffers);
		void				uninitialize();
		Sound*				load_sound(std::string& filename);
		void				stop_all_sound();

	private:
		static Audio*		m_instance;
	};
}