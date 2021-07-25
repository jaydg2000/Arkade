#include "Checkbox.h"

namespace arkade 
{
	Checkbox::Checkbox(const char* title, Font* font, uint32_t screen_x, uint32_t screen_y)
		: FormControl(screen_x, screen_y, { 0,0 })
	{
		_text = new Text(title, font);
		size(make_size(_text->source_rect()->w, _text->source_rect()->h));
		_font = font;
		_box_rect.x = screen_x;
		_box_rect.y = screen_y;
		_box_rect.w = 20;
		_box_rect.h = 20;
		_is_checked = false;
		_can_toggle = true;
	}

	Checkbox::~Checkbox()
	{
	}
	void Checkbox::checked(bool is_checked)
	{
		_is_checked = is_checked;
	}

	bool Checkbox::checked()
	{
		return _is_checked;
	}

	void Checkbox::on_render(Graphics* ptr_graphics)
	{
		ptr_graphics->render(&_box_rect, RGB::White, _is_checked);
		ptr_graphics->render(_text, x() + 25, y() - _font->size()/2);
	}

	void Checkbox::on_mouse_down(uint32_t mouse_x, uint32_t mouse_y)
	{
		if (_can_toggle)
		{
			_can_toggle = false;
			_is_checked = !_is_checked;
		}
	}

	void Checkbox::on_mouse_up()
	{
		_can_toggle = true;
	}
}