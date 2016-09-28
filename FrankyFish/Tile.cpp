#include "stdafx.h"
#include "Tile.h"

Tile::Tile() {}

Tile::Tile(TileDef* ptr_tile_definition, Flip flip, uint16_t rotation) {
	m_tile_definition = ptr_tile_definition;
	m_flip = flip;
	m_rotation = rotation;
}


Tile::~Tile() {
}

uint32_t Tile::tile_type() {
	if (m_tile_definition)
		return m_tile_definition->tile_type();
	else
		return 0;
}

Texture* Tile::texture() {
	return m_tile_definition->texture();
}

Size* Tile::size() {
	return m_tile_definition->size();
}

void Tile::flip(Flip render_flip) {
	m_flip = render_flip;
}

Flip Tile::flip() {
	return m_flip;
}

void Tile::rotation(uint16_t rotation) {
	m_rotation = rotation;
}

uint16_t Tile::rotation() {
	return m_rotation;
}
