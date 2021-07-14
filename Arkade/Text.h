#pragma once
#include "ArkadeTypes.h"
#include "Font.h"
#include "Image.h"

namespace arkade {

	class Text
	{
	public:
		Text(const char* psz_text, Font* font, SDL_Color color = { 255,255,255,255 });
		~Text();

		Texture*					texture();
		const char*					text() const;
		void						text(const char* psz_text);
		void						color(SDL_Color color);
		Rect*						source_rect();
		Image*						to_image();

	private:
		const char*					_psz_text;
		SDL_Color					_color;
		Font*						_ptr_font;
		Texture*					_ptr_texture;
		Rect						_source_rect;

		void						_make_texture();
		void						_make_source_rect();
	};

}