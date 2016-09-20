#pragma once
#include "GameSprite.h"

class CoinSprite : public GameSprite
{
public:
	CoinSprite(const char* file_name, Size& frame_size);
	~CoinSprite();
};

