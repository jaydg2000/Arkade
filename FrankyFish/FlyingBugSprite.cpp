#include "FlyingBugSprite.h"


FlyingBugSprite::FlyingBugSprite(const char* file_name, const Size& frame_size, uint32_t points)
	:RewardSprite(file_name, frame_size, points)
{
	m_speed = Random::rand_float(1.0f, 4.0f);
}


FlyingBugSprite::~FlyingBugSprite()
{
}

void FlyingBugSprite::on_update()
{
	//this->move_relative_x(-m_speed);
}
