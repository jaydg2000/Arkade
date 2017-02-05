#include "TileMapRepository.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

TileMapRepository::TileMapRepository() {
}


TileMapRepository::~TileMapRepository() {
}

TileMap* TileMapRepository::load_map(const char* m_psz_filename, TileSet* tile_set) {
	TileMap* map = new TileMap();	
	uint32_t row = 0;
	uint32_t col = 0;
	
	ifstream file(m_psz_filename);
	if (file.is_open()) {
		string line;
		while (!file.eof()) {
			file >> line;
			istringstream ss(line);
			string part;

			getline(ss, part, ',');

			if (part == "-") {
				file.close();
				return map;
			}

			int item_type = atoi(part.c_str());
			getline(ss, part, ',');
			int flip_x = atoi(part.c_str());
			getline(ss, part, ',');
			int flip_y = atoi(part.c_str());

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
	}
	file.close();

	return map;
}
