#include "stdafx.h"
#include "TileMapLoader.h"
#include "Scene1TileData.h"


TileMapLoader::TileMapLoader()
{
}


TileMapLoader::~TileMapLoader()
{
}

TileMap* TileMapLoader::load_map(TileSet* tile_set) {
	TileMap* map = new TileMap();
	int row = 0;
	int col = 0;
	int item_type = 0;
	int flip_x = 0;
	int flip_y = 0;

	int* dptr = scene_tiles;

	for (int count = 0; count < TILES_LENGTH; count++) {
		col = *dptr;
		row = *(dptr + 1);
		item_type = *(dptr + 2);
		flip_x = *(dptr + 3);
		flip_y = *(dptr + 4);

		dptr += 5;

		TileDef* tile_def = tile_set->find_tile(item_type);
		Flip flip;
		uint16_t rotation = 0;

		if (flip_x && flip_y) {
			flip = FLIP_NONE;
			rotation = 180.0f;
		}
		else if (flip_x && !flip_y) {
			flip = FLIP_HORIZONTAL;
		}
		else if (!flip_x && flip_y) {
			flip = FLIP_VERTICAL;
		}
		else {
			flip = FLIP_NONE;
		}

		if (item_type) {
			Tile* tile = new Tile(tile_def, flip);
			tile->rotation(rotation);
			map->tile_at(col, row, tile);

			//float tile_render_x = col * TILE_WIDTH;
			//float tile_render_y = row * TILE_HEIGHT;
			//tile->position(tile_render_x, tile_render_y);
		}

		row++;

		if (row >= TILE_MAP_HEIGHT) {
			col++;
			row = 0;
		}
	}

	return map;
}

