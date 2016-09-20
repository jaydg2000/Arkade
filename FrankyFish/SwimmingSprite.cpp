#include "stdafx.h"
#include "SwimmingSprite.h"


SwimmingSprite::SwimmingSprite(const char* filename, Size& frame_size)
	: Sprite(filename, frame_size)
{
	this->m_speed = 10.0f;
	m_swim_timer.start(20);
}


SwimmingSprite::~SwimmingSprite()
{
}

void SwimmingSprite::swim() {
	if (m_swim_timer.has_elapsed()) {
		this->move_relative_x(-m_speed);
	}
}

void SwimmingSprite::speed(float speed) {
	this->m_speed = speed;
}

float SwimmingSprite::speed() {
	return m_speed;
}


