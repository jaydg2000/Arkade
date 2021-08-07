#pragma once
#include <ArkadeTypes.h>

class TerrainCosts
{
public:
	TerrainCosts() {};
	~TerrainCosts();
	
	int32_t				cost(uint16_t tile_type_id);

	int32_t				_land;
	int32_t				_forest;
	int32_t				_mountain;
	int32_t				_water;
	int32_t				_river;
};

