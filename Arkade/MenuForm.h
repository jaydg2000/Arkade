#pragma once
#include <vector>
#include <functional>
#include "ArkadeTypes.h"
#include "Form.h"
#include "Button.h"
#include "Font.h"

namespace arkade {
	class MenuForm
	{
	public:
		MenuForm(Size window_size, Font* ptr_font);
		~MenuForm();

		void					add_menu_item(const char* title, std::function<void()> click_action);
		Form*					form();
		void					show();		
		void					enable();
		void					hide();
		void					disable();

	private:
		Form*					_form;
		Font*					_ptr_button_font;
		vector<Button*>			_menu_items;
		Size					_window_size;

		void					_adjust();
	};
}