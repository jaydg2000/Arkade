#include "BoulderSprite.h"


BoulderSprite::BoulderSprite()
	: GameSprite("res/sprites/boulder.png", make_size(136, 94))
{
	type(SPRITE_TYPE_PREDATOR);
	m_speed = Random::rand_float(.5f, 3.0f);
	m_rotation_speed = Random::rand_float(.1f, 2.0f);
	m_rotation_right = Random::rand_bool();
	collision_dim(10, 25, 114, 54);
}

BoulderSprite::~BoulderSprite()
{
}

void BoulderSprite::on_update() {
	Camera* ptr_camera = Camera::instance();
	float distance_from_camera = position_x() - ptr_camera->position_x();

	if (distance_from_camera < BOUDLER_START_DISTANCE_FROM_CAMERA
		&& distance_from_camera > BOULDER_END_DISTANCE_FROM_CAMERA) {

		if (position_y() < BOULDER_MAXIMUM_Y) {
			move_relative_y(m_speed);
			if (m_rotation_right) {
				rotate_right(m_rotation_speed);
			}
			else {
				rotate_left(m_rotation_speed);
			}
		}
	}
}

