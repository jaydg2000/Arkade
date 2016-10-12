#include "stdafx.h"
#include "SharkSprite.h"


SharkSprite::SharkSprite()
	:SwimmingSprite("res/sprites/sprite_shark.png", make_size(406, 227))
{
	animator(new ForwardAnimator(6, 80));
	animator()->current_frame(Random::rand_int(0, 5));
	type(SPRITE_TYPE_PREDATOR);
	collision_dim(60, 90, 150, 80);
}


SharkSprite::~SharkSprite()
{
}
