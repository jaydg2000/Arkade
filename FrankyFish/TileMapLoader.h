#pragma once

#include <ArkadeTypes.h>
#include "Tile.h"
#include "TileSet.h"
#include "TileMap.h"

#define TILE_MAP_WIDTH 2000
#define TILE_MAP_HEIGHT 10

class TileMapLoader
{
public:
	TileMapLoader();
	~TileMapLoader();

	TileMap*					load_map(TileSet* tile_set);
};

