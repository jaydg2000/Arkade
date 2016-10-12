#pragma once

#include <ForwardAnimator.h>
#include <Random.h>
#include <Camera.h>
#include "GameSprite.h"

class JellyFishSprite : public GameSprite
{
public:
	JellyFishSprite();
	~JellyFishSprite();

	virtual void				on_update() override;

private:
	float						m_speed;
};

