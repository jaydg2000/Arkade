#include "CoinSprite.h"
#include <ForwardAnimator.h>

CoinSprite::CoinSprite() 
	: Sprite("res/images/coin.png", make_size(66,65)) {
	animator(new ForwardAnimator(6, 100));
	type(SPRITE_TYPE_COIN);
	scale(.30, .30);
}

void CoinSprite::on_update() {
}

void CoinSprite::on_collision(Sprite* ptr_colliding_sprite) {
	if (ptr_colliding_sprite->type() == SPRITE_TYPE_PLAYER) {
		send_collected_message();
	}
}

void CoinSprite::send_collected_message() {
	Message* message = obtain_message();
	message->set(MESSAGE_TYPE_COIN_COLLECTED, nullptr, this);
	send_message(message);
}

