#pragma once
#include "ArkadeTypes.h"
#include <SDL_ttf.h>
#include <SDL.h>


namespace arkade {
	
	class Font
	{
	public:
		Font(const char* font_path, int size);
		~Font();

		TTF_Font*			font();
		int					size();
		Texture*			make_text_texture(const char* psz_text, SDL_Color = {255,255,255,255});

	private:
		TTF_Font*			_font;
		int					_size;
	};

}