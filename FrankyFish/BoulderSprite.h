#pragma once

#include <Random.h>
#include <Camera.h>
#include "GameSprite.h"

#define BOUDLER_START_DISTANCE_FROM_CAMERA  720.0f
#define BOULDER_END_DISTANCE_FROM_CAMERA   -500.0f
#define BOULDER_MAXIMUM_Y                  1000.0f

class BoulderSprite : public GameSprite
{
public:
	BoulderSprite();
	~BoulderSprite();

	virtual void				on_update() override;

private:
	float						m_speed;
	float						m_rotation_speed;
	bool						m_rotation_right;
};

