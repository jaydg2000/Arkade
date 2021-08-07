#include "Unit.h"

Unit::Unit(uint16_t type_id, RGB background_color, string name, UnitSpecification* specification)
{
	_specification = specification;
	_background_color = background_color;
	_type_id = type_id;	
	_movement_points = new queue<Point>();
	_name = name;
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

Sprite* Unit::sprite()
{
	return _specification->_unit_sprite;
}

RGB Unit::color()
{
	return _background_color;
}

void Unit::color(RGB color)
{
	_background_color = color;
}

void Unit::map(TiledMap* map)
{
	_map = map;
}

TerrainCosts* Unit::terrain_costs()
{
	return &(_specification->_movement_profile);
}

void Unit::move(Point point)
{
	_movement_points->push(Point(point));
}

const char* Unit::name()
{
	return _name.c_str();
}

uint8_t Unit::category()
{
	return _specification->_category;
}

void Unit::dug_in(bool is_dug_in)
{
	_is_dug_in = is_dug_in;
}

bool Unit::is_dug_in()
{
	return _is_dug_in;
}
