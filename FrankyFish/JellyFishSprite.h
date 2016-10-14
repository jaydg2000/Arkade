#pragma once

#include <ForwardAnimator.h>
#include <Random.h>
#include <Camera.h>
#include "GameSprite.h"

#define JELLYFISH_MINIMUM_Y 150.0f
#define JELLYFISH_MAXIMUM_Y 1000.0f
#define JELLYFISH_START_DISTANCE_FROM_CAMERA 720.0f
#define JELLYFISH_END_DISTANCE_FROM_CAMERA -500.0f

class JellyFishSprite : public GameSprite
{
public:
	JellyFishSprite();
	~JellyFishSprite();

	virtual void				on_update() override;

private:
	float						m_speed;
	bool						m_is_moving_up;
};

