#include "stdafx.h"
#include "JellyFishSprite.h"


JellyFishSprite::JellyFishSprite()
	: GameSprite("res/sprites/sprite_jelly.png", make_size(138, 244))
{
	type(SPRITE_TYPE_PREDATOR);
	animator(new ForwardAnimator(10, 75));
	animator()->current_frame(Random::rand_int(0, 9));
	m_speed = Random::rand_float(.5f, 2.0f);
	collision_dim(18, 25, 105, 210);
	m_is_moving_up = Random::rand_bool();
}


JellyFishSprite::~JellyFishSprite()
{
}

void JellyFishSprite::on_update() {
	Camera* ptr_camera = Camera::instance();
	float distance_from_camera = position_x() - ptr_camera->position_x();

	if (   distance_from_camera < JELLYFISH_START_DISTANCE_FROM_CAMERA 
		&& distance_from_camera > JELLYFISH_END_DISTANCE_FROM_CAMERA) {

		if (m_is_moving_up) {
			if (position_y() > JELLYFISH_MINIMUM_Y) {
				move_relative_y(-m_speed);
			}
			else {
				m_is_moving_up = false;
			}
		}
		else {
			if (position_y() < JELLYFISH_MAXIMUM_Y) {
				move_relative_y(m_speed);
			}
			else {
				m_is_moving_up = true;
			}
		}
	}
}