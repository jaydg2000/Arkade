#pragma once
#include <Sprite.h>
#include "Asteroids.h"

using namespace arkade;

class ExplosionSprite : public Sprite {
public:
	ExplosionSprite();
	~ExplosionSprite();

	virtual void on_update() override;
	virtual void on_pool_obtain() override;

private:
	bool			m_is_dead;
	void			send_dead_message();

};

