#include "RGB.h"

namespace arkade {

	RGB::RGB() {}

	RGB::RGB(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	RGB::~RGB()
	{
	}
	

	const RGB RGB::Black(0x00,0x00,0x00);
	const RGB RGB::Magenta(0xFF,0x00,0xFF);
}