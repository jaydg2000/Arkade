#pragma once
#include <SDL.h>

namespace arkade {

	struct PointF {
		float x;
		float y;

		SDL_Point	to_sdl() { SDL_Point sdl; sdl.x = (int)x; sdl.y = (int)y; return sdl; }
	};

}
