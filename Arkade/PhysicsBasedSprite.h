#pragma once
#include "Sprite.h"

#define ACCELERATION_MAGNITUDE .0050f
#define FRICTION_MAGNITUDE     .0050f

#define ACCELERATION_MAXIMUM    1.0f
#define ACCELERATION_MINIMUM    0.0f

namespace arkade {

	class PhysicsBasedSprite : public Sprite {
	public:
		PhysicsBasedSprite(const char* filename, Size& frame_size);
		~PhysicsBasedSprite();

		virtual void		accelerate();
		virtual void		friction();
		virtual void		stop();

		virtual void		on_update() override;

	private:
		float				m_speed;
		float				m_velocity_x;
		float				m_velocity_y;
		float				m_movementHeadingInRadians;
	};

}