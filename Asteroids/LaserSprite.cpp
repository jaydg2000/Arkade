#include "LaserSprite.h"



LaserSprite::LaserSprite()
	: Sprite("res/images/player_fire.png", make_size(9, 16))
{
}


LaserSprite::~LaserSprite()
{
}

void LaserSprite::on_update()
{
	move_at_heading(rotation(), 15);
}

