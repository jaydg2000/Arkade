#pragma once
#include <Timer.h>
#include <Random.h>
#include <math.h>
#include "SpriteTypes.h"
#include "GameSprite.h"

using namespace arkade;

class SwimmingSprite :
	public GameSprite
{
public:
	SwimmingSprite(const char* filename, Size& frame_size);
	~SwimmingSprite();

	void							speed(float speed);
	float							speed();

	virtual void					on_update() override;


private:
	Timer							m_swim_timer;
	float							m_speed;
	float							m_y_sine_amplitude;
	
	void							wobble_y();

};
