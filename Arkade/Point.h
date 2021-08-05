#pragma once
#include <SDL.h>

namespace arkade {

	struct Point {
		int x;
		int y;

		Point() {};
		Point(int point_x, int point_y)
		{
			x = point_x;
			y = point_y;
		}

		SDL_Point	to_sdl() { SDL_Point sdl; sdl.x = x; sdl.y = y; return sdl; }
	};

}
