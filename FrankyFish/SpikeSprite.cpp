#include "SpikeSprite.h"


SpikeSprite::SpikeSprite()
	: GameSprite("res/sprites/spike.png", make_size(65, 112))
{
	type(SPRITE_TYPE_PREDATOR);
	m_speed = Random::rand_float(1.5f, 3.0f);
	collision_dim(10, 15, 35, 85);
}


SpikeSprite::~SpikeSprite()
{
}

void SpikeSprite::on_update() {
	Camera* ptr_camera = Camera::instance();
	float distance_from_camera = position_x() - ptr_camera->position_x();

	if (distance_from_camera < SPIKE_START_DISTANCE_FROM_CAMERA
		&& distance_from_camera > SPIKE_END_DISTANCE_FROM_CAMERA) {

		if (position_y() < SPIKE_MAXIMUM_Y) {
			move_relative_y(m_speed);
		}
	}
}
