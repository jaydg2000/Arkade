#include "stdafx.h"
#include "PredatorSprite.h"


PredatorSprite::PredatorSprite(const char* filename, Size& frame_size)
	:Sprite(filename, frame_size)
{
	m_swim_timer.start(20);
	go_to_start_position();
}


PredatorSprite::~PredatorSprite()
{
}

void PredatorSprite::speed(float speed) {
	this->m_speed = speed;
}

float PredatorSprite::speed() {
	return m_speed;
}

void PredatorSprite::swim() {
	if (m_swim_timer.has_elapsed()) {
		this->move_relative_x(-m_speed);
		if (this->position_x() < -200.0f) {
			go_to_start_position();
		}
	}
}

void PredatorSprite::go_to_start_position() {
	this->position_x(Random::rand_int(FishGame::res_width + 200, FishGame::res_width+400));
	this->position_y(Random::rand_int(450, 1200));
}

