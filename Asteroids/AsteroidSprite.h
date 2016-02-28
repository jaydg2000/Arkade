#pragma once
#include "Sprite.h"

using namespace arkade;

class AsteroidSprite :
	public Sprite {
public:
	AsteroidSprite(const char* filename, Size texture_size);
	~AsteroidSprite();

	void			heading(float heading);
	virtual void	on_update();

private:
	float			m_heading;
	float			m_speed;
	float			m_rotation_rate;
};

