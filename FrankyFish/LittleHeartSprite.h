#pragma once
#include "GameSprite.h"

class LittleHeartSprite : public GameSprite
{
public:
	LittleHeartSprite();
	~LittleHeartSprite();

	virtual void			on_update() override;
	void					init(float x, float y, float heading);

private:
	Timer					m_life_timer;
	float					m_heading_to_move;
};

