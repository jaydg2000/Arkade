#include "stdafx.h"
#include "BugThreeSprite.h"


BugThreeSprite::BugThreeSprite()
	:FlyingBugSprite("res/sprites/sprite_bug_3.png", make_size(79, 80), 15)
{
	animator(new ForwardAnimator(7, 50));
	animator()->current_frame(Random::rand_int(0, 6));
	type(SPRITE_TYPE_REWARD);
}


BugThreeSprite::~BugThreeSprite()
{
}
