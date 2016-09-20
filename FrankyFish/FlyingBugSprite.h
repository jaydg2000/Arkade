#pragma once
#include <Random.h>
#include "GameSprite.h"

class FlyingBugSprite : public GameSprite
{
public:
	FlyingBugSprite(const char* file_name, Size& frame_size);
	~FlyingBugSprite();

	virtual void					on_update() override;

private:
	float							m_speed;
};

