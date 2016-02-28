#pragma once
#include <PhysicsBasedSprite.h>

using namespace arkade;

class SpaceShipSprite : public PhysicsBasedSprite {
public:
	SpaceShipSprite();
	~SpaceShipSprite();

	virtual void					on_setup();
	virtual void					on_update();
	void							thrust(bool is_on);

private:
	Texture*						m_engine_off_texture;
	Texture*						m_engine_on_texture;
	Animator*						m_engine_on_animator;
	Size							m_frame_size;
	bool							m_thrust_on;
};

