#pragma once
#include <map>
#include "Tile.h"

using namespace arkade;
using namespace std;

class TileSet
{
public:
	TileSet();
	~TileSet();
	
	Tile*					tile(uint16_t tile_id);

private:
	map<uint16_t, Tile*>	_tiles;
};

