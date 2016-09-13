#pragma once
#include <ArkadeTypes.h>
#include <Scene.h>
#include <Mouse.h>
#include <SpritePool.h>
#include "FrankySprite.h"
#include "SharkSprite.h"
#include "FishGame.h"

using namespace arkade;

class SceneFrankysFirstSwim :
	public Scene
{
public:
	SceneFrankysFirstSwim();
	~SceneFrankysFirstSwim();

protected:
	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_keyboard_input(Keyboard* keyboard);
	virtual void					on_mouse_button(uint32_t button_event_type);
	virtual void					on_update();
	virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_end();
	virtual void					on_cleanup();
	virtual void					on_detect_collisions();
	virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
	FrankySprite*					m_ptr_franky;
	Image*							m_ptr_sky;

	RGB								m_water_color_rgb;

	int32_t							m_franky_start_x;
	int32_t							m_franky_start_y;

	SpritePool*						m_spritepool_predators;
};

