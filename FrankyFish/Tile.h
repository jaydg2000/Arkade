#pragma once

#include <ArkadeTypes.h>
#include "TileDef.h"

using namespace arkade;

class Tile {
public:
	Tile();
	Tile(TileDef* ptr_tile_definition, Flip flip = FLIP_NONE, uint16_t rotation = 0.0f);
	~Tile();

	uint32_t				tile_type();
	Texture*				texture();
	Size*					size();
	void					flip(Flip render_flip);
	Flip					flip();
	void					rotation(uint16_t rotation);
	uint16_t				rotation();

private:
	Flip					m_flip;
	uint16_t				m_rotation;
	TileDef*				m_tile_definition;
};

