#pragma once
#include <SDL.h>

#define FLIP_NONE SDL_FLIP_NONE
#define FLIP_HORIZONTAL SDL_FLIP_HORIZONTAL
#define FLIP_VERTICAL SDL_FLIP_VERTICAL

namespace arkade {
	typedef SDL_Rect Rect;
	typedef SDL_Point Vector2;
	typedef SDL_Point Size;
	typedef SDL_Texture Texture;
	typedef SDL_RendererFlip Flip;

	Size make_size(uint32_t x, uint32_t y) {
		Size s; s.x = x; s.y = y;
		return s;
	}
}