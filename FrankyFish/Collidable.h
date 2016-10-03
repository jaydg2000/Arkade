#pragma once

#include <list>
#include <ArkadeTypes.h>

using namespace arkade;
using namespace std;

class Collidable
{
public:
	Collidable();
	~Collidable();

	virtual bool			has_collided(Rect* source_rect) = 0;
	void					add_collision_region(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
	list<Rect*>				collision_regions();
	void					collision_enabled(bool enabled);
	bool					collision_enabled();


private:
	bool					m_collision_detection_enabled;
	list<Rect*>				m_collision_rects;
	void					flip_region(Rect* rect, bool flip_h, bool flip_v);
};

