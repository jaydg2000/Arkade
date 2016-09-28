#pragma once

#include "Tile.h"

#define TILE_WIDTH 128
#define TILE_HEIGHT 128
#define TILE_MAP_WIDTH 10000
#define TILE_MAP_HEIGHT 10

class TileMap {
public:
	TileMap();
	~TileMap();

	void				tile_at(uint32_t x, uint32_t y, Tile* ptr_tile);
	Tile*				tile_at(uint32_t x, uint32_t y);

private:
	Tile				m_map[TILE_MAP_WIDTH][TILE_MAP_HEIGHT];
};

