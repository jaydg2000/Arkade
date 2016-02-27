#include "Keyboard.h"

namespace arkade {

	Keyboard::Keyboard()
	{
	}


	Keyboard::~Keyboard()
	{
	}

	bool Keyboard::is_key_pressed(uint8_t key_scan_code) {
		const uint8_t* keys = SDL_GetKeyboardState(NULL);
		bool is_pressed = keys[key_scan_code] == 1;
		return is_pressed;
	}
}