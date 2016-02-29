#include "AsteroidSprite.h"
#include "Asteroids.h"
#include <Random.h>

AsteroidSprite::AsteroidSprite(const char* filename, Size texture_size, BoundsChecker* ptr_bounds_checker, Sound* ptr_sound_explosion)
	:Sprite(filename, texture_size)
{
	type(SPRITE_TYPE_ASTEROID);
	m_speed = Random::rand_int(1,4);
	m_rotation_rate = Random::rand_int(0, 15);
	m_heading = 0;
	m_is_out_of_bounds = false;
	m_ptr_bounds_checker = ptr_bounds_checker;
	m_ptr_sound_explosion = ptr_sound_explosion;
}


AsteroidSprite::~AsteroidSprite()
{
}

void AsteroidSprite::heading(float heading) {
	m_heading = heading;
}

void AsteroidSprite::on_update() {
	if (m_is_out_of_bounds)
		return;

	float x = position_x();
	float y = position_y();

	move_at_heading(m_heading, m_speed);
	rotation(rotation() + m_rotation_rate);

	if (m_ptr_bounds_checker->is_out_of_bounds(x, y))
		send_dead_message();
}

void AsteroidSprite::on_pool_obtain() {
	m_is_out_of_bounds = false;
}

void AsteroidSprite::send_dead_message() {
	Message* message = obtain_message();
	message->set(MESSAGE_TYPE_ASTEROID_DEAD, nullptr, this);
	send_message(message);
	m_is_out_of_bounds = true;
}

void AsteroidSprite::send_explosion_message() {
	Message* message = obtain_message();
	
	PointF* position = new PointF();
	position->x = position_x();
	position->y = position_y();
	message->set(MESSAGE_TYPE_CREATE_EXPLOSION, nullptr, position);
	send_message(message);
}

void AsteroidSprite::on_collision(Sprite* ptr_colliding_sprite) {
	if (ptr_colliding_sprite->type() == SPRITE_TYPE_LASER) {
		send_dead_message();
		send_explosion_message();
		m_ptr_sound_explosion->play_sound();
	}
}