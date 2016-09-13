#include "FrankySprite.h"
#include <ForwardAnimator.h>
#include <MathUtil.h>
#include "FishGame.h"

FrankySprite::FrankySprite():
	Sprite("res/sprites/sprite_freddy_swim_right.png", make_size(126, 86))
{
	this->animator(new ForwardAnimator(6, 150));
	this->m_momentum = 0.0f;
	this->m_is_jumping = false;
}

FrankySprite::~FrankySprite() {}

void FrankySprite::swim() {
	if (m_is_jumping) {
		idle();
		return;
	}

	m_momentum += MOMENTUM_STEP_UP;
	if(m_momentum > MAX_MOMENTUM)
		m_momentum = MAX_MOMENTUM;
	tilt_up();
}

void FrankySprite::idle() {
	if(m_is_jumping)
		m_momentum -= MOMENTUM_AIR_STEP_DN;
	else
		m_momentum -= MOMENTUM_STEP_DN;
	if(m_momentum < MIN_MOMENTUM)
		m_momentum = MIN_MOMENTUM;
	if (position_y() >= MAX_Y_POSITION || m_momentum > (MIN_MOMENTUM / 2.0f))
		tilt_straight();
	else
		tilt_down();
}

void FrankySprite::tilt_straight() {
	float r = rotation();
	if (r < 0)
		tilt_down();
	else if(r>0)
		tilt_up();
}

void FrankySprite::tilt_up() {
	float r = rotation();
	r -= 5;
	if (r < -45)
		r = -45;
	rotation(r);
}

void FrankySprite::tilt_down() {
	float r = rotation();
	r+=2;
	if (r > 45)
		r = 45;
	rotation(r);
}

void FrankySprite::jump() {
	m_is_jumping = true;
	rotation(-45);
	m_momentum = MAX_MOMENTUM;
}

void FrankySprite::on_update() {
	move_relative_y(-m_momentum);
	if(position_y() > MAX_Y_POSITION)
		position_y(MAX_Y_POSITION);
	if (m_is_jumping) {
		if (position_y() > MIN_Y_JUMP_POSITION) {
			m_is_jumping = false;
		}
	}
	else if (position_y() < MIN_Y_POSITION-10) {
		jump();
	}
}
