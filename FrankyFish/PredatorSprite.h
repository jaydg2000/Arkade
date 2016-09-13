#pragma once

#include <Sprite.h>
#include <Timer.h>
#include <Random.h>
#include "FishGame.h"

using namespace arkade;

class PredatorSprite : public Sprite
{
public:
	PredatorSprite(const char* filename, Size& frame_size);
	~PredatorSprite();

	void							swim();
	void							go_to_start_position();

	void							speed(float speed);
	float							speed();
private:
	Timer							m_swim_timer;

	float							m_speed;

};

