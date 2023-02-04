#include "DiamondSprite.h"
#include <ForwardAnimator.h>
#include <Random.h>

DiamondSprite::DiamondSprite(BoundsChecker* ptr_bounds_checker):Sprite() {
	animator(new ForwardAnimator(2, 100));
	type(SPRITE_TYPE_COIN);
	scale(.15, .15);
	if (Random::rand_bool()) 
		texture("res/images/white_diamond.png", RGB::Magenta); 
	else
		texture("res/images/blue_diamond.png", RGB::Magenta);
	size(Point(256, 208));
	m_ptr_bounds_checker = ptr_bounds_checker;
	m_speed = Random::rand_int(1, 3);
}

void DiamondSprite::on_update() {
	move_at_heading(m_heading, m_speed);
	float x = position_x();
	float y = position_y();
	if (m_ptr_bounds_checker->is_out_of_bounds(x, y))
		send_collected_message();
}

void DiamondSprite::on_collision(Sprite* ptr_colliding_sprite) {
	if (ptr_colliding_sprite->type() == SPRITE_TYPE_PLAYER) {
		send_collected_message();
	}
}

void DiamondSprite::send_collected_message() {
	Message* message = obtain_message();
	message->set(MESSAGE_TYPE_DIAMOND_COLLECTED, nullptr, this);
	send_message(message);
}

void DiamondSprite::heading(float heading) {
	m_heading = heading;
}


