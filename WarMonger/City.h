#pragma once
#include <ArkadeTypes.h>
#include <RGB.h>

using namespace arkade;

class City
{
public:
	City(uint32_t map_x, uint32_t map_y);
	~City();

	void							production_type(uint32_t unit_type_id);
	uint32_t						production_type();
	void							back_color(RGB color);
	uint32_t						x();
	uint32_t						y();

private:
	uint32_t						_map_x,_map_y;
	uint32_t						_production_type;
	uint32_t						_production_turn;
	RGB								_back_color;
};

