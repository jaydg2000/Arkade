#include "ToothyFishThreeSprite.h"


ToothyFishThreeSprite::ToothyFishThreeSprite()
	:SwimmingSprite("res/sprites/sprite_toothy_fish_3.png", make_size(234, 54))
{
	animator(new ForwardAnimator(7, 100));
	animator()->current_frame(Random::rand_int(0, 6));
	type(SPRITE_TYPE_PREDATOR);
	collision_dim(0, 20, 80, 30);
}


ToothyFishThreeSprite::~ToothyFishThreeSprite()
{
}
