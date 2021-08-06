#include "Unit.h"

Unit::Unit(uint16_t type_id, RGB background_color, Sprite* unit_sprite, TerrainCosts* costs)
{
	_background_color = background_color;
	_unit_sprite = unit_sprite;
	_type_id = type_id;	
	_costs = costs;
	_movement_points = new queue<Point>();
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
	return _unit_sprite;
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
	return _costs;
}

void Unit::move(Point point)
{
	_movement_points->push(Point(point));
}
