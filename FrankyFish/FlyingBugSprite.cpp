#include "stdafx.h"
#include "FlyingBugSprite.h"


FlyingBugSprite::FlyingBugSprite(const char* file_name, Size& frame_size)
	:GameSprite(file_name, frame_size)
{
	m_speed = Random::rand_float(1.0f, 4.0f);
}


FlyingBugSprite::~FlyingBugSprite()
{
}

void FlyingBugSprite::on_update()
{
	this->move_relative_x(-m_speed);
}
