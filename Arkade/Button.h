#pragma once
#include "Font.h"
#include "Image.h"
#include "Text.h"
#include "ArkadeTypes.h"
#include "RGB.h"
#include "FormControl.h"
#include "Graphics.h"

namespace arkade {

	class Button : public FormControl
	{
	public:
		Button(Image* image, uint32_t screen_x = 0, uint32_t screen_y = 0);
		Button(Text* ptr_text, uint32_t screen_x = 0, uint32_t screen_y = 0);
		~Button();

		Image*					image();
		void					image(Image* image);
		RGB						border_color();
		void					border_color(RGB border_color);

		void					on_render(Graphics* ptr_graphics);

	protected:
		virtual void			on_mouse_down(uint32_t mouse_x, uint32_t mouse_y) override;
		virtual void			on_mouse_up() override;
		virtual void			on_mouse_over(uint32_t mouse_x, uint32_t mouse_y) override;


	private:
		bool					_is_managing_image;
		bool					_is_being_clicked;
		Size					_ptr_size;
		Image*					_ptr_image;
		const char*				_psz_title;
		Font*					_ptr_font;
		RGB						_border_color;
		
	};

}