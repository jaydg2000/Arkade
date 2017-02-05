#pragma once
#include "GameSprite.h"
#include <MessageBroadcaster.h>

class RewardSprite : public GameSprite
{
public:
	RewardSprite(const char* filename, const Size& frame_size, uint32_t points);
	~RewardSprite();

	uint32_t						points();
	void							points(uint32_t points);
	virtual void					on_collision(Sprite* sprite) override;

private:
	uint32_t						m_points;
};

