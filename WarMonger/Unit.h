#pragma once
#include <ArkadeTypes.h>
#include <TextureCache.h>
#include <Sprite.h>
#include "TiledMap.h"
#include "TerrainCosts.h"
#include "UnitSpecification.h""

using namespace arkade;


#define UNIT_INFANTRY				1000
#define UNIT_MECHANIZED_INFANTRY	1010

#define CATEGORY_LAND				1
#define CATEGORY_AIR				2
#define CATEGORY_SEA				3

class Unit
{
public:
	Unit(
		uint16_t type_id, 
		RGB background_color, 
		string name,
		UnitSpecification* specification);
	~Unit();

	void							x(uint32_t x);
	void							y(uint32_t y);
	uint32_t						x();
	uint32_t						y();
	void							position(uint32_t x, uint32_t y);
	Sprite*							sprite();
	RGB								color();
	void							color(RGB color);
	void							map(TiledMap* map);
	TerrainCosts*					terrain_costs();
	void							move(Point point);
	const char*						name();
	uint8_t							category();
	void							dug_in(bool is_dug_in);
	bool							is_dug_in();

private:
	UnitSpecification*				_specification;
	std::string						_name;
	uint16_t						_type_id;
	uint32_t						_x, _y;
	uint32_t						_remaining_strength;
	RGB								_background_color;
	TiledMap*						_map;
	queue<Point>*					_movement_points;
	bool							_is_dug_in;
};

