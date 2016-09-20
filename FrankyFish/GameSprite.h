#pragma once
#include <Sprite.h>
#include "SpriteTypes.h"

using namespace arkade;

class GameSprite : public Sprite	
{
public:
	GameSprite(const char* file_name, Size& frame_size);
	~GameSprite();

private:
	uint16_t					m_direction;
};

