#pragma once

#include <Graphics.h>
#include "TileSet.h"
#include "TileDef.h"

class TileSetRepository {
public:
	TileSetRepository();
	~TileSetRepository();

	TileSet*				load_tile_set();

};

