#include "FrankySprite.h"
#include <ForwardAnimator.h>
#include <MathUtil.h>
#include "FishGame.h"
#include "RewardSprite.h"

FrankySprite::FrankySprite():
	GameSprite("res/sprites/sprite_franky_swim_right.png", make_size(128, 128))
{
	this->m_is_immortal = false;
	this->type(SPRITE_TYPE_PLAYER);
	this->animator(new ForwardAnimator(6, 80));
	this->reset();
	this->m_rotation_increment = -(140.0f / (MAX_MOMENTUM - MIN_MOMENTUM));
	this->collision_dim(30, 45, 70, 45);
	m_swoosh_timer.start(1500);
	m_ptr_sound_swoosh = new Sound("res/wav/swim.wav");	
}

FrankySprite::~FrankySprite() {
}

void FrankySprite::boost() {
	if (m_is_dead) {
		rest();
		return;
	}

	if (m_swoosh_timer.has_elapsed() && is_sound_enabled()) {
		m_ptr_sound_swoosh->play_sound();
	}
	else {
		m_swoosh_timer.start();
	}

	m_momentum = MAX_MOMENTUM; 
	tilt();
}

void FrankySprite::rest() {
	m_momentum -= MOMENTUM_STEP_DN;
	if(m_momentum < MIN_MOMENTUM)
		m_momentum = MIN_MOMENTUM;

	tilt();
}

void FrankySprite::tilt() {
	float r = m_momentum * m_rotation_increment;
	rotation(r);
}

void FrankySprite::on_update() {
	move_relative_y(-m_momentum);
	if(position_y() > MAX_Y_POSITION)
		position_y(MAX_Y_POSITION);
}

bool FrankySprite::can_restart() {
	return m_is_dead && position_y() >= MAX_Y_POSITION;
}

void FrankySprite::on_collision(Sprite* sprite) {

	if (m_is_dead)
		return;

	if (sprite->type() == SPRITE_TYPE_REWARD) {
		uint32_t points = ((RewardSprite*)sprite)->points();
		Message* message = obtain_message();
		message->set(MESSAGE_TYPE_SCORE, this, &points);
		send_message(message);
	}

	if (sprite->type() == SPRITE_TYPE_EXTRA) {
		Message* message = obtain_message();
		message->set(MESSAGE_TYPE_EXTRA_LIFE, this, sprite);
		send_message(message);
	}

	if (sprite->type() == SPRITE_TYPE_PREDATOR) {		
		if (!m_is_immortal) {
			die();
			Message* message = obtain_message();
			message->set(MESSAGE_TYPE_DEAD, this);
			send_message(message);
		}
	}
}

void FrankySprite::die() {
	m_is_dead = true;
	m_momentum = MIN_MOMENTUM * 2;
	rotation(90);
}

void FrankySprite::reset() {
	this->rotation(0);
	this->m_momentum = 0.0f;
	this->m_is_dead = false;
}

bool FrankySprite::immortal() {
	return m_is_immortal;
}

void FrankySprite::immortal(bool enable) {
	m_is_immortal = enable;
}
