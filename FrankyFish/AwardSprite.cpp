#include "stdafx.h"
#include "AwardSprite.h"


AwardSprite::AwardSprite(const char* filename, Size& frame_size)
	:SwimmingSprite(filename, frame_size)
{
	m_points = 0;
	this->type(SPRITE_TYPE_REWARD);
}

AwardSprite::~AwardSprite()
{
}

uint32_t AwardSprite::points() {
	return m_points;
}

void AwardSprite::points(uint32_t points) {
	m_points = points;
}