#pragma once
#include <ArkadeTypes.h>

class TerrainCosts
{
public:
	TerrainCosts(int32_t land = -1, int32_t forest = -1, int32_t mountain = -1, int32_t river = -1, int32_t water = -1);
	~TerrainCosts();
	
	int32_t				cost(uint16_t tile_type_id);

private:
	int32_t				_land;
	int32_t				_forest;
	int32_t				_mountain;
	int32_t				_water;
	int32_t				_river;
};

