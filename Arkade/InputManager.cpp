#include "InputManager.h"

namespace arkade {

	InputManager::InputManager() {
		m_device_close = false;
	}


	InputManager::~InputManager() {
	}

	void InputManager::update() {
		m_mouse_button_left_down = false;
		m_mouse_button_right_down = false;

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LMASK) {
					m_mouse_button_left_down = true;
				}
				else if (event.button.button == SDL_BUTTON_RMASK) {
					m_mouse_button_right_down = true;
				}
			}
			if (event.type == SDL_MOUSEMOTION) {
				m_mouse_x = event.motion.x;
				m_mouse_y = event.motion.y;
			}
			if (event.type == SDLK_AC_BACK) {
				m_device_close = true;
			}
		}
	}

	bool InputManager::is_key_pressed(uint8_t key_scan_code) {
		const uint8_t* keys = SDL_GetKeyboardState(NULL);
		bool is_pressed = keys[key_scan_code] == 1;
		return is_pressed;
	}

	bool InputManager::is_mouse_button_pressed(MOUSE_BUTTON_ID button) {
		if (button == MOUSE_BUTTON_INPUT_LEFT)
			return m_mouse_button_left_down;
		if (button == MOUSE_BUTTON_INPUT_RIGHT)
			return m_mouse_button_right_down;
	}

	uint32_t InputManager::mouse_x() {
		return m_mouse_x;
	}

	uint32_t InputManager::mouse_y() {
		return m_mouse_y;
	}
	
	bool InputManager::is_device_closing_app() {
		return m_device_close;
	}

}