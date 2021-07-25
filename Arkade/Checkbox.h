#pragma once
#include "FormControl.h"
#include "Text.h"
#include "Font.h"

namespace arkade
{
	class Checkbox : public FormControl
	{	
	public:
		Checkbox(const char* title, Font* font, uint32_t screen_x, uint32_t screen_y);
		~Checkbox();

		void						checked(bool is_checked);
		bool						checked();

		virtual void				on_render(Graphics* ptr_graphics);

	protected:
		virtual void				on_mouse_down(uint32_t mouse_x, uint32_t mouse_y) override;
		virtual void				on_mouse_up() override;

	private:
		Text*						_text;
		Font*						_font;
		Rect						_box_rect;
		bool						_is_checked;
		bool						_can_toggle;
	};
}

