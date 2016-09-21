#pragma once
#include <SDL.h>

namespace arkade {

#define MOUSE_BUTTON_ID uint16_t
#define MOUSE_BUTTON_INPUT_LEFT  1
#define MOUSE_BUTTON_INPUT_RIGHT 2

	class InputManager {
	public:
		InputManager();
		~InputManager();

		void				update();
		bool				is_key_pressed(uint8_t key_scan_code);
		bool				is_mouse_button_pressed(MOUSE_BUTTON_ID button);

	private:
		bool				m_mouse_button_left_down;
		bool				m_mouse_button_right_down;
	};

}