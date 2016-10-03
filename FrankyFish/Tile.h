#pragma once

#include <ArkadeTypes.h>
#include "TileDef.h"

using namespace arkade;

class Tile {
public:
	Tile();
	Tile(TileDef* ptr_tile_definition, Flip flip = FLIP_NONE, uint16_t rotation = 0.0f);
	~Tile();

	void					position(float x, float y);
	float					position_x();
	float					position_y();
	uint32_t				tile_type();
	Texture*				texture();
	Size*					size();
	void					flip(Flip render_flip);
	Flip					flip();
	void					rotation(uint16_t rotation);
	uint16_t				rotation();
	bool					have_collided(Rect* source_rect);
	list<Rect*>*			collision_regions();

private:
	float					m_x;
	float					m_y;
	Flip					m_flip;
	uint16_t				m_rotation;
	TileDef*				m_tile_definition;

	void					flip_collision_region(Rect* rect, Rect* dest_rect);
};

