#include "DollarSprite.h"


DollarSprite::DollarSprite() 
: GameSprite("res/sprites/dollar.png", make_size(22,38)) {

	m_heading_to_move = Random::rand_float(0.0f, 359.0f);
}


DollarSprite::~DollarSprite() {
}

void DollarSprite::on_update() {
	move_at_heading(m_heading_to_move, 10.0f);
	//scale(scale() - .0025);
	if (m_life_timer.has_elapsed()) {
		Message* msg = obtain_message();
		msg->set(MESSAGE_TYPE_DOLLAR_COMPLETED, this, nullptr);
		send_message(msg);
	}
}

void DollarSprite::init(float x, float y, float heading) {
	position(x, y);
	m_heading_to_move = heading;
	m_life_timer.start(500);
}