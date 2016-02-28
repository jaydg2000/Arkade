#pragma once
#include "Sprite.h"

using namespace arkade;

#define MESSAGE_TYPE_ASTEROID_OUT_OF_BOUNDS 20001

class AsteroidSprite :
	public Sprite {
public:
	AsteroidSprite(const char* filename, Size texture_size, uint32_t screen_width, uint32_t screen_height);
	~AsteroidSprite();

	void			heading(float heading);
	virtual void	on_update();

private:
	float			m_heading;
	float			m_speed;
	float			m_rotation_rate;
	int32_t			m_x_lower_boundary;
	int32_t			m_y_lower_boundary;
	int32_t			m_x_upper_boundary;
	int32_t			m_y_upper_boundary;
	bool			m_is_out_of_bounds;
};

