#include "stdafx.h"
#include "SwimmingSprite.h"
#include <Camera.h>

SwimmingSprite::SwimmingSprite(const char* filename, Size& frame_size)
	: GameSprite(filename, frame_size)
{
	m_speed = Random::rand_float(1.0f, 1.25f);
	m_y_sine_amplitude = Random::rand_float(0.55f, 1.55f);
	m_x_sine = Random::rand_float(.05f, 50.0f);
	m_swim_timer.start(20);
}


SwimmingSprite::~SwimmingSprite()
{
}

void SwimmingSprite::on_update() {
	if (m_swim_timer.has_elapsed()) {
		//this->move_relative_x(-m_speed);
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
	//float x = Camera::instance()->position_x();
	float y = m_y_sine_amplitude * sin(m_x_sine * M_PI / 180);
	m_x_sine += m_speed;
	move_relative_y(y);
}


