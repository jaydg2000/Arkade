#include "AsteroidSprite.h"
#include <Random.h>

AsteroidSprite::AsteroidSprite(const char* filename, Size texture_size, uint32_t screen_width, uint32_t screen_height)
	:Sprite(filename, texture_size)
{
	m_speed = Random::rand_int(1,4);
	m_rotation_rate = Random::rand_int(0, 15);
	m_heading = 0;
	m_x_lower_boundary = -500;
	m_y_lower_boundary = -500;
	m_x_upper_boundary = screen_width + 500;
	m_y_upper_boundary = screen_height + 500;
	m_is_out_of_bounds = false;
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

	if (x < m_x_lower_boundary
		|| x > m_x_upper_boundary
		|| y < m_y_lower_boundary
		|| y > m_y_upper_boundary) {

		Message* message = obtain_message();
		message->set(MESSAGE_TYPE_ASTEROID_OUT_OF_BOUNDS, nullptr, this);
		send_message(message);
		m_is_out_of_bounds = true;
	}
}