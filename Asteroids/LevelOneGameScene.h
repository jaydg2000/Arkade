#pragma once
#include <Scene.h>
#include <BoundingBoxCollisionDetector.h>
#include "SpaceShipSprite.h"
#include "AsteroidSprite.h"
#include "LaserSprite.h"
#include "ExplosionSprite.h"
#include "DiamondSprite.h"
#include "BoundsChecker.h"
#include "Font.h"

using namespace arkade;

class LevelOneGameScene : public Scene {
public:
	LevelOneGameScene();
	~LevelOneGameScene();

	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_input(InputManager* ptr_keyboard);
	virtual void					on_mouse_input();
	virtual void					on_update();
	virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_end();
	virtual void					on_cleanup();
	virtual void					on_detect_collisions();
	virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
	Image*							m_ptr_background;
	SpaceShipSprite*				m_ptr_spaceship;
	SpritePool*						m_ptr_asteroid_pool;
	SpritePool*						m_ptr_explosion_pool;
	SpritePool*						m_ptr_diamond_pool;
	Timer							m_asteroid_creation_timer;
	BoundsChecker*					m_bounds_checker;
	BoundingBoxCollisionDetector	m_collision_detector;
	Sound*							m_ptr_asteroid_explosion_sound;
	Sound*							m_ptr_spaceship_explosion_sound;
	Sound*							m_ptr_laser_sound;
	Sound*							m_ptr_scream_sound;
	Font*							m_ptr_font;
	uint32_t						m_delay_between_asteroid_creation;
	int								m_lives_left;
	void							init_asteroid_pool();
	void							init_explosion_pool();
	void							init_diamond_pool();
	void							add_asteroid();
	void							add_laser();
	void							add_explosion(PointF* position);
	void							add_diamond();
};

