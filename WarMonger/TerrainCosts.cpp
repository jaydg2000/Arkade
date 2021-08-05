#include "TerrainCosts.h"
#include "TileSet.h"

TerrainCosts::TerrainCosts(int32_t land, int32_t forest, int32_t mountain, int32_t river, int32_t water)
{
	_land = land;
	_forest = forest;
	_mountain = mountain;
	_river = river;
	_water = water;
}

TerrainCosts::~TerrainCosts()
{
}

int32_t TerrainCosts::cost(uint16_t tile_type_id)
{
	if (TileSet::is_land)
		return _land;
	if (TileSet::is_forest)
		return _forest;
	if (TileSet::is_mountain)
		return _mountain;
	if (TileSet::is_water)
		return _water;
	if (TileSet::is_river)
		return _river;
}
