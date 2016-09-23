#include "stdafx.h"
#include "BugTwoSprite.h"


BugTwoSprite::BugTwoSprite()
	:FlyingBugSprite("res/sprites/sprite_bug_2.png", make_size(118, 99), 50)
{
	animator(new ForwardAnimator(7, 50));
	animator()->current_frame(Random::rand_int(0, 6));
	type(SPRITE_TYPE_REWARD);
}


BugTwoSprite::~BugTwoSprite()
{
}
