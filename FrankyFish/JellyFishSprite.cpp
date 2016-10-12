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
}


JellyFishSprite::~JellyFishSprite()
{
}

void JellyFishSprite::on_update() {
	Camera* ptr_camera = Camera::instance();
	float distance_from_camera = position_x() - ptr_camera->position_x();

	if (distance_from_camera < 720) {
		if (position_y() > 150) {
			move_relative_y(-m_speed);
		}
	}
}