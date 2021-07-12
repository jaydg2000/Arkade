#include "LittleHeartSprite.h"
#include <Random.h>
#include "MessageTypes.h"

LittleHeartSprite::LittleHeartSprite()
	: GameSprite("res/sprites/little_heart.png", make_size(25, 23))
{
	m_heading_to_move = Random::rand_float(0.0f, 359.0f);
}


LittleHeartSprite::~LittleHeartSprite()
{
}

void LittleHeartSprite::on_update() {
	move_at_heading(m_heading_to_move, 12.0f);
	//scale(scale() - .0025);
	if (m_life_timer.has_elapsed()) {
		Message* msg = obtain_message();
		msg->set(MESSAGE_TYPE_HEART_COMPLETED, this, nullptr);
		send_message(msg);
	}
}

void LittleHeartSprite::init(float x, float y, float heading) {
	position(x, y);
	m_heading_to_move = heading;
	m_life_timer.start(400);
}