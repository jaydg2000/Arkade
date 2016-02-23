#pragma once
#include <SDL.h>

namespace arkade {

	struct Point {
		int x;
		int y;

		SDL_Point	to_sdl() { SDL_Point sdl; sdl.x = x; sdl.y = y; return sdl; }
	};

}
