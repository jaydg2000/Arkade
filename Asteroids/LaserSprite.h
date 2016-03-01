#pragma once
#include <Sprite.h>
#include "BoundsChecker.h"

#define MESSAGE_TYPE_LASER_DEAD 20002

using namespace arkade;

class LaserSprite : public Sprite {
public:
	LaserSprite(BoundsChecker* ptr_bounds_checker);
	~LaserSprite();

protected:
	void				on_update();
	void				on_pool_obtain();
	void				on_collision(Sprite* ptr_colliding_sprite);

private:
	BoundsChecker*		m_ptr_bounds_checker;
	Timer				m_timer;
	bool				m_is_out_of_bounds;

	void				send_dead_message();

};

