#pragma once
#include <SDL.h>

namespace arkade {
	struct RGB {
		
		public:

		RGB();
		RGB(uint8_t r, uint8_t g, uint8_t b, uint8_t a=0xFF);
		~RGB();

		uint8_t			 r;
		uint8_t			 g;
		uint8_t			 b;
		uint8_t			 a;

		static const RGB Magenta;
		static const RGB Black;
		static const RGB White;
		static const RGB Blue;
		static const RGB Green;
		static const RGB Yellow;
		static const RGB DarkGreen;
		static const RGB LightGray;
		static const RGB SkyBlue;
	};
}