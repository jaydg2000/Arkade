#pragma once
#include <SDL.h>

namespace arkade {

	class Keyboard {
	public:
		Keyboard();
		~Keyboard();

		bool				is_key_pressed(uint8_t key_scan_code);
	};

}