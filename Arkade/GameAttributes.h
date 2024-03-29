#pragma once
#include <SDL.h>
#include <SDL_mixer.h>

namespace arkade {

	struct GameAttributes {
		bool full_screen = true;
		bool hide_cursor = true;
		bool use_logical_scale = false;
		uint32_t logical_width = 0;
		uint32_t logical_height = 0;
		uint32_t width = 1366;
		uint32_t height = 768;
		uint32_t color_depth = 32;
		uint32_t frame_rate = 60;
		uint32_t audio_rate = MIX_DEFAULT_FREQUENCY;
		uint16_t audio_format = MIX_DEFAULT_FORMAT;
		uint32_t audio_channels = 2; 
		uint32_t audio_buffers = 4096;
		const char* psz_caption = "";
	};
}