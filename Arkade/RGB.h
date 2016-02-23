#pragma once
#include <SDL.h>

namespace arkade {
	struct RGB {
		
		public:

		RGB();
		RGB(uint8_t r, uint8_t g, uint8_t b, uint8_t a=0xFF);
		~RGB();

		uint8_t			r;
		uint8_t			g;
		uint8_t			b;
		uint8_t			a;
	};

}