#include "HeartSprite.h"
#include <StaticAnimator.h>

HeartSprite::HeartSprite()
	: GameSprite("res/sprites/heart.png", make_size(50, 45))
{
	//animator(new StaticAnimator(1));
	type(SPRITE_TYPE_EXTRA);
	collision_dim(5, 5, 40, 40);
}


HeartSprite::~HeartSprite()
{
}
