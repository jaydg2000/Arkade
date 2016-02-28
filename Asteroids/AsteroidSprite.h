#pragma once
#include "Sprite.h"
#include "BoundsChecker.h"

using namespace arkade;

#define MESSAGE_TYPE_ASTEROID_DEAD 20001

class AsteroidSprite :
	public Sprite {
public:
	AsteroidSprite(const char* filename, Size texture_size, BoundsChecker* ptr_bounds_checker);
	~AsteroidSprite();

	void			heading(float heading);
	virtual void	on_update();
	virtual void	on_collision(Sprite* ptr_colliding_sprite);

private:
	float			m_heading;
	float			m_speed;
	float			m_rotation_rate;
	bool			m_is_out_of_bounds;
	BoundsChecker*	m_ptr_bounds_checker;

	void			send_explosion_message();
	void			send_dead_message();
};

