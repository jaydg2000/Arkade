#include "stdafx.h"
#include "ToothyFishThreeSprite.h"


ToothyFishThreeSprite::ToothyFishThreeSprite()
	:SwimmingSprite("res/sprites/sprite_toothy_fish_3.png", make_size(234, 54))
{
	animator(new ForwardAnimator(7, 100));
	animator()->current_frame(Random::rand_int(0, 6));
	type(SPRITE_TYPE_PREDATOR);
}


ToothyFishThreeSprite::~ToothyFishThreeSprite()
{
}
