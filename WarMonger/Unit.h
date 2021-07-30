#pragma once
#include <ArkadeTypes.h>
#include <TextureCache.h>
#include <Sprite.h>

using namespace arkade;

#define UNIT_INFANTRY				1000
#define UNIT_MECHANIZED_INFANTRY	1010

class Unit
{
public:
	Unit(uint16_t type_id, RGB background_color, Sprite* unit_sprite);
	~Unit();

	void							x(uint32_t x);
	void							y(uint32_t y);
	uint32_t						x();
	uint32_t						y();
	void							position(uint32_t x, uint32_t y);

private:
	uint16_t						_type_id;
	uint32_t						_x, _y;
	RGB								_background_color;
	Sprite*							_unit_sprite;
};

