#include "SpaceShipSprite.h"
#include <OscillatingAnimator.h>
#include <TextureCache.h>
#include <ArkadeTypes.h>

SpaceShipSprite::SpaceShipSprite()
	: PhysicsBasedSprite("res/images/PlayerSheet.png", arkade::make_size(66, 52))
{
	m_engine_on_animator = new OscillatingAnimator(3, 150);
	animator(m_engine_on_animator);
	m_frame_size.x = 66;
	m_frame_size.y = 52;
	m_engine_on_texture = texture();
}


SpaceShipSprite::~SpaceShipSprite()
{
}

void SpaceShipSprite::on_setup() {
	m_engine_off_texture = TextureCache::instance()->obtain("res/images/playersheet_nopower.png");
}

void SpaceShipSprite::on_update() {
	
	PhysicsBasedSprite::on_update();

	if (m_thrust_on) {
		texture(m_engine_on_texture);
		animator(m_engine_on_animator);
	}
	else {
		texture(m_engine_off_texture);
		animator(nullptr);
	}
}

void SpaceShipSprite::thrust(bool is_on) {
	m_thrust_on = is_on;
}