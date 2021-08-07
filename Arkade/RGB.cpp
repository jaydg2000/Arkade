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
	

	const RGB RGB::Black      (0x00, 0x00, 0x00);
	const RGB RGB::Magenta    (0xFF, 0x00, 0xFF);
	const RGB RGB::White      (0xFF, 0xFF, 0xFF);
	const RGB RGB::Blue       (0x00, 0x00, 0xFF);
	const RGB RGB::Yellow     (0xFF, 0xF7, 0x00);
	const RGB RGB::Green      (0x00, 0xFF, 0x00);
	const RGB RGB::DarkGreen  (0x00, 0xAD, 0x09);
	const RGB RGB::LightGray  (0xC4, 0xC4, 0xC2);
	const RGB RGB::SkyBlue    (0x39, 0xb3, 0xfa);
}