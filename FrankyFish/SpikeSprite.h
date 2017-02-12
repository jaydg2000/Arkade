#pragma once

#include <Random.h>
#include <Camera.h>
#include "GameSprite.h"

#define SPIKE_START_DISTANCE_FROM_CAMERA  720.0f
#define SPIKE_END_DISTANCE_FROM_CAMERA   -500.0f
#define SPIKE_MAXIMUM_Y					 1000.0f

class SpikeSprite : public GameSprite
{
public:
	SpikeSprite();
	~SpikeSprite();
	
	virtual void				on_update() override;

private:
	float						m_speed;
};

