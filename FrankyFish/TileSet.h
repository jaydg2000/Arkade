#pragma once

#include <list>
#include "TileDef.h"

class TileSet {
public:
	TileSet();
	~TileSet();

	TileDef*			add_tile(uint32_t type_id, Texture* ptr_texture, uint32_t w, uint32_t h);
	TileDef*			find_tile(uint32_t type_id);

private:
	list<TileDef*>		m_tile_defs;
};

