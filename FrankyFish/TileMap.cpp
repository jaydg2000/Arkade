#include "stdafx.h"
#include "TileMap.h"


TileMap::TileMap() {
	for (int row = 0; row < TILE_MAP_HEIGHT; row++)
		for (int col = 0; col < TILE_MAP_WIDTH; col++)
			m_map[col][row] = nullptr;
}


TileMap::~TileMap() {
}

void TileMap::tile_at(uint32_t x, uint32_t y, Tile* ptr_tile) {
	m_map[x][y] = *ptr_tile;
}

Tile* TileMap::tile_at(uint32_t x, uint32_t y) {
	return &(m_map[x][y]);
}