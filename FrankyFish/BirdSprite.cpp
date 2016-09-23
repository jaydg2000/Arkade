#include "stdafx.h"
#include "BirdSprite.h"


BirdSprite::BirdSprite()
	: GameSprite("res/sprites/sprite_bird3.png", make_size(300, 370))
{
	animator(new ForwardAnimator(12, 50));
	animator()->current_frame(Random::rand_int(0, 11));
	type(SPRITE_TYPE_PREDATOR);
}


BirdSprite::~BirdSprite()
{
}
