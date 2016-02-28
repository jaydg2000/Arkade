#pragma once
#include <Scene.h>
#include "SpaceShipSprite.h"
#include "AsteroidSprite.h"
#include "LaserSprite.h"

using namespace arkade;

class LevelOneGameScene : public Scene {
public:
	LevelOneGameScene();
	~LevelOneGameScene();

	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_keyboard_input(Keyboard* ptr_keyboard);
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
	SpritePool*						m_ptr_laser_pool;
	Timer							m_asteroid_creation_timer;

	void							init_asteroid_pool();
	void							init_laser_pool();
	void							add_asteroid();
};

