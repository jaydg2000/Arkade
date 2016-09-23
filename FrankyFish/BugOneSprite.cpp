#include "stdafx.h"
#include "BugOneSprite.h"


BugOneSprite::BugOneSprite()
	: FlyingBugSprite("res/sprites/sprite_bug_1.png", make_size(120, 95), 10)
{
	animator(new ForwardAnimator(5, 50));
	animator()->current_frame(Random::rand_int(0, 4));
	type(SPRITE_TYPE_REWARD);
}


BugOneSprite::~BugOneSprite()
{
}
