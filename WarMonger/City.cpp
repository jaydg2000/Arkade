#include "City.h"

City::City(uint32_t map_x, uint32_t map_y)
{
	_map_x = map_x;
	_map_y = map_y;
}

City::~City()
{
}

void City::production_type(uint32_t unit_type_id)
{
	_production_type = unit_type_id;
}

uint32_t City::production_type()
{
	return _production_type;
}

void City::back_color(RGB color)
{
	_back_color = color;
}
