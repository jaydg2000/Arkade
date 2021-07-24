#include "FormControl.h"
#include "SystemMessages.h"

namespace arkade {

	arkade::FormControl::FormControl(uint32_t screen_x, uint32_t screen_y, Size size)
	{
		_x = screen_x;
		_y = screen_y;
		_size = size;
		_margin = {0,0};
		_click_action = nullptr;
	}

	arkade::FormControl::~FormControl()
	{
	}

	uint32_t FormControl::id()
	{
		return _id;
	}

	uint32_t FormControl::x()
	{
		return _x;
	}

	uint32_t FormControl::y()
	{
		return _y;
	}

	void FormControl::position(uint32_t screen_x, uint32_t screen_y)
	{
		_x = screen_x;
		_y = screen_y;
	}

	Size FormControl::size()
	{
		return _size;
	}

	void FormControl::size(Size size)
	{
		_size.x = size.x;
		_size.y = size.y;
	}

	Size FormControl::border_margin()
	{
		return _margin;
	}
	void FormControl::border_margin(Size border_margin)
	{
		_margin = border_margin;
	}


	bool FormControl::is_point_on_control(uint32_t screen_x, uint32_t screen_y)
	{
		if (screen_x >= (_x - _margin.x) && screen_x <= _x + _size.x + _margin.x)
		{
			if (screen_y >= (_y - _margin.y) && screen_y <= _y + _size.y + _margin.y)
				return true;
		}
		return false;
	}

	void FormControl::on_click(std::function<void()> click_action)
	{
		_click_action = click_action;
	}

	void FormControl::on_setup()
	{
		_mouse_up_interval = new IntervalLogic(100, 1, false);
	}

	void FormControl::on_check_input(InputManager* ptr_input_manager)
	{
		uint32_t mouse_x = ptr_input_manager->mouse_x();
		uint32_t mouse_y = ptr_input_manager->mouse_y();

		bool is_mouse_over = is_point_on_control(mouse_x, mouse_y);

		if (is_mouse_over)
		{
			on_mouse_over(mouse_x, mouse_y);
			if (ptr_input_manager->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT))
			{
				on_mouse_down(mouse_x, mouse_y);
				_mouse_up_interval->restart();
				click(mouse_x, mouse_y);
			}
		}
	}

	void FormControl::on_update()
	{
		_mouse_up_interval->tick([this](uint32_t step) {
			this->on_mouse_up();
		});
	}

	void FormControl::click(uint32_t mouse_x, uint32_t mouse_y)
	{
		if (_click_action)
			_click_action();
	}

	void FormControl::set_id(uint32_t id)
	{
		_id = id;
	}

}