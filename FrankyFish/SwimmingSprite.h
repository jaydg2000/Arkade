#pragma once
#include <Sprite.h>
#include <Timer.h>
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

};

