#include "stdafx.h"
#include "TileSet.h"


TileSet::TileSet() {
}


TileSet::~TileSet() {
}

TileDef* TileSet::add_tile(uint32_t type_id, Texture* ptr_texture, uint32_t w, uint32_t h) {
	TileDef* td = new TileDef();
	td->tile_type(type_id);
	td->texture(ptr_texture);
	td->size()->x = w;
	td->size()->y = h;
	m_tile_defs.push_back(td);

	return td;
}

TileDef* TileSet::find_tile(uint32_t type_id) {
	for each (TileDef* td in m_tile_defs) {
		if (td->tile_type() == type_id)
			return td;
	}

	return nullptr;
}