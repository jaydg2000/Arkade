#include "stdafx.h"
#include "Collidable.h"


Collidable::Collidable()
{
	m_collision_detection_enabled = true;
}


Collidable::~Collidable()
{
	for (auto&& rect : m_collision_rects) {
		delete rect;
	}
}

void Collidable::collision_enabled(bool enabled) {
	m_collision_detection_enabled = enabled;
}

bool Collidable::collision_enabled() {
	return m_collision_detection_enabled;
}

bool Collidable::has_collided(Rect* source_rect) {
	for each(Rect* collision_rect in m_collision_rects) {
		if (SDL_HasIntersection(source_rect, collision_rect) == SDL_TRUE)
			return true;
	}
	return false;
}

void Collidable::add_collision_region(uint32_t x, uint32_t y, uint32_t w, uint32_t h) {
	Rect* r = new Rect();
	r->x = x;
	r->y = y;
	r->w = w;
	r->h = h;

	m_collision_rects.push_back(r);
}

list<Rect*> Collidable::collision_regions() {
	return m_collision_rects;
}