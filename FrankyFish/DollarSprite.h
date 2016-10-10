#pragma once

#include <ArkadeTypes.h>
#include <Random.h>
#include "GameSprite.h"
#include "MessageTypes.h"

class DollarSprite : public GameSprite {
public:
	DollarSprite();
	~DollarSprite();

	virtual void			on_update() override;
	void					init(float x, float y, float heading);

private:
	Timer					m_life_timer;
	float					m_heading_to_move;
};

