#pragma once
#include <Random.h>
#include "RewardSprite.h"

class FlyingBugSprite : public RewardSprite
{
public:
	FlyingBugSprite(const char* file_name, Size& frame_size, uint32_t points);
	~FlyingBugSprite();

	virtual void					on_update() override;

private:
	float							m_speed;
};

