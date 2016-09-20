#include "stdafx.h"
#include "GameSprite.h"


GameSprite::GameSprite(const char* file_name, Size& frame_size)
	:Sprite(file_name, frame_size)
{
	m_direction = SPRITE_DIRECTION_LEFT;
}


GameSprite::~GameSprite()
{
}
