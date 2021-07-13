#include <iostream>
#include "Font.h"
#include "TextureCache.h"

namespace arkade {

	Font::Font(const char* font_path, int size)
	{
		_font = TTF_OpenFont(font_path, size);
		if (!_font)
		{
			std:cerr << "failed to load font: " << font_path << SDL_GetError();
		}
	}

	Font::~Font()
	{
	}

	TTF_Font* Font::font()
	{
		return _font;
	}

	int Font::size()
	{
		return _size;
	}

	Texture* Font::make_text_texture(const char* psz_text, SDL_Color text_color)
	{
		SDL_Surface* text_surface = TTF_RenderText_Solid(_font, psz_text, text_color);
		Texture* ptr_texture = Graphics::instance()->create_texture_from_surface(text_surface);
		SDL_FreeSurface(text_surface);
		return ptr_texture;
	}
}