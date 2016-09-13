#include "stdafx.h"
#include "SharkSprite.h"
#include <OscillatingAnimator.h>

SharkSprite::SharkSprite()
	: PredatorSprite("res/sprites/sprite_shark.png", make_size(152, 88))
{
	this->animator(new OscillatingAnimator(4, 120));
	this->speed(5);
}


SharkSprite::~SharkSprite()
{
}
