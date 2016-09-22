#include "FrankySprite.h"
#include <ForwardAnimator.h>
#include <MathUtil.h>
#include "FishGame.h"
#include "RewardSprite.h"

FrankySprite::FrankySprite():
	GameSprite("res/sprites/sprite_franky_swim_right.png", make_size(128, 128))
{
	this->type(SPRITE_TYPE_PLAYER);
	this->animator(new ForwardAnimator(6, 80));
	this->reset();
	this->m_rotation_increment = -(140.0f / (MAX_MOMENTUM - MIN_MOMENTUM));
}

FrankySprite::~FrankySprite() {
}

void FrankySprite::boost() {
	if (m_is_jumping || m_is_dead) {
		rest();
		return;
	}

	m_momentum = MAX_MOMENTUM; 
	//tilt_up();
	tilt();
}

void FrankySprite::rest() {
	if(m_is_jumping)
		m_momentum -= MOMENTUM_AIR_STEP_DN;
	else
		m_momentum -= MOMENTUM_STEP_DN;
	if(m_momentum < MIN_MOMENTUM)
		m_momentum = MIN_MOMENTUM;
	//if (position_y() >= MAX_Y_POSITION || m_momentum > (MIN_MOMENTUM / 2.0f))
	//	tilt_straight();
	//else
	//tilt_down();
	tilt();
}

void FrankySprite::tilt() {
	float r = m_momentum * m_rotation_increment;
	rotation(r);
}

//void FrankySprite::tilt_straight() {
//	float r = rotation();
//	if (r < 0)
//		tilt_down();
//	else if(r>0)
//		tilt_up();
//}
//
//void FrankySprite::tilt_up() {
//	float r = rotation();
//	r -= 1.5f;
//	if (r < 0)
//		r = 0;
//
//	rotation(r);
//}
//
//void FrankySprite::tilt_down() {
//	float r = rotation();
//	float rotation_max = m_is_jumping ? 75.0f : 25.0f;
//	float rotation_inc = m_is_jumping ? 3.0f : 1.5f;
//
//	r += rotation_inc;
//	if (r > rotation_max)
//		r = rotation_max;
//	rotation(r);
//}

void FrankySprite::jump() {
	if (m_is_jumping)
		return;

	m_is_jumping = true;
	rotation(-45);
	m_momentum = 14.0f;//MAX_MOMENTUM;
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
}

bool FrankySprite::can_restart() {
	return m_is_dead && position_y() == MAX_Y_POSITION;
}

void FrankySprite::on_collision(Sprite* sprite) {
	if (sprite->type() == SPRITE_TYPE_REWARD) {
		uint32_t points = ((RewardSprite*)sprite)->points();
		Message* message = obtain_message();
		message->set(MESSAGE_TYPE_SCORE, this, &points);
		send_message(message);
	}
	if (sprite->type() == SPRITE_TYPE_PREDATOR) {
		m_is_dead = true;
		m_momentum = MIN_MOMENTUM*2;
		rotation(90);
		Message* message = obtain_message();
		message->set(MESSAGE_TYPE_DEAD, this);
		send_message(message);
	}
}

Rect* FrankySprite::collision_rect() {
	Rect* ptr_rect = destination_rect();
	m_collision_rect.x = ptr_rect->x + 15;
	m_collision_rect.y = ptr_rect->y + 25;
	m_collision_rect.w = ptr_rect->w - 50;
	m_collision_rect.h = ptr_rect->h - 50;

	return &m_collision_rect;
}

void FrankySprite::reset() {
	m_is_dead = false;
	this->rotation(0);
	this->m_momentum = 0.0f;
	this->m_is_jumping = false;
	this->m_is_dead = false;
}