#include "stdafx.h"
#include "SharkSprite.h"


SharkSprite::SharkSprite()
	:SwimmingSprite("res/sprites/sprite_shark.png", make_size(406, 227))
{
	animator(new ForwardAnimator(6, 80));
	animator()->current_frame(Random::rand_int(0, 5));
	type(SPRITE_TYPE_PREDATOR);
}


SharkSprite::~SharkSprite()
{
}

Rect* SharkSprite::collision_rect() {
	Rect* ptr_rect = destination_rect();
	m_collision_rect.x = ptr_rect->x + 65;
	m_collision_rect.y = ptr_rect->y + 90;
	m_collision_rect.w = 200;
	m_collision_rect.h = 100;

	return &m_collision_rect;
}