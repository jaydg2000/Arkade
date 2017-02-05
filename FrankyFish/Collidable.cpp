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

//bool Collidable::has_collided(Rect* source_rect) {
//	Rect local_rect;
//
//	for each(Rect* collision_rect in m_collision_rects) {
//		local_rect.x = x + collision_rect->x;
//		local_rect.y = y + collision_rect->y;
//		local_rect.w = collision_rect->w;
//		local_rect.h = collision_rect->h;
//		if (SDL_HasIntersection(source_rect, &local_rect) == SDL_TRUE)
//			return true;
//	}
//	return false;
//}

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

void Collidable::flip_region(Rect* rect, bool flip_h, bool flip_v) {

}