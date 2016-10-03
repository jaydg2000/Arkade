#include "stdafx.h"
#include "Tile.h"

Tile::Tile() {}

Tile::Tile(TileDef* ptr_tile_definition, Flip flip, uint16_t rotation) {
	m_tile_definition = ptr_tile_definition;
	m_flip = flip;
	m_rotation = rotation;
	m_x = 0.0f;
	m_y = 0.0f;
}


Tile::~Tile() {
}

void Tile::position(float x, float y) {
	m_x = x;
	m_y = y;
}

float Tile::position_x() {
	return m_x;
}

float Tile::position_y() {
	return m_y;
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

bool Tile::have_collided(Rect* source_rect) {
	Rect local_rect;
	Rect flipped_rect;

	// loose detection
	local_rect.x = m_x;
	local_rect.y = m_y;
	local_rect.w = m_tile_definition->size()->x;
	local_rect.h = m_tile_definition->size()->y;
	if (!SDL_HasIntersection(source_rect, &local_rect) == SDL_TRUE)
		return false;


	// tight detection
	list<Rect*>* collision_rect_list = m_tile_definition->collision_regions();
	for each (Rect* collision_rect in *collision_rect_list) {

		flip_collision_region(collision_rect, &flipped_rect);

		local_rect.x = m_x + flipped_rect.x;
		local_rect.y = m_y + flipped_rect.y;
		local_rect.w = flipped_rect.w;
		local_rect.h = flipped_rect.h;
		if (SDL_HasIntersection(source_rect, &local_rect) == SDL_TRUE)
			return true;
	}

	return false;
}

list<Rect*>* Tile::collision_regions() {
	list<Rect*>* new_list = new list<Rect*>();

	for each (Rect* rect in *m_tile_definition->collision_regions()) {
		Rect* new_rect = new Rect();
		flip_collision_region(rect, new_rect);
		new_list->push_back(new_rect);
	}

	return new_list;
}

void Tile::flip_collision_region(Rect* rect, Rect* dest_rect) {
	float new_y = rect->y;
	float new_x = rect->x;

	if(m_flip == FLIP_VERTICAL || m_rotation == 180.0f)
		new_y = size()->y - (rect->y + rect->h);
	if(m_flip == FLIP_HORIZONTAL || m_rotation == 180.0f)
		new_x = size()->x - (rect->x + rect->w);
	dest_rect->x = new_x;
	dest_rect->y = new_y;
	dest_rect->w = rect->w;
	dest_rect->h = rect->h;
}