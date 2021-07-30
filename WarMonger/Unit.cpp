#include "Unit.h"

Unit::Unit(uint16_t type_id, RGB background_color, Sprite* unit_sprite)
{
	_background_color = background_color;
	_unit_sprite = unit_sprite;
	_type_id = type_id;
}

Unit::~Unit()
{
}

void Unit::x(uint32_t x)
{
	_x = x;
}

void Unit::y(uint32_t y)
{
	_y = y;
}

uint32_t Unit::x()
{
	return _x;
}

uint32_t Unit::y()
{
	return _y;
}

void Unit::position(uint32_t x, uint32_t y)
{
	_x = x;
	_y = y;
}
