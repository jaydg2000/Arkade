#include "stdafx.h"
#include "SwimmingSprite.h"


SwimmingSprite::SwimmingSprite(const char* filename, Size& frame_size)
	: GameSprite(filename, frame_size)
{
	m_speed = Random::rand_float(1.0f,2.0f);
	m_y_sine_amplitude = Random::rand_float(0.35f, 0.85f);
	m_swim_timer.start(20);
}


SwimmingSprite::~SwimmingSprite()
{
}

void SwimmingSprite::on_update() {
	if (m_swim_timer.has_elapsed()) {
		this->move_relative_x(-m_speed);
		wobble_y();
	}
}

void SwimmingSprite::speed(float speed) {
	this->m_speed = speed;
}

float SwimmingSprite::speed() {
	return m_speed;
}

void SwimmingSprite::wobble_y() {
	float y = m_y_sine_amplitude * sin(position_x() * M_PI / 180);
	move_relative_y(y);
}


