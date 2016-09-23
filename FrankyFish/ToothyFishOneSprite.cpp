#include "stdafx.h"
#include "ToothyFishOneSprite.h"


ToothyFishOneSprite::ToothyFishOneSprite()
	:SwimmingSprite("res/sprites/sprite_toothy_fish_1.png", make_size(262, 182))
{
	animator(new ForwardAnimator(8, 90));
	animator()->current_frame(Random::rand_int(0, 7));
	type(SPRITE_TYPE_PREDATOR);
	collision_dim(15, 55, 100, 115);
}


ToothyFishOneSprite::~ToothyFishOneSprite()
{
}
