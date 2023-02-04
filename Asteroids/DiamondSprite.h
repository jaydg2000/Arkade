#pragma once
#include <Sprite.h>
#include "Asteroids.h"
#include "BoundsChecker.h"

using namespace arkade;

class DiamondSprite : public Sprite {
public:
	DiamondSprite(BoundsChecker* ptr_bounds_checker);

	virtual void on_update() override;
	virtual void on_collision(Sprite* ptr_colliding_sprite) override;
	void heading(float heading);

private:
	float m_heading;
	float m_speed;
	BoundsChecker* m_ptr_bounds_checker;
	void send_collected_message();
};

