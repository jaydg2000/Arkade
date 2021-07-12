#include <iostream>
#include "Font.h"
#include "TextureCache.h"

namespace arkade {

	Font::Font(const std::string &font_path, int size)
	{
		_ptr_texture = nullptr;
		_font = TTF_OpenFont(font_path.c_str(), size);
		if (!_font)
		{
			std:cerr << "failed to load font: " << font_path.c_str() << SDL_GetError();
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
		if (_ptr_texture)
		{
			SDL_DestroyTexture(_ptr_texture);
			_ptr_texture = nullptr;
		}
		SDL_Surface* text_surface = TTF_RenderText_Solid(_font, psz_text, text_color);
		_ptr_texture = Graphics::instance()->create_texture_from_surface(text_surface);
		SDL_FreeSurface(text_surface);
		return _ptr_texture;
	}


}