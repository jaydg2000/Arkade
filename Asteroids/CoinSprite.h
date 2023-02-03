#pragma once
#include <Sprite.h>
#include "Asteroids.h"

using namespace arkade;

class CoinSprite : public Sprite {
public:
	CoinSprite();

	virtual void on_update() override;
	virtual void on_collision(Sprite* ptr_colliding_sprite) override;

private:
	void send_collected_message();
};

