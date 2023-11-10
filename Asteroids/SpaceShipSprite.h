#pragma once
#include <Sprite.h>
#include <SpritePool.h>
#include "BoundsChecker.h"
#include <Sound.h>

using namespace arkade;

class LaserSprite;
class SpaceShipSprite : public Sprite {
public:
	SpaceShipSprite(uint32_t screen_width, uint32_t screen_height, BoundsChecker* bounds_checker, Sound* ptr_laser_sound/*, Sound* ptr_scream_sound, Sound* ptr_exploion_sound*/);
	~SpaceShipSprite();

	virtual void					on_setup();
	virtual void					on_update();
	virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);
	virtual void					on_collision(Sprite* ptr_colliding_sprite);
	void							thrust(bool is_on);
	LaserSprite*					fire();
	SpritePool*						laser_sprite_pool();

private:
	Texture*						m_engine_off_texture;
	Texture*						m_engine_on_texture;
	Animator*						m_engine_on_animator;
	SpritePool*						m_ptr_laser_pool;
	Timer							m_laser_fire_timer;
	Timer							m_death_timer;
	BoundsChecker*					m_bounds_checker;
	Sound*							m_laser_sound;
	Sound*							m_explosion_sound;
	Sound*							m_scream_sound;

	Size							m_frame_size;
	bool							m_thrust_on;
	int32_t							m_screen_center_x;
	int32_t							m_screen_center_y;

	void							apply_texture();
	void							check_bounds();
	void							reset_position();
	void							init_laser_pool();
	void							send_explosion_message();
};

