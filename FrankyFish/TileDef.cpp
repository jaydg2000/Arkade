#include "stdafx.h"
#include "TileDef.h"


TileDef::TileDef()
{
}


TileDef::~TileDef()
{
}

void TileDef::tile_type(uint32_t type_id) {
	m_tile_type = type_id;
}

uint32_t TileDef::tile_type() {
	return m_tile_type;
}

void TileDef::texture(Texture* ptr_texture) {
	m_ptr_texture = ptr_texture;
}

Texture* TileDef::texture() {
	return m_ptr_texture;
}

Size* TileDef::size() {
	return &m_size;
}

void TileDef::size(uint32_t w, uint32_t h) {
	m_size.x = w;
	m_size.y = h;
}

void TileDef::add_collision_region(uint32_t x, uint32_t y, uint32_t w, uint32_t h) {
	Rect* r = new Rect();
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;

	m_collision_rects.push_back(r);
}

list<Rect*>* TileDef::collision_regions() {
	return &m_collision_rects;
}