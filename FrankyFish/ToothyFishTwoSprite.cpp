#include "stdafx.h"
#include "ToothyFishTwoSprite.h"


ToothyFishTwoSprite::ToothyFishTwoSprite()
	:SwimmingSprite("res/sprites/sprite_toothy_fish_2.png", make_size(79, 68))
{
	animator(new ForwardAnimator(6, 110));
	animator()->current_frame(Random::rand_int(0, 5));
	type(SPRITE_TYPE_PREDATOR);
	collision_dim(5, 15, 40, 40);
}


ToothyFishTwoSprite::~ToothyFishTwoSprite()
{
}
