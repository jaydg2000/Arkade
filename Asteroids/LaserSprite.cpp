#include "LaserSprite.h"
#include "Asteroids.h"

#define LASER_SPEED 11

LaserSprite::LaserSprite(BoundsChecker* ptr_bounds_checker)
	: Sprite("res/images/player_fire.png", make_size(9, 16))
{
	type(SPRITE_TYPE_LASER);
	m_ptr_bounds_checker = ptr_bounds_checker;
	m_is_out_of_bounds = false;
}


LaserSprite::~LaserSprite()
{
}

void LaserSprite::on_pool_obtain() {
	m_is_out_of_bounds = false;
	m_timer.start(1000);
}

void LaserSprite::on_update()
{
	if (m_is_out_of_bounds)
		return;

	if (m_timer.has_elapsed()) {
		send_dead_message();
	}

	if (m_ptr_bounds_checker->is_out_of_bounds(position_x(), position_y())) {
		send_dead_message();
		return;
	}

	move_at_heading(rotation(), LASER_SPEED);
}

void LaserSprite::on_collision(Sprite* ptr_colliding_sprite) {
	if (ptr_colliding_sprite->type() == SPRITE_TYPE_ASTEROID) {
		send_dead_message();
	}
}

void LaserSprite::send_dead_message() {
	m_is_out_of_bounds = true;
	Message* message = obtain_message();
	message->set(MESSAGE_TYPE_LASER_DEAD, nullptr, this);
	send_message(message);
}
