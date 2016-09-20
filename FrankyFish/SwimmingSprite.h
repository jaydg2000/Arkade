#pragma once
#include <Sprite.h>
#include <Timer.h>
#include <Random.h>
#include <math.h>
#include "SpriteTypes.h"

using namespace arkade;

class SwimmingSprite :
	public Sprite
{
public:
	SwimmingSprite(const char* filename, Size& frame_size);
	~SwimmingSprite();

	void							swim();
	void							speed(float speed);
	float							speed();


private:
	Timer							m_swim_timer;
	float							m_speed;
	float							m_y_sine_amplitude;
	
	void							wobble_y();

};

