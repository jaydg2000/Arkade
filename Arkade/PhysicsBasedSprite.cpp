#include "PhysicsBasedSprite.h"
#include "MathUtil.h"

namespace arkade {

	PhysicsBasedSprite::PhysicsBasedSprite(const char* filename, Size& frame_size)
		: Sprite(filename, frame_size)
	{
		m_speed = 0.0f;
		m_velocity_x = 0.0f;
		m_velocity_y = 0.0f;
	}

	PhysicsBasedSprite::~PhysicsBasedSprite()
	{
	}

	void PhysicsBasedSprite::on_update() {
		move_relative_x(m_velocity_x);
		move_relative_y(m_velocity_y);
	}

	void PhysicsBasedSprite::accelerate() {

		if (m_speed < ACCELERATION_MAXIMUM)
			m_speed += ACCELERATION_MAGNITUDE;

		float heading = rotation();
		m_movementHeadingInRadians = MathUtil::degrees_to_radians(heading);
		m_velocity_y += -(m_speed * cos(m_movementHeadingInRadians));
		m_velocity_x += m_speed * sin(m_movementHeadingInRadians);
	}

	void PhysicsBasedSprite::friction() {
		m_speed = 0.0f;

		if (m_velocity_x < 0) {
			m_velocity_x += FRICTION_MAGNITUDE;
			if (m_velocity_x > 0)
				m_velocity_x = 0;
		}
		if (m_velocity_x > 0) {
			m_velocity_x -= FRICTION_MAGNITUDE;
			if (m_velocity_x < 0)
				m_velocity_x = 0;
		}

		if (m_velocity_y < 0) {
			m_velocity_y += FRICTION_MAGNITUDE;
			if (m_velocity_y > 0)
				m_velocity_y = 0;
		}
		if (m_velocity_y > 0) {
			m_velocity_y -= FRICTION_MAGNITUDE;
			if (m_velocity_y < 0)
				m_velocity_y = 0;
		}
	}


	void PhysicsBasedSprite::stop() {
		m_speed = 0;
		m_velocity_x = 0;
		m_velocity_y = 0;
		rotation(0);
	}
}