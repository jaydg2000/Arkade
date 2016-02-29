#include "ExplosionSprite.h"
#include <ForwardOnceAnimator.h>

ExplosionSprite::ExplosionSprite()
	: Sprite("res/images/explosion_1.png", make_size(32,32))
{	
	m_is_dead = false;
	animator(new ForwardOnceAnimator(7, 50, false));
}


ExplosionSprite::~ExplosionSprite()
{
}


void ExplosionSprite::on_update() {
	if (!m_is_dead && animator()->is_done()) {
		send_dead_message();
		m_is_dead = true;
		is_visible(false);
	}
}

void ExplosionSprite::on_pool_obtain() {
	m_is_dead = false;
	animator()->reset();
	is_visible(true);
}

void ExplosionSprite::send_dead_message() {
	Message* message = obtain_message();
	message->set(MESSAGE_TYPE_EXPLOSION_DEAD, nullptr, this);
	send_message(message);
}

