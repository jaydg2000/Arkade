#pragma once
#include <map>
#include "Tile.h"

using namespace arkade;
using namespace std;

#define TILE_WATER_1    101
#define TILE_LAND_1     111
#define TILE_FOREST_1   121
#define TILE_MOUNTAIN_1 131
#define TILE_RIVER_1    141
#define TILE_CITY_1     191

class TileSet
{
public:
	TileSet();
	~TileSet();
	
	Tile*					tile(uint16_t tile_id);

private:
	map<uint16_t, Tile*>	_tiles;
};

