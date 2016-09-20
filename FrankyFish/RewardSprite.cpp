#include "stdafx.h"
#include "RewardSprite.h"
#include "MessageTypes.h"


RewardSprite::RewardSprite(const char* filename, Size& frame_size, uint32_t points)
	:GameSprite(filename, frame_size)
{
	m_points = points;
	this->type(SPRITE_TYPE_REWARD);
}

RewardSprite::~RewardSprite()
{
}

uint32_t RewardSprite::points() {
	return m_points;
}

void RewardSprite::points(uint32_t points) {
	m_points = points;
}

void RewardSprite::on_collision(Sprite* sprite) {
	if (sprite->type() == SPRITE_TYPE_PLAYER) {
		Message* msg = obtain_message();
		msg->set(MESSAGE_TYPE_REWARD_COLLECTED, this);
		send_message(msg);
	}
}