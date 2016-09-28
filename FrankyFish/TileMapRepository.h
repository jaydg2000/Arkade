#pragma once

#include <ArkadeTypes.h>
#include "Tile.h"
#include "TileSet.h"
#include "TileMap.h"

#define TILE_MAP_WIDTH 10000
#define TILE_MAP_HEIGHT 10

class TileMapRepository {

public:
	TileMapRepository();
	~TileMapRepository();

	TileMap*					load_map(const char* m_psz_filename, TileSet* tile_set);	
};

