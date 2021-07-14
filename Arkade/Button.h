#pragma once
#include "Font.h"
#include "Image.h"
#include "Text.h"
#include "ArkadeTypes.h"
#include "RGB.h"
#include <functional>

namespace arkade {

	class Button
	{
	public:
		Button(Image* image, uint32_t screen_x = 0, uint32_t screen_y = 0);
		Button(Text* ptr_text, uint32_t screen_x = 0, uint32_t screen_y = 0);
		~Button();

		Image*					image();
		void					image(Image* image);
		RGB						border_color();
		void					border_color(RGB border_color);
		Size					border_margin();
		void					border_margin(Size border_margin);
		void					on_click(std::function<void()> click_action);		

	private:
		uint32_t				_x, _y;
		bool					_is_managing_image;
		Size					_ptr_size;
		Image*					_ptr_image;
		const char*				_psz_title;
		Font*					_ptr_font;
		uint32_t				_click_message_id;
		RGB						_border_color;
		Size					_border_size;
		std::function<void()>	_click_action;
	};

}